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
	ofRectangle tempRect(0, 0, 720, 405);

	infoUiInputRect = ofRectangle(tempRect);
	infoUiInputRect.setPosition(1150, 25);

	infoUiOutputRect = ofRectangle(tempRect);
	infoUiOutputRect.setPosition(1150, 650);
    
    ofSetLineWidth(4);

    auto mainContainer = gui.addContainer(c);
    
    ofParameter<void> reloadEvent;
    reloadEvent.addListener(&panelCalculator, &PanelCalculator::calculate);
    reloadEvent.set("Refreash Calculations");
    
    ofParameter<void> saveEvent;
    saveEvent.addListener(&c,  &Config::save);
    saveEvent.set("Save Config");
    
    buttonConfigJson = ofJson({{"type", "fullsize"}, {"text-align", "center"}, {"padding", "20"}});

    mainContainer->add(panelCalculator.savePanelLayoutE, buttonConfigJson);
    mainContainer->add(reloadEvent, buttonConfigJson);
    mainContainer->add(saveEvent, buttonConfigJson);

    auto panel = gui.addGroup("Info", ofJson({{"width", 720}}));
    panel->setPosition(1150, 450);
        
    panel->add<ofxGuiFloatLabel>(panelCalculator.panelWidth);
    panel->add<ofxGuiFloatLabel>(panelCalculator.panelHeight);

    panel->addFpsPlotter();
    
    panel->add<ofxGuiLabel>(input.names);
    panel->add<ofxGuiLabel>(output.names);
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

    input.frameBuffer.draw(infoUiInputRect);
    panelCalculator.draw(infoUiInputRect);
    
	ofDrawRectangle(infoUiInputRect);

	output.frameBuffer.draw(infoUiOutputRect);
	ofDrawRectangle(infoUiOutputRect);

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
