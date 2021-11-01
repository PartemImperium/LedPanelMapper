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
        
        
        ofParameter<float> panelWidth;
        ofParameter<float> panelHeight;
    
        ofParameter<void> savePanelLayoutE;
    private:
        Config* c;
        ofFbo framebuffer;
    
        //For some reason when a event handler calls ofSystemSaveDialog it triggers twice. This is a workaround for that....
        bool triggerSavePanel;
        void triggerSavePanelHandler();
};
