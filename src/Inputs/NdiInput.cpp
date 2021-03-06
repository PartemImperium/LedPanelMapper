#include "NdiInput.hpp"

std::string NdiInput::InputName() {
    return "NDI Receiver";
}

void NdiInput::setup(Config *config) {
    NDIlib_initialize();
    DrawIndex = config->Inputs.Ndi.DrawIndex;
    
    buffer.allocate(config->Inputs.inputWidth, config->Inputs.inputHeight);

    ofxNDIFinder ndiFinder;
    auto sources = ndiFinder.listSources();
    
    for (int i = 0; i < sources.size(); i++) {
        auto s = sources[i];
        if (s.p_ndi_name == config->Inputs.Ndi.FeedName){
            ndiReceiver.changeConnection(s);
            ndiReceiver.setup();
            ndiVideoFrameSync.setup(ndiReceiver);
        }
    }
    // I dont know why this is needed..... It wasnt needed when it was directly in the ofApp.cpp..... TODO: Find out why and fix....
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

void NdiInput::draw() {
    if(ndiVideoFrameSync.isFrameNew()) {
        buffer.begin();
        
        ofPixels tempPixels;
        ndiVideoFrameSync.decodeTo(tempPixels);
        ofImage(tempPixels).draw(0,0);
        
        buffer.end();
    }
    buffer.draw(0,0);
}

void NdiInput::update() {
    if(ndiReceiver.isConnected()) {
        ndiVideoFrameSync.update();
    }
}

ofTexture NdiInput::getTexture() {
    return buffer.getTexture();
}
