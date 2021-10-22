#include "DeckLinkInput.hpp"

void DeckLinkInput::setup(Config *config) {
    DrawIndex = config->Inputs.DeckLink.DrawIndex;

    if (deckLinkInput.setup(1)) {//TODO: Make this use config
        deckLinkInput.start(bmdModeHD1080p30);
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
