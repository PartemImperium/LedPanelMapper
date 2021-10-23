#pragma once

// Open Frameworks
#include "ofMain.h"

class PanelCalculations {
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
