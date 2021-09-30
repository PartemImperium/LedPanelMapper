#pragma once

#include "StaticImageInputConfig.hpp"
#include "VideoPlayerInputConfig.hpp"
#include "SyphonInputConfig.hpp"
#include "NdiInputConfig.hpp"

class InputsConfig {
    public:
        StaticImageInputConfig StaticImage;
        VideoPlayerInputConfig VideoPlayer;
        SyphonInputConfig Syphon;
        NdiInputConfig Ndi;
};
