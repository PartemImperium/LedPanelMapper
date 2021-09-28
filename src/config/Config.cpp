#include "Config.hpp"
#include "Panel.hpp"

Config::Config(){}

void Config::setup(ofxJSONElement json){
    
    // Inputs
    ofxJSONElement inputs = json["inputs"];
    
    ofxJSONElement videoPlayerInput = inputs["videoPlayer"];
    Inputs.VideoPlayer.FilePath = videoPlayerInput["filePath"].asString();
    Inputs.VideoPlayer.IsInputEnabled = videoPlayerInput["isEnabled"].asBool();
 
    ofxJSONElement syphonInput = inputs["syphon"];
    Inputs.Syphon.ApplicationName = syphonInput["applicationName"].asString();
    Inputs.Syphon.ServerName = syphonInput["serverName"].asString();
    Inputs.Syphon.IsInputEnabled = syphonInput["isEnabled"].asBool();
    
    ofxJSONElement ndiInput = inputs["ndi"];
    Inputs.Ndi.FeedName = ndiInput["feedName"].asString();
    Inputs.Ndi.IsInputEnabled = ndiInput["isEnabled"].asBool();
    
    // Outputs
    ofxJSONElement outputs = json["outputs"];
    
    ofxJSONElement syphonOutput = outputs["syphon"];
    Outputs.Syphon.Name = syphonOutput["name"].asString();
    Outputs.Syphon.IsOutputEnabled = syphonOutput["isEnabled"].asBool();

    // Panels
    ofxJSONElement panels = json["panels"];
    for (int i = 0; i < panels.size(); i++){
        Panel p;
        p.X = panels[i]["x"].asFloat();
        p.Y = panels[i]["y"].asFloat();
        
        Panels.push_back(p);
    }
}
