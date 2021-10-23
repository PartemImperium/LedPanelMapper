#include "DeckLinkInput.hpp"

void DeckLinkInput::setup(Config *config) {
    DrawIndex = config->Inputs.DeckLink.DrawIndex;

    int deviceId = config->Inputs.DeckLink.DeviceId - 1;
    if (deckLinkInput.setup(deviceId)) {
        deckLinkInput.start(config->Inputs.DeckLink.VideoMode);
    }
    name = "Black Magic DeckLink (" + std::to_string(deviceId) + ")";
}

void DeckLinkInput::draw() {
    deckLinkInput.draw(0, 0);
}

void DeckLinkInput::update() {
    deckLinkInput.update();
}

std::string DeckLinkInput::InputName() {
    return name;
}
