#include "Config.hpp"
#include "PanelConfig.hpp"

Config::Config() {}

void Config::setup(ofxJSONElement json) {

	// Inputs
	ofxJSONElement inputs = json["inputs"];

    ofxJSONElement staticImageInput = inputs["staticImage"];
    Inputs.StaticImage.FilePath = staticImageInput["filePath"].asString();
    Inputs.StaticImage.IsInputEnabled = staticImageInput["isEnabled"].asBool();
    
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

    ofxJSONElement deckLinkInput = inputs["deckLink"];
    Inputs.DeckLink.DeviceId = deckLinkInput["deviceId"].asInt();
    Inputs.DeckLink.VideoMode = deckLinkInput["videoMode"].asString();
    Inputs.DeckLink.IsInputEnabled = deckLinkInput["isEnabled"].asBool();
    
    
	// Outputs
	ofxJSONElement outputs = json["outputs"];

	ofxJSONElement syphonOutput = outputs["syphon"];
	Outputs.Syphon.Name = syphonOutput["name"].asString();
	Outputs.Syphon.IsOutputEnabled = syphonOutput["isEnabled"].asBool();
    

	ofxJSONElement ndiOutput = outputs["ndi"];
	Outputs.Ndi.Name = syphonOutput["name"].asString();
	Outputs.Ndi.IsOutputEnabled = syphonOutput["isEnabled"].asBool();
    
    ofxJSONElement deckLinkOutput = outputs["deckLink"];
    Outputs.DeckLink.DeviceId = deckLinkOutput["deviceId"].asInt();
    Outputs.DeckLink.VideoMode = deckLinkOutput["videoMode"].asString();
    Outputs.DeckLink.IsOutputEnabled = deckLinkOutput["isEnabled"].asBool();

	// Panels
	ofxJSONElement panels = json["panels"];
	for (int i = 0; i < panels.size(); i++) {
		PanelConfig p;
		p.X = panels[i]["x"].asFloat();
		p.Y = panels[i]["y"].asFloat();

		Panels.push_back(p);
	}
}
