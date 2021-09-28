#pragma once

// Open Frameworks
#include "ofMain.h"

// Project Code
#include "Config.hpp"

// JSON addon
#include "ofxJSONElement.h"

// Syphon addon
#include "ofxSyphonClient.h"

// NDI addon
#include "ofxNDIReceiver.h"
#include "ofxNDIRecvStream.h"
#include "ofxNDIFinder.h"
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
        ofFbo input;
    
        ofVideoPlayer videoPlayer;
        void setupVideoPlayer(Config config);
        void drawVideoPlayerToInputFrameBuffer();
        void updateVideoPlayerInputFeed();
    
        ofxSyphonClient syphonClient;
        void setupSyphonClient(Config config);
        void drawSyphonToInputFrameBuffer();
        void updateSyphonInputFeed();

        ofxNDIReceiver ndiReceiver;
        ofxNDIRecvVideoFrameSync ndiVideoFrameSync;
        void setupNdiClient(Config config);
        void drawNdiToInputFrameBuffer();
        void updateNdiInputFeed();
    
        // Outputs
        ofFbo output;

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
