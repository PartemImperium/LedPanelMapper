#include "PanelConfig.hpp"

void PanelConfig::setup(ofxJSONElement json) {
    X = json["x"].asFloat();
    Y = json["y"].asFloat();
}