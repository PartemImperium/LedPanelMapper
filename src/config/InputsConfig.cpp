#include "InputsConfig.hpp"

void InputsConfig::setup(ofxJSONElement json) {
    StaticImage.setup(json["staticImage"]);
	VideoPlayer.setup(json["videoPlayer"]);
	Syphon.setup(json["syphon"]);
	Ndi.setup(json["ndi"]);
    DeckLink.setup(json["deckLink"]);
}