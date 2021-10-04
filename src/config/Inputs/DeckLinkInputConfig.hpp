#pragma once

#include <string>
#include "ofxJSONElement.h"

class DeckLinkInputConfig {
    public:
        bool IsInputEnabled;
        int DeviceId;
        std::string VideoMode;

        void setup(ofxJSONElement json);
};
