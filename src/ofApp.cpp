#include "ofApp.h"

void ofApp::setup() {
    ofSetEscapeQuitsApp(false);
    ofDisableArbTex();

    setupConfig();
    setupInfoUi(c);

    // Setup Inputs
    inputFrameBuffer.allocate(1920, 1080);
    
    setupInput();
        
    // Setup Outputs
    output.allocate(1920, 1080);
    
    setupSyphonServer(c);
    setupNdiSender(c);
}

void ofApp::setupConfig() {
    ofxJSONElement config;
    config.open("config.json");
    c.setup(config);
}

void ofApp::setupInput() {
    if (c.Inputs.VideoPlayer.IsInputEnabled){
        input = new VideoPlayerInput();
    }
    else if (c.Inputs.Syphon.IsInputEnabled){
        input = new SyphonInput();
    }
    else if (c.Inputs.Ndi.IsInputEnabled) {
        input = new NdiInput();
    }
    
    input->setup(c);
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
    if (config.Outputs.Syphon.IsOutputEnabled) {
        syphonServer.setName(config.Outputs.Syphon.Name);
        outputNames+="Syphon Server ";
    }
}

void ofApp::setupNdiSender(Config config){
    if (c.Outputs.Ndi.IsOutputEnabled){
        if(ndiSender.setup(c.Outputs.Ndi.Name)) {
            ndiSendVideo.setup(ndiSender);
            ndiSendVideo.setAsync(true);
        }
        outputNames+="NDI Sender ";
    }
}

void ofApp::update()
{
    input->update();
}

const float appY = 0;

const float appW = 64;
const float appH = 128;

const float syphonW = 281.6;
const float syphonH = 540;

void ofApp::draw() {
    // Draw Input to Input Framebuffer (we call each possible input but only one can be on at once).
    inputFrameBuffer.begin();

    input->draw();

    inputFrameBuffer.end();
    
    // Draw Input Framebuffer into Output Framebuffer (with panels scalled and put into top left corner).
    drawPanelsToOutputFrameBuffer();
    
    // Draw Output Framebuffer to all outputs (Multiple outputs can be turned on at the same time).
    drawOutputFramebuffertoSyphon();
    drawOutputFramebufferToNdi();
    
    //Draw Info UI to main window.
    drawInfoUi();
}

void ofApp::drawPanelsToOutputFrameBuffer() {
    output.begin();
        for (int i = 0; i < c.Panels.size(); i++) {
            float appX = (i * appW) + 1;
            float syphonX = c.Panels[i].X;
            float syphonY = c.Panels[i].Y;
            
            inputFrameBuffer.getTexture().drawSubsection(appX,appY,appW,appH,syphonX,syphonY,syphonW,syphonH);
        }
    output.end();
}

void ofApp::drawOutputFramebuffertoSyphon() {
    if (c.Outputs.Syphon.IsOutputEnabled){
        syphonServer.publishTexture(&output.getTexture());
    }
}

void ofApp::drawOutputFramebufferToNdi(){
    if (c.Outputs.Ndi.IsOutputEnabled){
        ofPixels tempPixels;
        output.readToPixels(tempPixels);
        ndiSendVideo.send(tempPixels);
    }
}

void ofApp::drawInfoUi() {
    std::string fps = "FPS: " + std::to_string(ofGetFrameRate());
    ofDrawBitmapString(fps,1300,170);
    
    inputFrameBuffer.draw(infoUiInputRect);
    ofDrawRectangle(infoUiInputRect);
    
    ofDrawBitmapString("Input Framebuffer: " + input->InputName,1300,185);

    output.draw(infoUiOutputRect);
    ofDrawRectangle(infoUiOutputRect);
    ofDrawBitmapString("Output Framebuffer: " + outputNames,1300,595);
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
