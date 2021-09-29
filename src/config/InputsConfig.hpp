#pragma once

#include "VideoPlayerInputConfig.hpp"
#include "SyphonInputConfig.hpp"
#include "NdiInputConfig.hpp"

class InputsConfig {
    public:
        VideoPlayerInputConfig VideoPlayer;
        SyphonInputConfig Syphon;
        NdiInputConfig Ndi;
};
