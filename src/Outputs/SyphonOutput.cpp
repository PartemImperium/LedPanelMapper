#if __APPLE__

#include "SyphonOutput.hpp"

std::string SyphonOutput::OutputName() {
    return "Syphon Server";
}

void SyphonOutput::setup(Config config) {
    c = config;
    syphonServer.setName(c.Outputs.Syphon.Name);
    tempTexture.allocate(1920, 1080,GL_RGBA);
}

void SyphonOutput::draw(ofFbo output) {
    syphonServer.publishTexture(&output.getTexture());
}

#endif
