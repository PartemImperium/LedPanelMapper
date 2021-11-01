#include "PanelCalculator.hpp"

void PanelCalculator::setup(Config* config) {
    c = config;
    
    framebuffer.allocate(c->Inputs.inputWidth, c->Inputs.inputHeight);
    
    panelWidth.setName("Calculated Panel Width");
    panelHeight.setName("Calculated Panel Height");
    
    calculate();
    
    savePanelLayoutE.addListener(this, &PanelCalculator::triggerSavePanelHandler,200);
    savePanelLayoutE.setName("Save Panel Layout Image");
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
        auto savePath = ofSystemSaveDialog("panel-layout.png","Select Save Path");

        if (savePath.bSuccess){
            ofPixels pix;
            pix.allocate(c->Inputs.inputWidth, c->Inputs.inputHeight, OF_IMAGE_QUALITY_BEST);
            framebuffer.readToPixels(pix);

            ofSaveImage(pix, savePath.filePath);
        }
}

void PanelCalculator::triggerSavePanelHandler() {
    triggerSavePanel = true;
}

void PanelCalculator::draw(ofRectangle rect) {
    framebuffer.draw(rect);
    
    // This is more of a update activitiy but I dont want to add a update function just for the jank workaround of the button calling the event twice when using a save dialog in a event handler
    if (triggerSavePanel) {
        triggerSavePanel = false;
        savePanelLayoutImage();
    }
}
