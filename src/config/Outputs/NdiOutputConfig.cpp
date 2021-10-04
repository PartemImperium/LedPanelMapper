#include "NdiOutputConfig.hpp"

void NdiOutputConfig::setup(ofxJSONElement json) {
	Name = json["name"].asString();
	IsOutputEnabled = json["isEnabled"].asBool();
}