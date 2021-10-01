#pragma once

// Open Frameworks
#include "ofMain.h"

class PanelCalculations {
    public:
        float destinationX;
        float destinationY;
        float destinationWidth;
        float destinationHeight;
    
        float sourceX;
        float sourceY;
        float sourceWidth;
        float sourceHeight;
    
        void draw(ofTexture& texture);
};
