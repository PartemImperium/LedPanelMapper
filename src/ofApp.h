#pragma once
// std
#include <string>
#include <vector>
#include <algorithm>

// Project Code
#include "Config.hpp"
#include "PanelCalculations.hpp"

// Inputs
#include "BaseInput.hpp"
#include "VideoPlayerInput.hpp"
#include "StaticImageInput.hpp"
#include "NdiInput.hpp"
#include "DeckLinkInput.hpp"

#if __APPLE__
#include "SyphonInput.hpp"
#endif

// Outputs
#include "NdiOutput.hpp"
#include "DeckLinkOutput.hpp"

#if __APPLE__
#include "SyphonOutput.hpp"
#endif

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
        
        // Inputs
        ofFbo inputFrameBuffer;
        std::vector<std::unique_ptr<BaseInput>> inputs;
        string inputNames;
    
        void setupInput();
    
        // Outputs
        ofFbo outputFrameBuffer;
        std::vector<std::unique_ptr<BaseOutput>> outputs;
        string outputNames;
            
        void setupOutputs();
    
        // Panel scaling and selection.
        void drawPanelsToOutputFrameBuffer();
};
