#pragma once

#include <string>
#include "ofxJSONElement.h"

class VideoPlayerInputConfig {
    public:
        bool IsInputEnabled;
        std::string FilePath;
        int DrawIndex;
    
        void setup(ofxJSONElement json);
};
