#pragma once

// std
#include <string>
#include <vector>
#include <algorithm>

// Project Code
#include "Config.hpp"
#include "PanelCalculations.hpp"
#include "AggregateInput.hpp"
#include "AggregateOutput.hpp"

// Open Frameworks addons
#include "ofxJSONElement.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
        void exit();
        
    private:
        Config c;
        void setupConfig();
    
        float calculatedPanelWidth;
        float calculatedPanelHeight;
        std::vector<PanelCalculations> panels;
        void setupPanelCalculations();
    
        // Info UI
        ofFbo infoUiInputFrameBuffer;
        ofRectangle infoUiInputRect;
        ofRectangle infoUiOutputRect;
        ofxPanel gui;
        void setupInfoUi(Config config);
        void drawInfoUi();
        void savePanelLayoutImage();
        
        AggregateInput input;
    
        AggregateOutput output;
        
        // Panel scaling and selection.
        void drawPanelsToOutputFrameBuffer();
};
