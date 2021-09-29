#pragma once

// Open Frameworks
#include "ofMain.h"
#include "Config.hpp"
#include "BaseInput.hpp"

class VideoPlayerInput: public BaseInput {
    public:
        virtual void setup(Config config);
        virtual void draw();
        virtual void update();
        std::string InputName = "Video Player";

    private:
        Config c;
        ofVideoPlayer videoPlayer;
};
