#include "DeckLinkOutput.hpp"

void DeckLinkOutput::setup(Config *config) {
    int deviceId = SharedDeckLinkHelpers::convertHumanReadibleDeviceId(config->Outputs.DeckLink.DeviceId);
    
    if (deckLinkOut.setup(deviceId)) {
        BMDDisplayMode displayMode = SharedDeckLinkHelpers::convertDispayMode(config->Outputs.DeckLink.VideoMode);
        deckLinkOut.start(displayMode);
    }
    name = "Black Magic DeckLink (" + std::to_string(config->Outputs.DeckLink.DeviceId) + ")";// This is not converted to the internal device id on purpose. This is being displayed so we want the +1 to the internal one.
}

void DeckLinkOutput::draw(ofFbo output) {
    deckLinkOut.publishTexture(output.getTexture());
}

void DeckLinkOutput::update() {
    
}

std::string DeckLinkOutput::OutputName() {
    return name;
}
