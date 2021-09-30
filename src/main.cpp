#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofSetupOpenGL(1920,1080,OF_WINDOW);			// <-------- setup the GL context

    ofEnableDataPath();
#if __APPLE__
    ofSetDataPathRoot("../Resources/");
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) ||  defined(__NT__)
    ofSetDataPathRoot("../");
#endif

    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());

}
