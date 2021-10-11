#include "PanelConfig.hpp"

void PanelConfig::setup(ofxJSONElement json, int panelNumber) {
    setName("Panel (" + std::to_string(panelNumber) + ")");
        
    X.set("Source X", json["x"].asInt(), 0, 1920);//TODO: Decide what to put for max/ how to get a logical max based on what the source res is
    add(X);
    
    Y.set("Source Y", json["y"].asInt(), 0, 1080);//TODO: Decide what to put for max/ how to get a logical max based on what the source res is
    add(Y);
}

ofxJSONElement PanelConfig::getJson() {
    ofxJSONElement json;
    
    json["x"] = X.get();
    json["y"] = Y.get();
    
    return json;
}
