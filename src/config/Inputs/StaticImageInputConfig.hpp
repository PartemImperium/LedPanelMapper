#pragma once

#include <string>
#include "ofxJSONElement.h"

class StaticImageInputConfig {
    public:
        bool IsInputEnabled;
        std::string FilePath;
        int DrawIndex;
        
        void setup(ofxJSONElement json);
};
