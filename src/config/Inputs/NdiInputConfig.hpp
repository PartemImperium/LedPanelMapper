#pragma once

#include <string>
#include "ofxJSONElement.h"

class NdiInputConfig {
    public:
        bool IsInputEnabled;
        std::string FeedName;
        int DrawIndex;
    
        void setup(ofxJSONElement json);
};
