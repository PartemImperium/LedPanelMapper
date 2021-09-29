#pragma once

#include <string>
#include "ofxJSONElement.h"
#include "PanelConfig.hpp"
#include "InputsConfig.hpp"
#include "OutputsConfig.hpp"

class Config {
    public:
        
        InputsConfig Inputs;
        OutputsConfig Outputs;
        std::vector<PanelConfig> Panels;

        void setup(ofxJSONElement json);
        Config();
};
