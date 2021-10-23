#include "DeckLinkOutput.hpp"

void DeckLinkOutput::setup(Config *config) {
    int deviceId = config->Outputs.DeckLink.DeviceId - 1;
    if (deckLinkOut.setup(deviceId)) {
        deckLinkOut.start(config->Outputs.DeckLink.VideoMode);
    }
    name = "Black Magic DeckLink (" + std::to_string(deviceId) + ")";
}

void DeckLinkOutput::draw(ofFbo output) {
    deckLinkOut.publishTexture(output.getTexture());
}

void DeckLinkOutput::update() {
    
}

std::string DeckLinkOutput::OutputName() {
    return name;
}
