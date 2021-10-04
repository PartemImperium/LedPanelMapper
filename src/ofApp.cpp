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

void ofApp::setupPanelCalculations() {
    int sourceWidth = 1920;
    int sourceHeight = 1080;//TODO: Make this a config (and use the value for input frame buffer allocation.
    
    
    for (int i = 0; i < c.PanelInfo.Panels.size(); i++) {
        
        PanelCalculations tempCalc;
		
        tempCalc.destinationX = (i * c.PanelInfo.PanelWidth) + 1;// TODO: Check if the 1 px add here is needed. I dont think it is.;
        tempCalc.destinationY = 0;
        tempCalc.destinationWidth = c.PanelInfo.PanelWidth;
        tempCalc.destinationHeight = c.PanelInfo.PanelHeight;
        
        tempCalc.sourceX = c.PanelInfo.Panels[i].X;
        tempCalc.sourceY = c.PanelInfo.Panels[i].Y;
        tempCalc.sourceWidth = sourceWidth / c.PanelInfo.PanelsToFillWidth;
        tempCalc.sourceHeight = sourceHeight / c.PanelInfo.PanelsToFillHeight;
        
        panels.push_back(tempCalc);
    }
}


void ofApp::setupInput() {
    if (c.Inputs.StaticImage.IsInputEnabled) {
        inputs.push_back(std::move(std::make_unique<StaticImageInput>()));
    }
    if (c.Inputs.VideoPlayer.IsInputEnabled) {
        inputs.push_back(std::move(std::make_unique< VideoPlayerInput>()));
	}
#if __APPLE__
	if (c.Inputs.Syphon.IsInputEnabled) {
        inputs.push_back(std::move(std::make_unique<SyphonInput>()));
	}
#endif
	if (c.Inputs.Ndi.IsInputEnabled) {
        inputs.push_back(std::move(std::make_unique<NdiInput>()));
	}
    if (c.Inputs.DeckLink.IsInputEnabled) {
        inputs.push_back(std::move(std::make_unique<DeckLinkInput>()));
	}

    for (auto& i : inputs) {
        i->setup(c);
    }
    std::sort(inputs.begin(), inputs.end(),[] (const std::unique_ptr<BaseInput>& left, const std::unique_ptr<BaseInput>& right) {
        return left->DrawIndex < right->DrawIndex;
    });
    for (auto& i : inputs) {// Do this here instead of by the setup so that they are in draw order.
        inputNames += i->InputName() + " ";
    }
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
    for (auto& i : inputs) {
        i->update();
    }
}

void ofApp::draw() {
	// Draw Input to Input Framebuffer.
	inputFrameBuffer.begin();

    for (auto& i : inputs) {
        i->draw();
    }

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

	ofDrawBitmapString("Input Framebuffer: " + inputNames, 1300, 185);

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
