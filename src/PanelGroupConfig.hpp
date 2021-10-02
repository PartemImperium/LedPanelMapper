#pragma once

#include <vector>
#include "PanelConfig.hpp"

class PanelGroupConfig {
    public:
        int PanelWidth;
        int PanelHeight;
    
        int PanelsToFillWidth;
        int PanelsToFillHeight;
    
        std::vector<PanelConfig> Panels;
};
