#pragma once

// Open Frameworks
#include "ofMain.h"

#include "Config.hpp"
#include "BaseInput.hpp"

class VideoPlayerInput: public BaseInput {
    public:
        VideoPlayerInput() {};
        virtual ~VideoPlayerInput() {};
    
        virtual void setup(Config *config);
        virtual void draw();
        virtual void update();
        virtual std::string InputName();

    private:
        ofVideoPlayer videoPlayer;// TODO: Move this to something that works without installing Quicktime on windows
};
