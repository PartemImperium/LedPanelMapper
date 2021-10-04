#include "SyphonInputConfig.hpp"

void SyphonInputConfig::setup(ofxJSONElement json) {
    ApplicationName = json["applicationName"].asString();
	ServerName = json["serverName"].asString();
	IsInputEnabled = json["isEnabled"].asBool();
    DrawIndex = json["drawIndex"].asInt();
}
