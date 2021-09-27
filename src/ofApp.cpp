#include "ofApp.h"

void ofApp::setup() {
    ofSetEscapeQuitsApp(false);
    ofDisableArbTex();

    setupConfig();
    setupInfoUi(c);

    // Setup Inputs
    input.allocate(1920, 1080);
    
    setupSyphonClient(c);
    
    // Setup Outputs
    output.allocate(1920, 1080);
    
    setupSyphonServer(c);
}

void ofApp::setupConfig() {
    ofxJSONElement config;
    config.open("config.json");
    c.setup(config);
}

void ofApp::setupInfoUi(Config config) {
    ofRectangle tempRect(0,0,480,270);
    
    infoUiInputRect = ofRectangle(tempRect);
    infoUiInputRect.setPosition(1300,200);
    
    infoUiOutputRect = ofRectangle(tempRect);
    infoUiOutputRect.setPosition(1300,610);
    
    ofNoFill();
    ofSetLineWidth(2);
}

void ofApp::setupSyphonServer(Config config) {
    syphonServer.setName("PanelMapper");
}

void ofApp::setupSyphonClient(Config config) {
    syphonClient.setup();
    syphonClient.set(config.SyphonServer,config.SyphonApplication);
}

void ofApp::update() { }

const float appY = 0;

const float appW = 64;
const float appH = 128;

const float syphonW = 281.6;
const float syphonH = 540;

void ofApp::draw() {
    drawSyphonToInputFrameBuffer();
    
    drawPanelsToOutputFrameBuffer();
    
    syphonServer.publishTexture(&output.getTexture());
    
    drawInfoUi();
}

void ofApp::drawSyphonToInputFrameBuffer() {
    input.begin();
        syphonClient.draw(0,0);
    input.end();
}

void ofApp::drawPanelsToOutputFrameBuffer() {
    output.begin();
        for (int i = 0; i < c.Panels.size(); i++) {
            float appX = (i * appW) + 1;
            float syphonX = c.Panels[i].X;
            float syphonY = c.Panels[i].Y;
            
            input.getTexture().drawSubsection(appX,appY,appW,appH,syphonX,syphonY,syphonW,syphonH);
        }
    output.end();
}

void ofApp::drawInfoUi() {
    input.draw(infoUiInputRect);
    ofDrawRectangle(infoUiInputRect);

    output.draw(infoUiOutputRect);
    ofDrawRectangle(infoUiOutputRect);
}

void ofApp::keyPressed(int key) { }

void ofApp::keyReleased(int key) { }

void ofApp::mouseMoved(int x, int y ) { }

void ofApp::mouseDragged(int x, int y, int button) { }

void ofApp::mousePressed(int x, int y, int button) { }

void ofApp::mouseReleased(int x, int y, int button) { }

void ofApp::mouseEntered(int x, int y) { }

void ofApp::mouseExited(int x, int y) { }

void ofApp::windowResized(int w, int h) { }

void ofApp::gotMessage(ofMessage msg) { }

void ofApp::dragEvent(ofDragInfo dragInfo) { }
