#include "StaticImageInput.hpp"

void StaticImageInput::setup(Config config) {
    c = config;
    DrawIndex = c.Inputs.StaticImage.DrawIndex;
    
    image.load(c.Inputs.StaticImage.FilePath);
}

void StaticImageInput::draw() {
    image.draw(0, 0);
}

void StaticImageInput::update() {
    
}

std::string StaticImageInput::InputName() {
    return "Static Image";
}
