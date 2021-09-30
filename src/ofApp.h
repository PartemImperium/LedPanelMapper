#pragma once
// std
#include <string>
#include <vector>

// Project Code
#include "Config.hpp"

// Inputs
#include "BaseInput.hpp"
#include "VideoPlayerInput.hpp"
#include "StaticImageInput.hpp"
#include "NdiInput.hpp"

#if __APPLE__
#include "SyphonInput.hpp"
#endif

// Outputs
#include "NdiOutput.hpp"

#if __APPLE__
#include "SyphonOutput.hpp"
#endif

// JSON addon
#include "ofxJSONElement.h"



class ofApp : public ofBaseApp{

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
        
    private:
        Config c;
        void setupConfig();
    
        // Info UI
        ofRectangle infoUiInputRect;
        ofRectangle infoUiOutputRect;
        void setupInfoUi(Config config);
        void drawInfoUi();

        // Inputs
        ofFbo inputFrameBuffer;
        BaseInput* input;
    
        void setupInput();
    
        // Outputs
        ofFbo outputFrameBuffer;
        std::vector<std::unique_ptr<BaseOutput>> outputs;
        string outputNames;
            
        void setupOutputs();
    
        // Panel scaling and selection.
        void drawPanelsToOutputFrameBuffer();
};
