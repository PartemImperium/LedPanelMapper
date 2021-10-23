#pragma once

#include "ofxJSONElement.h"

class DeckLinkInputConfig {
    public:
        bool IsInputEnabled;
        int DeviceId;
        unsigned int VideoMode;
        int DrawIndex;
    
        void setup(ofxJSONElement json);
};
