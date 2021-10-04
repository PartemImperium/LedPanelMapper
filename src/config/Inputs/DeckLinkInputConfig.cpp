#include "DeckLinkInputConfig.hpp"

void DeckLinkInputConfig::setup(ofxJSONElement json) {
    DeviceId = json["deviceId"].asInt();
    VideoMode = json["videoMode"].asString();
    IsInputEnabled = json["isEnabled"].asBool();   
}
