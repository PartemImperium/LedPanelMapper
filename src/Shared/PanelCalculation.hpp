#pragma once

// Open Frameworks
#include "ofMain.h"

class PanelCalculation {
    public:
        float destinationX;
        float destinationY;
        float destinationWidth;
        float destinationHeight;
    
        ofRectangle getDestination();
    
        float sourceX;
        float sourceY;
        float sourceWidth;
        float sourceHeight;
    
        ofRectangle getSource();
    
        void draw(ofTexture& texture);
};
