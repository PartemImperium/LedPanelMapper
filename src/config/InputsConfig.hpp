#pragma once

#include "StaticImageInputConfig.hpp"
#include "VideoPlayerInputConfig.hpp"
#include "SyphonInputConfig.hpp"
#include "NdiInputConfig.hpp"
#include "DeckLinkInputConfig.hpp"

#include "ofxJSONElement.h"

class InputsConfig {
    public:
        StaticImageInputConfig StaticImage;
        VideoPlayerInputConfig VideoPlayer;
        SyphonInputConfig Syphon;
        NdiInputConfig Ndi;
        DeckLinkInputConfig DeckLink;

        void setup(ofxJSONElement json);
};
