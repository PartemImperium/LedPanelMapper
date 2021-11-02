#pragma once

#include <string>

#include "ofxJSONElement.h"
#include "ofParameter.h"

#include "PanelGroupConfig.hpp"
#include "InputsConfig.hpp"
#include "OutputsConfig.hpp"

class Config : public ofParameterGroup {
    public:
        
        InputsConfig Inputs;
        OutputsConfig Outputs;
            
        PanelGroupConfig PanelInfo;
        
        void setup(ofxJSONElement json);
        void save();
        Config();
    
        ofParameter<void> saveE;
};
