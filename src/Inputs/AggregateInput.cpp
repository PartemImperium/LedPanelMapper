#include "AggregateInput.hpp"

void AggregateInput::setup(Config *config) {
    frameBuffer.allocate(1920, 1080);
    
    if (config->Inputs.StaticImage.IsInputEnabled) {
        inputs.push_back(std::move(std::make_unique<StaticImageInput>()));
    }
    if (config->Inputs.VideoPlayer.IsInputEnabled) {
        inputs.push_back(std::move(std::make_unique< VideoPlayerInput>()));
    }
#if __APPLE__
    if (config->Inputs.Syphon.IsInputEnabled) {
        inputs.push_back(std::move(std::make_unique<SyphonInput>()));
    }
#endif
    if (config->Inputs.Ndi.IsInputEnabled) {
        inputs.push_back(std::move(std::make_unique<NdiInput>()));
    }
    if (config->Inputs.DeckLink.IsInputEnabled) {
        inputs.push_back(std::move(std::make_unique<DeckLinkInput>()));
    }

    for (auto& i : inputs) {
        i->setup(config);
    }
    std::sort(inputs.begin(), inputs.end(),[] (const std::unique_ptr<BaseInput>& left, const std::unique_ptr<BaseInput>& right) {
        return left->DrawIndex < right->DrawIndex;
    });
    for (auto& i : inputs) {// Do this here instead of by the setup so that they are in draw order.
        inputNames += i->InputName() + " ";
    }
}

void AggregateInput::draw() {
    // Draw Inputs to Input Framebuffer.
    frameBuffer.begin();

    for (auto& i : inputs) {
        i->draw();
    }

    frameBuffer.end();
}

void AggregateInput::update() {
    for (auto& i : inputs) {
        i->update();
    }
}

std::string AggregateInput::getInputNames() {
    return inputNames;
}
