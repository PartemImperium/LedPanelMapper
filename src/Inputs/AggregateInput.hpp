#pragma once

// std
#include <string>
#include <vector>
#include <algorithm>

#include "Config.hpp"

#include "BaseInput.hpp"
#include "VideoPlayerInput.hpp"
#include "StaticImageInput.hpp"
#include "NdiInput.hpp"
#include "DeckLinkInput.hpp"

#if __APPLE__
#include "SyphonInput.hpp"
#endif

class AggregateInput {
    public:
        void setup(Config *config);
        void draw();
        void update();
        
        ofFbo frameBuffer;

        std::string getInputNames();
    private:
        std::vector<std::unique_ptr<BaseInput>> inputs;
        std::string inputNames;
};
