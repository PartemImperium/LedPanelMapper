#include "ofApp.h"

void ofApp::setup() {
	ofSetEscapeQuitsApp(false);
	ofDisableArbTex();

    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
	setupConfig();

    setupPanelCalculations();
    setupInfoUi(c);

	// Setup Inputs
	inputFrameBuffer.allocate(1920, 1080);
	setupInput();

	// Setup Outputs
	outputFrameBuffer.allocate(1920, 1080);
	setupOutputs();
}

void ofApp::setupConfig() {
	ofxJSONElement config;
	config.open("config.json");
	c.setup(config);
}
const float appY = 0;

const float appW = 64;
const float appH = 128;

const float syphonW = 281.6;
const float syphonH = 540;

void ofApp::setupPanelCalculations() {
    for (int i = 0; i < c.Panels.size(); i++) {
        float appX = (i * appW) + 1;
        float syphonX = c.Panels[i].X;
        float syphonY = c.Panels[i].Y;
        
        PanelCalculations tempCalc;
        tempCalc.destinationX =appX;
        tempCalc.destinationY = appY;
        tempCalc.destinationWidth = appW;
        tempCalc.destinationHeight = appH;
        
        tempCalc.sourceX = syphonX;
        tempCalc.sourceY = syphonY;
        tempCalc.sourceWidth = syphonW;
        tempCalc.sourceHeight = syphonH;
        panels.push_back(tempCalc);
    }
}


void ofApp::setupInput() {
	if (c.Inputs.VideoPlayer.IsInputEnabled) {
		input = new VideoPlayerInput();
	}
    else if (c.Inputs.StaticImage.IsInputEnabled) {
        input = new StaticImageInput();
    }
#if __APPLE__
	else if (c.Inputs.Syphon.IsInputEnabled) {
		input = new SyphonInput();
	}
#endif
	else if (c.Inputs.Ndi.IsInputEnabled) {
		input = new NdiInput();
	}
    else if (c.Inputs.DeckLink.IsInputEnabled) {
		input = new DeckLinkInput();
	}

	input->setup(c);
}

void ofApp::setupOutputs() {
	if (c.Outputs.Ndi.IsOutputEnabled) {
		outputs.push_back(std::move(std::make_unique<NdiOutput>()));
	}
#if __APPLE__
	if (c.Outputs.Syphon.IsOutputEnabled) {
		outputs.push_back(std::move(std::make_unique<SyphonOutput>()));
	}
#endif
    if (c.Outputs.DeckLink.IsOutputEnabled) {
        outputs.push_back(std::move(std::make_unique<DeckLinkOutput>()));
    }

	for (auto& o : outputs) {
		o->setup(c);
		outputNames += o->OutputName() + " ";
	}
}

void ofApp::setupInfoUi(Config config) {
    infoUiInputFrameBuffer.allocate(1920, 1080);

	ofRectangle tempRect(0, 0, 480, 270);

	infoUiInputRect = ofRectangle(tempRect);
	infoUiInputRect.setPosition(1300, 200);

	infoUiOutputRect = ofRectangle(tempRect);
	infoUiOutputRect.setPosition(1300, 610);
    
    ofSetLineWidth(4);
}

void ofApp::update()
{
	input->update();
}

void ofApp::draw() {
	// Draw Input to Input Framebuffer.
	inputFrameBuffer.begin();

	input->draw();

	inputFrameBuffer.end();

	// Draw Input Framebuffer into Output Framebuffer (with panels scalled and put into top left corner).
    drawPanelsToOutputFrameBuffer();

	// Draw Output Framebuffer to all outputs (Multiple outputs can be turned on at the same time).
	for (auto& o : outputs)
	{
		o->draw(outputFrameBuffer);
	}

	//Draw Info UI to main window.
	drawInfoUi();
}

void ofApp::drawPanelsToOutputFrameBuffer() {
	outputFrameBuffer.begin();
	for (int i = 0; i < panels.size(); i++) {
		
        panels[i].draw(inputFrameBuffer.getTexture());
	}
	outputFrameBuffer.end();
}

void ofApp::drawInfoUi() {
	ofNoFill();

    infoUiInputFrameBuffer.begin();
    
    inputFrameBuffer.draw(0,0);
    for (int i = 0; i < panels.size(); i++) {
        ofDrawRectangle(panels[i].getSource());
    }
    
    infoUiInputFrameBuffer.end();
    
    
	std::string fps = "FPS: " + std::to_string(ofGetFrameRate());
	ofDrawBitmapString(fps, 1300, 170);

    infoUiInputFrameBuffer.draw(infoUiInputRect);
	ofDrawRectangle(infoUiInputRect);

	ofDrawBitmapString("Input Framebuffer: " + input->InputName(), 1300, 185);

	outputFrameBuffer.draw(infoUiOutputRect);
	ofDrawRectangle(infoUiOutputRect);
	ofDrawBitmapString("Output Framebuffer: " + outputNames, 1300, 595);

	ofFill();
}

void ofApp::keyPressed(int key) { }

void ofApp::keyReleased(int key) { }

void ofApp::mouseMoved(int x, int y) { }

void ofApp::mouseDragged(int x, int y, int button) { }

void ofApp::mousePressed(int x, int y, int button) { }

void ofApp::mouseReleased(int x, int y, int button) { }

void ofApp::mouseEntered(int x, int y) { }

void ofApp::mouseExited(int x, int y) { }

void ofApp::windowResized(int w, int h) { }

void ofApp::gotMessage(ofMessage msg) { }

void ofApp::dragEvent(ofDragInfo dragInfo) { }
