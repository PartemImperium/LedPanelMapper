#include "DeckLinkInput.hpp"

void DeckLinkInput::setup(Config *config) {
    DrawIndex = config->Inputs.DeckLink.DrawIndex;

    int deviceId = SharedDeckLinkHelpers::convertHumanReadibleDeviceId(config->Inputs.DeckLink.DeviceId);
    if (deckLinkInput.setup(deviceId)) {
        deckLinkInput.start(config->Inputs.DeckLink.VideoMode);
    }
    name = "Black Magic DeckLink (" + std::to_string(config->Inputs.DeckLink.DeviceId) + ")";// This is not converted to the internal device id on purpose. This is being displayed so we want the +1 to the internal one.
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
