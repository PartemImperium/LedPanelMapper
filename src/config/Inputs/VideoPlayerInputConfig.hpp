#pragma once

#include <string>
#include "ofxJSONElement.h"

class VideoPlayerInputConfig {
    public:
        bool IsInputEnabled;
        std::string FilePath;

        void setup(ofxJSONElement json);
};
