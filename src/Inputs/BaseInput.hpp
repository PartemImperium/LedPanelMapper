#pragma once

#include <string>
#include "Config.hpp"
#include "ofTexture.h"

class BaseInput {
    public:
        BaseInput() {};
        virtual ~BaseInput() {};
    
        virtual void setup(Config *config) = 0;
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual ofTexture getTexture() = 0;
        virtual std::string InputName() = 0;
        int DrawIndex;
};
