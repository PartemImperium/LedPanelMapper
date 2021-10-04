#pragma once

#include "ofxJSONElement.h"

class PanelConfig {
    public:
        float Y;
        float X;

        void setup(ofxJSONElement json);
};
