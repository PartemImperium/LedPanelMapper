#pragma once
#ifndef config_hpp
#define config_hpp

#include <stdio.h>

#endif /* config_hpp */
#include <string>
#include "ofxJSONElement.h"
#include "Panel.hpp"
#include "Inputs.hpp"
#include "Outputs.hpp"

class Config {
    public:
        
        Inputs Inputs;
        Outputs Outputs;
        std::vector<Panel> Panels;

        void setup(ofxJSONElement json);
        Config();
};
