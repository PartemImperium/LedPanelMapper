#pragma once

#include "Config.hpp"
#include "BaseInput.hpp"

// Open Frameworks
#include "ofMain.h"

class StaticImageInput: public BaseInput {
    public:
        StaticImageInput() {};
        virtual ~StaticImageInput() {};
    
        virtual void setup(Config config);
        virtual void draw();
        virtual void update();
        virtual std::string InputName();

    private:
        Config c;
        ofImage image;
};
