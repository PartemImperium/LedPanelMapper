#include "DeckLinkInput.hpp"

void DeckLinkInput::setup(Config *config) {
    DrawIndex = config->Inputs.DeckLink.DrawIndex;

    if (deckLinkInput.setup(config->Inputs.DeckLink.DeviceId - 1)) {
        deckLinkInput.start(config->Inputs.DeckLink.VideoMode);
    }
}

void DeckLinkInput::draw() {
    deckLinkInput.draw(0, 0);
}

void DeckLinkInput::update() {
    deckLinkInput.update();
}

std::string DeckLinkInput::InputName() {
    return "Deck Link Input";
}
