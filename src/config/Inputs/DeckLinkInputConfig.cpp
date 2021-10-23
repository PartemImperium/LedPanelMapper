#include "DeckLinkInputConfig.hpp"

void DeckLinkInputConfig::setup(ofxJSONElement json) {
    DeviceId = json["deviceId"].asInt();
    VideoMode = json["videoMode"].asInt();
    IsInputEnabled = json["isEnabled"].asBool();
    DrawIndex = json["drawIndex"].asInt();
}
