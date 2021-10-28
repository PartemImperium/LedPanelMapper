#include "PanelCalculator.hpp"

void PanelCalculator::setup(Config* config) {
    c = config;
    
    framebuffer.allocate(c->Inputs.inputWidth, c->Inputs.inputHeight);
    
    panelWidth.setName("Calculated Panel Width");
    panelHeight.setName("Calculated Panel Height");
    
    calculate();
}

void PanelCalculator::calculate() {
    std::vector<PanelCalculation> tempPanels;
    for (int i = 0; i < c->PanelInfo.Panels.size(); i++) {
        PanelCalculation tempCalc;
        
        panelWidth = c->Inputs.inputWidth / c->PanelInfo.PanelsToFillWidth;
        panelHeight = c->Inputs.inputHeight / c->PanelInfo.PanelsToFillHeight;
        
        tempCalc.destinationX = (i * c->PanelInfo.PanelWidth);
        tempCalc.destinationY = 0;
        tempCalc.destinationWidth = c->PanelInfo.PanelWidth;
        tempCalc.destinationHeight = c->PanelInfo.PanelHeight;
        
        tempCalc.sourceX = c->PanelInfo.Panels[i].X;
        tempCalc.sourceY = c->PanelInfo.Panels[i].Y;
        tempCalc.sourceWidth = panelWidth;
        tempCalc.sourceHeight = panelHeight;
        
        tempPanels.push_back(tempCalc);
    }
    panels = tempPanels;

    ofNoFill();
    framebuffer.begin();

    ofClear(0, 0, 0);
    for (int i = 0; i < panels.size(); i++) {
        ofDrawRectangle(panels[i].getSource());
    }
    
    framebuffer.end();
    ofFill();
}

void PanelCalculator::savePanelLayoutImage() {
    ofPixels pix;
    pix.allocate(c->Inputs.inputWidth, c->Inputs.inputHeight, OF_IMAGE_QUALITY_BEST);
    framebuffer.readToPixels(pix);
    ofSaveImage(pix, ofFilePath::join(c->PanelLayoutImagePath.get(), "panel-layout.png"));
}

void PanelCalculator::draw(ofRectangle rect) {
    framebuffer.draw(rect);
}

