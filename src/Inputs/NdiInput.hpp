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
        NdiInput() {};
        virtual ~NdiInput() {};
    
        virtual void setup(Config *config);
        virtual void draw();
        virtual void update();
        virtual std::string InputName();
        virtual ofTexture getTexture();

    private:
        ofxNDIReceiver ndiReceiver;
        ofxNDIRecvVideoFrameSync ndiVideoFrameSync;
        
        ofFbo buffer;
};
