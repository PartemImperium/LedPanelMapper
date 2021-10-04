#pragma once

#include <string>
#include "ofxJSONElement.h"

class NdiOutputConfig {
    public:
        bool IsOutputEnabled;
        std::string Name;

        void setup(ofxJSONElement json);
};
