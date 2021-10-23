#include "AggregateOutput.hpp"

void AggregateOutput::setup(Config *config) {
    frameBuffer.allocate(config->Outputs.outputWidth, config->Outputs.outputHeight);

    if (config->Outputs.Ndi.IsOutputEnabled) {
        outputs.push_back(std::move(std::make_unique<NdiOutput>()));
    }
#if __APPLE__
    if (config->Outputs.Syphon.IsOutputEnabled) {
        outputs.push_back(std::move(std::make_unique<SyphonOutput>()));
    }
#endif
    if (config->Outputs.DeckLink.IsOutputEnabled) {
        outputs.push_back(std::move(std::make_unique<DeckLinkOutput>()));
    }

    for (auto& o : outputs) {
        o->setup(config);
        outputNames += o->OutputName() + " ";
    }
}

void AggregateOutput::draw() {
    // Draw Output Framebuffer to all outputs (Multiple outputs can be turned on at the same time).
    for (auto& o : outputs)
    {
        o->draw(frameBuffer);
    }
}

std::string AggregateOutput::getOutputNames() {
    return outputNames;
}
