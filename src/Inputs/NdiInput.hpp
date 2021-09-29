#pragma once

// Open Frameworks
#include "ofMain.h"

#include "Config.hpp"
#include "BaseInput.hpp"

// NDI addon
#include "ofxNDIReceiver.h"
#include "ofxNDIRecvStream.h"
#include "ofxNDIFinder.h"

#include <chrono>
#include <thread>

class NdiInput: public BaseInput {
    public:
        virtual void setup(Config config);
        virtual void draw();
        virtual void update();
        std::string InputName = "NDI Receiver";

    private:
        Config c;
        ofxNDIReceiver ndiReceiver;
        ofxNDIRecvVideoFrameSync ndiVideoFrameSync; 
};
