#include "Config.hpp"
#include "Panel.hpp"

Config::Config(){}

void Config::setup(ofxJSONElement json){
    SyphonApplication = json["syphonApplication"].asString();
    SyphonServer = json["syphonServer"].asString();
    
    for (int i = 0; i < json["panels"].size(); i++){
        Panel p;
        p.X = json["panels"][i]["x"].asFloat();
        p.Y = json["panels"][i]["y"].asFloat();
        Panels.push_back(p);
    }
}
