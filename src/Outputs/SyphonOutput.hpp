#if __APPLE__

#pragma once

#include "BaseOutput.hpp"
#include "Config.hpp"

// Syphon addon
#include "ofxSyphonClient.h"

class SyphonOutput: public BaseOutput {
    public:
        SyphonOutput() {};
        virtual ~SyphonOutput() {};
    
        virtual void setup(Config config);
        virtual void draw(ofFbo output);
    
        virtual std::string OutputName();

    private:
        Config c;
        ofxSyphonServer syphonServer;
        ofTexture tempTexture;
};

#endif
