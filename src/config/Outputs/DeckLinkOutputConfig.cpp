#include "DeckLinkOutputConfig.hpp"

void DeckLinkOutputConfig::setup(ofxJSONElement json) {

    DeviceId = json["deviceId"].asInt();
    VideoMode = json["videoMode"].asInt();
    IsOutputEnabled = json["isEnabled"].asBool();
}