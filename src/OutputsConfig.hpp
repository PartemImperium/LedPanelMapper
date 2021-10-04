#pragma once

#include "SyphonOutputConfig.hpp"
#include "NdiOutputConfig.hpp"
#include "DeckLinkOutputConfig.hpp"

#include "ofxJSONElement.h"

class OutputsConfig {
    public:
        SyphonOutputConfig Syphon;
        NdiOutputConfig Ndi;
        DeckLinkOutputConfig DeckLink;

        void setup(ofxJSONElement json);
};
