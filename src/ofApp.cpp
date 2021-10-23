#include "ofApp.h"

void ofApp::setup() {
	ofSetEscapeQuitsApp(false);
	ofDisableArbTex();

    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
	setupConfig();

    setupInfoUi(c);
    setupPanelCalculations();

    input.setup(&c);

    output.setup(&c);
}

void ofApp::setupConfig() {
	ofxJSONElement config;
	config.open("config.json");
	c.setup(config);
}

void ofApp::setupPanelCalculations() {
    int sourceWidth = 1920;
    int sourceHeight = 1080;//TODO: Make this a config (and use the value for input frame buffer allocation.
    
    std::vector<PanelCalculations> tempPanels;
    for (int i = 0; i < c.PanelInfo.Panels.size(); i++) {
        PanelCalculations tempCalc;
        
        calculatedPanelWidth = sourceWidth / c.PanelInfo.PanelsToFillWidth;
        calculatedPanelHeight = sourceHeight / c.PanelInfo.PanelsToFillHeight;
        
        tempCalc.destinationX = (i * c.PanelInfo.PanelWidth);
        tempCalc.destinationY = 0;
        tempCalc.destinationWidth = c.PanelInfo.PanelWidth;
        tempCalc.destinationHeight = c.PanelInfo.PanelHeight;
        
        tempCalc.sourceX = c.PanelInfo.Panels[i].X;
        tempCalc.sourceY = c.PanelInfo.Panels[i].Y;
        tempCalc.sourceWidth = calculatedPanelWidth;
        tempCalc.sourceHeight = calculatedPanelHeight;
        
        tempPanels.push_back(tempCalc);
    }
    panels = tempPanels;

    ofNoFill();
    infoUiInputFrameBuffer.begin();

    ofClear(0, 0, 0);
    for (int i = 0; i < panels.size(); i++) {
        ofDrawRectangle(panels[i].getSource());
    }
    
    infoUiInputFrameBuffer.end();
    ofFill();

}


void ofApp::setupInfoUi(Config config) {
    infoUiInputFrameBuffer.allocate(1920, 1080);

	ofRectangle tempRect(0, 0, 480, 270);

	infoUiInputRect = ofRectangle(tempRect);
	infoUiInputRect.setPosition(1300, 200);

	infoUiOutputRect = ofRectangle(tempRect);
	infoUiOutputRect.setPosition(1300, 610);
    
    ofSetLineWidth(4);

    ofEvent<void> saveEvent;
    saveEvent.add(&c,  &Config::save, 200);
    gui.savePressedE = saveEvent;
    
    ofEvent<void> reloadEvent;
    reloadEvent.add(this, &ofApp::setupPanelCalculations,200);
    gui.loadPressedE = reloadEvent;
    
    ofParameterGroup fullGroup;
    
    fullGroup.add(c);
    
    ofParameter<void> savePanelLayoutButton;
    savePanelLayoutButton.addListener(this, &ofApp::savePanelLayoutImage);
    savePanelLayoutButton.set("Save Panel Layout Image");
    gui.add(savePanelLayoutButton);
    fullGroup.add(savePanelLayoutButton);
    
    gui.setDefaultWidth(400);
    
    gui.setup(fullGroup, "remove_me");
    // I dont want it to make a settings.xml file as I want control of the config and its schema however for some reason I dont understand giving it "remove_me" as a file name prevents it from saving the setting file.... I was gonna use the exit event but this works too ¯\_(ツ)_/¯
}

void ofApp::update()
{
    input.update();
}

void ofApp::draw() {
    input.draw();
    
	// Draw Input Framebuffer into Output Framebuffer (with panels scalled and put into top left corner).
    drawPanelsToOutputFrameBuffer();

    output.draw();


	//Draw Info UI to main window.
	drawInfoUi();
}

void ofApp::drawPanelsToOutputFrameBuffer() {
	output.frameBuffer.begin();
	for (int i = 0; i < panels.size(); i++) {
        panels[i].draw(input.frameBuffer.getTexture());
	}
	output.frameBuffer.end();
}

void ofApp::drawInfoUi() {
    ofNoFill();

	std::string fps = "FPS: " + std::to_string(ofGetFrameRate());
	ofDrawBitmapString(fps, 1300, 170);

    input.frameBuffer.draw(infoUiInputRect);
    infoUiInputFrameBuffer.draw(infoUiInputRect);
    
	ofDrawRectangle(infoUiInputRect);

	ofDrawBitmapString("Input Framebuffer: " + input.getInputNames(), 1300, 185);

	output.frameBuffer.draw(infoUiOutputRect);
	ofDrawRectangle(infoUiOutputRect);
	ofDrawBitmapString("Output Framebuffer: " + output.getOutputNames(), 1300, 595);
    
    ofDrawBitmapString("Canculated Panel Info:",1300,20);
    
    ofDrawBitmapString("Panel Source Width: " + std::to_string(calculatedPanelWidth),1300,50);
    ofDrawBitmapString("Panel Source Height: " + std::to_string(calculatedPanelHeight),1300,65);
    
    gui.draw();

    ofFill();
}

void ofApp::savePanelLayoutImage() {
    ofPixels pix;
    pix.allocate(1920, 1080, OF_IMAGE_QUALITY_BEST);
    infoUiInputFrameBuffer.readToPixels(pix);
    ofSaveImage(pix, ofFilePath::join(c.PanelLayoutImagePath.get(), "panel-layout.png"));
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

void ofApp::exit() { }
