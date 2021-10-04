#include "NdiInputConfig.hpp"

void NdiInputConfig::setup(ofxJSONElement json) {
	FeedName = json["feedName"].asString();
	IsInputEnabled = json["isEnabled"].asBool();
}
