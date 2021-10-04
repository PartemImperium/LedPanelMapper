#pragma once

#include <string>
#include "ofxJSONElement.h"

class NdiInputConfig {
    public:
        bool IsInputEnabled;
        std::string FeedName;
    
        void setup(ofxJSONElement json);
};
