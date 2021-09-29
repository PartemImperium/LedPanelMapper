#include "SyphonInput.hpp"

void SyphonInput::setup(Config config) {
    c = config;
    syphonClient.setup();
    syphonClient.set(c.Inputs.Syphon.ServerName,config.Inputs.Syphon.ApplicationName);
}

void SyphonInput::draw() {
    syphonClient.draw(0,0);
}

void SyphonInput::update() {
    
}