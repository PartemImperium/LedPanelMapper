#pragma once

#include <vector>
#include "PanelConfig.hpp"

#include "ofxJSONElement.h"

#include "ofParameter.h"

class PanelGroupConfig : public ofParameterGroup {
    public:
        ofParameter<int> PanelWidth;
        ofParameter<int> PanelHeight;
    
        ofParameter<int> PanelsToFillWidth;
        ofParameter<int> PanelsToFillHeight;
    
    
        std::vector<PanelConfig> Panels;

        void setup(ofxJSONElement json);
        ofxJSONElement getJson();
};
