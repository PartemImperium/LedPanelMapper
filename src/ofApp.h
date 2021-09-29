#pragma once
// std
#include <string>

// Project Code
#include "Config.hpp"

// Inputs
#include "BaseInput.hpp"
#include "VideoPlayerInput.hpp"
#include "SyphonInput.hpp"
#include "NdiInput.hpp"

// JSON addon
#include "ofxJSONElement.h"


#include "ofxNDISender.h"
#include "ofxNDISendStream.h"

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
        ofFbo output;
        std::string outputNames;
    
        ofxSyphonServer syphonServer;
        void setupSyphonServer(Config config);
        void drawOutputFramebuffertoSyphon();
    
        ofxNDISender ndiSender;
        ofxNDISendVideo ndiSendVideo;
        void setupNdiSender(Config config);
        void drawOutputFramebufferToNdi();
        

        // Panel scaling and selection.
        void drawPanelsToOutputFrameBuffer();
};
