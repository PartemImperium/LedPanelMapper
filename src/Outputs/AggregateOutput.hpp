#pragma once

// std
#include <string>
#include <vector>
#include <algorithm>

#include "Config.hpp"

#include "NdiOutput.hpp"
#include "DeckLinkOutput.hpp"

#if __APPLE__
#include "SyphonOutput.hpp"
#endif

class AggregateOutput {
public:
    void setup(Config *config);
    void draw();
    
    ofFbo frameBuffer;

    std::string getOutputNames();
private:
    std::vector<std::unique_ptr<BaseOutput>> outputs;
    std::string outputNames;
};
