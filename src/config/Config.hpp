#pragma once

#include <string>
#include "ofxJSONElement.h"
#include "PanelGroupConfig.hpp"
#include "InputsConfig.hpp"
#include "OutputsConfig.hpp"

class Config {
    public:
        
        InputsConfig Inputs;
        OutputsConfig Outputs;
            
        PanelGroupConfig PanelInfo;
    
        void setup(ofxJSONElement json);
        Config();
};
