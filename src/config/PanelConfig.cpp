#include "PanelConfig.hpp"

void PanelConfig::setup(ofxJSONElement json, int panelNumber) {
    setName("Panel (" + std::to_string(panelNumber) + ")");
        
    X = json["x"].asInt();
    X.setName("Source X");
    X.setMin(0);
    X.setMax(1920);//TODO: Decide what to put for max/ how to get a logical max based on what the source res is
    add(X);
    
    Y = json["y"].asInt();
    Y.setName("Source Y");
    Y.setMin(0);
    Y.setMax(1080);//TODO: Decide what to put for max/ how to get a logical max based on what the source res is
    add(Y);
}

ofxJSONElement PanelConfig::getJson() {
    ofxJSONElement json;
    
    json["x"] = X.get();
    json["y"] = Y.get();
    
    return json;
}
