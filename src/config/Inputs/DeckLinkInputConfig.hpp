#pragma once

#include "ofxJSONElement.h"

class DeckLinkInputConfig {
    public:
        bool IsInputEnabled;
        int DeviceId;
        std::string VideoMode;
        int DrawIndex;
    
        void setup(ofxJSONElement json);
};
