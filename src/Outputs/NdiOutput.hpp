#pragma once

#include "BaseOutput.hpp"

#include "ofxNDISender.h"
#include "ofxNDISendStream.h"

class NdiOutput: public BaseOutput {
    public:
        NdiOutput() {};
        virtual ~NdiOutput() {};
    
        virtual void setup(Config *config);
        virtual void draw(ofFbo output);
    
        virtual std::string OutputName();

    private:
        ofxNDISender ndiSender;
        ofxNDISendVideo ndiSendVideo;};
