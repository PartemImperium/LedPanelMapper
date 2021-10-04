#pragma once

#include <string>
#include "ofxJSONElement.h"

class SyphonInputConfig {
    public:
        bool IsInputEnabled;
        std::string ApplicationName;
        std::string ServerName;

        void setup(ofxJSONElement json);
};
