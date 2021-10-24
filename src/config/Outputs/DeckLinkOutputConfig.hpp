#pragma once

#include <string>
#include "ofxJSONElement.h"

class DeckLinkOutputConfig {
    public:
        bool IsOutputEnabled;
        int DeviceId;
        std::string VideoMode;

        void setup(ofxJSONElement json);
};
