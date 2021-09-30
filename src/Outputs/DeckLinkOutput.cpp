#include "DeckLinkOutput.hpp"

void DeckLinkOutput::setup(Config config) {
    c = config;
    if (deckLinkOut.setup(2)) {
        deckLinkOut.start(bmdModeHD1080p30);
    }
}

void DeckLinkOutput::draw(ofFbo output) {
    deckLinkOut.publishTexture(output.getTexture());
}

void DeckLinkOutput::update() {
    
}

std::string DeckLinkOutput::OutputName() {
    return "Black Magic DeckLink";
}
