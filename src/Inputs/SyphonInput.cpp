#if __APPLE__

#include "SyphonInput.hpp"

std::string SyphonInput::InputName() {
    return "Syphon Client";
}
void SyphonInput::setup(Config *config) {
    DrawIndex = config->Inputs.Syphon.DrawIndex;

    syphonClient.setup();
    syphonClient.set(config->Inputs.Syphon.ServerName,config->Inputs.Syphon.ApplicationName);
}

void SyphonInput::draw() {
    syphonClient.draw(0,0);
}

void SyphonInput::update() {
    
}

ofTexture SyphonInput::getTexture() {
    return syphonClient.getTexture();
}

#endif
