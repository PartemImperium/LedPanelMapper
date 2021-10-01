#include "DeckLinkOutput.hpp"

void DeckLinkOutput::setup(Config config) {
    c = config;

    if (deckLinkOut.setup(c.Outputs.DeckLink.DeviceId - 1)) {
        deckLinkOut.start(c.Outputs.DeckLink.VideoMode);
    }
}

void DeckLinkOutput::draw(ofFbo output) {
    deckLinkOut.publishTexture(output.getTexture());
}

void DeckLinkOutput::update() {
    
}

std::string DeckLinkOutput::OutputName() {
    return "Black Magic DeckLink (" + std::to_string(c.Outputs.DeckLink.DeviceId) + ")";
}
