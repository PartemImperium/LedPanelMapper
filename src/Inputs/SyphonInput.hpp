#if __APPLE__

#pragma once

#include "Config.hpp"
#include "BaseInput.hpp"

// Syphon addon
#include "ofxSyphonClient.h"

class SyphonInput: public BaseInput {
    public:
        SyphonInput() {};
        virtual ~SyphonInput() {};
    
        virtual void setup(Config *config);
        virtual void draw();
        virtual void update();
        virtual std::string InputName();
        virtual ofTexture getTexture();

    private:
        ofxSyphonClient syphonClient;
};

#endif
