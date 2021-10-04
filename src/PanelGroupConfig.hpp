#pragma once

#include <vector>
#include "PanelConfig.hpp"

#include "ofxJSONElement.h"

class PanelGroupConfig {
    public:
        int PanelWidth;
        int PanelHeight;
    
        int PanelsToFillWidth;
        int PanelsToFillHeight;
    
        std::vector<PanelConfig> Panels;

        void setup(ofxJSONElement json);
};
