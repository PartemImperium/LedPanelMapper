#pragma once

#include <string>
#include "Config.hpp"

// Open Frameworks
#include "ofMain.h"

class BaseOutput {
    public:
        BaseOutput() {};
        virtual ~BaseOutput() {};
    
        virtual void setup(Config config) = 0;
        virtual void draw(ofFbo output) = 0;
        virtual std::string OutputName() = 0;

    private:
        Config c;
};
