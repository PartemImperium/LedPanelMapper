#include "NdiOutput.hpp"

std::string NdiOutput::OutputName() {
    return  "NDI Sender";
}

void NdiOutput::setup(Config *config) {
    NDIlib_initialize();

    if(ndiSender.setup(config->Outputs.Ndi.Name)) {
        ndiSendVideo.setup(ndiSender);
        ndiSendVideo.setAsync(true);
    }
}

void NdiOutput::draw(ofFbo output) {
    ofPixels tempPixels;
    output.readToPixels(tempPixels);
    ndiSendVideo.send(tempPixels);
}
