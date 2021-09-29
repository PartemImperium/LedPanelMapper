#pragma once

#include <string>
#include "Config.hpp"   

class BaseInput {
    public:
        virtual void setup(Config config) = 0;
        virtual void draw() = 0;
        virtual void update() = 0;
        std::string InputName;

    private:
        Config c;
};
