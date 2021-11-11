#include "StaticImageInput.hpp"

void StaticImageInput::setup(Config *config) {
    DrawIndex = config->Inputs.StaticImage.DrawIndex;
    
    image.load(config->Inputs.StaticImage.FilePath);
}

void StaticImageInput::draw() {
    image.draw(0, 0);
}

void StaticImageInput::update() {
    
}

std::string StaticImageInput::InputName() {
    return "Static Image";
}

ofTexture StaticImageInput::getTexture() {
    return image.getTexture();
}
