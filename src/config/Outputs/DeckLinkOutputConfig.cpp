#include "DeckLinkOutputConfig.hpp"

void DeckLinkOutputConfig::setup(ofxJSONElement json) {

    DeviceId = json["deviceId"].asInt();
    VideoMode = json["videoMode"].asString();
    IsOutputEnabled = json["isEnabled"].asBool();
}
