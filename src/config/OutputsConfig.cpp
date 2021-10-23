#include "OutputsConfig.hpp"

void OutputsConfig::setup(ofxJSONElement json) {
	Syphon.setup(json["syphon"]);
	Ndi.setup(json["ndi"]);
    DeckLink.setup(json["deckLink"]);
    
    outputWidth = json["outputWidth"].asInt();
    outputHeight = json["outputHeight"].asInt();
}
