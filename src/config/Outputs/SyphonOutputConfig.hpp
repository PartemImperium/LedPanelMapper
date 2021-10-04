#pragma once

#include <string>
#include "ofxJSONElement.h"

class SyphonOutputConfig {
    public:
        bool IsOutputEnabled;
        std::string Name;

        void setup(ofxJSONElement json);
};
