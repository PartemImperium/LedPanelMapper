#include "DeckLinkOutput.hpp"

void DeckLinkOutput::setup(Config *config) {
    if (deckLinkOut.setup(config->Outputs.DeckLink.DeviceId - 1)) {
        deckLinkOut.start(config->Outputs.DeckLink.VideoMode);
    }
    name = "Black Magic DeckLink (" + std::to_string(config->Outputs.DeckLink.DeviceId) + ")";
}

void DeckLinkOutput::draw(ofFbo output) {
    deckLinkOut.publishTexture(output.getTexture());
}

void DeckLinkOutput::update() {
    
}

std::string DeckLinkOutput::OutputName() {
    return name;
}
