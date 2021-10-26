#pragma once

#include "Config.hpp"
#include "PanelCalculation.hpp"

class PanelCalculator {
    public:
        void setup(Config* config);
    
        void calculate();
    
        std::vector<PanelCalculation> panels;
        ofFbo framebuffer;
        
        float panelWidth;
        float panelHeight;
    private:
        Config* c;
};
