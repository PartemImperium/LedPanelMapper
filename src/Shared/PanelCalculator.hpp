#pragma once

#include "Config.hpp"
#include "PanelCalculation.hpp"

class PanelCalculator {
    public:
        void setup(Config* config);
    
        void calculate();
        void savePanelLayoutImage();
    
        void draw(ofRectangle rect);
    
        std::vector<PanelCalculation> panels;
        
        
        float panelWidth;
        float panelHeight;
    private:
        Config* c;
        ofFbo framebuffer;
};
