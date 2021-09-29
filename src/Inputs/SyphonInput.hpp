#if __APPLE__

#pragma once

#include "Config.hpp"
#include "BaseInput.hpp"

// Syphon addon
#include "ofxSyphonClient.h"

class SyphonInput: public BaseInput {
    public:
        virtual void setup(Config config);
        virtual void draw();
        virtual void update();
        virtual std::string InputName();

    private:
        Config c;
        ofxSyphonClient syphonClient;
};

#endif
