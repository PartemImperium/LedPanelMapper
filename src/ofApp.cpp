#include "ofApp.h"

void ofApp::setup() {
	ofSetEscapeQuitsApp(false);
	ofDisableArbTex();

    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
	setupConfig();

    setupInfoUi();
    panelCalculator.setup(&c);

    input.setup(&c);

    output.setup(&c);
}

void ofApp::setupConfig() {
	ofxJSONElement config;
	config.open("config.json");
	c.setup(config);
}

void ofApp::setupInfoUi() {
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
    reloadEvent.add(&panelCalculator, &PanelCalculator::calculate,200);
    gui.loadPressedE = reloadEvent;
    
    ofParameterGroup fullGroup;
    
    fullGroup.add(c);
    
    ofParameter<void> savePanelLayoutButton;
    savePanelLayoutButton.addListener(&panelCalculator, &PanelCalculator::savePanelLayoutImage);
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
	for (int i = 0; i < panelCalculator.panels.size(); i++) {
        panelCalculator.panels[i].draw(input.frameBuffer.getTexture());
	}
	output.frameBuffer.end();
}

void ofApp::drawInfoUi() {
    ofNoFill();

	std::string fps = "FPS: " + std::to_string(ofGetFrameRate());
	ofDrawBitmapString(fps, 1300, 170);

    input.frameBuffer.draw(infoUiInputRect);
    panelCalculator.draw(infoUiInputRect);
    
	ofDrawRectangle(infoUiInputRect);

	ofDrawBitmapString("Input Framebuffer: " + input.getInputNames(), 1300, 185);

	output.frameBuffer.draw(infoUiOutputRect);
	ofDrawRectangle(infoUiOutputRect);
	ofDrawBitmapString("Output Framebuffer: " + output.getOutputNames(), 1300, 595);
    
    ofDrawBitmapString("Canculated Panel Info:",1300,20);
    
    ofDrawBitmapString("Panel Source Width: " + std::to_string(panelCalculator.panelWidth),1300,50);
    ofDrawBitmapString("Panel Source Height: " + std::to_string(panelCalculator.panelHeight),1300,65);
    
    gui.draw();

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

void ofApp::exit() { }
