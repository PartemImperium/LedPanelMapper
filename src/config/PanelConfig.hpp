#pragma once

#include "ofxJSONElement.h"
#include "ofParameter.h"

class PanelConfig : public ofParameterGroup {
    public:
        ofParameter<int> Y;
        ofParameter<int> X;

        void setup(ofxJSONElement json, int panelNumber);
        ofxJSONElement getJson();
};
