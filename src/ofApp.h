#pragma once

#include "ofMain.h"
#include "Config.hpp"

#include "ofxSyphonClient.h"
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

        ofFbo input;
        ofFbo output;
    
        ofxSyphonClient syphonClient;
        void setupSyphonClient(Config config);
        void drawSyphonToInputFrameBuffer();
    
        ofxSyphonServer syphonServer;
        void setupSyphonServer(Config config);
        void drawPanelsToOutputFrameBuffer();
};
