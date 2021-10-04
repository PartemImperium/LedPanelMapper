#include "VideoPlayerInputConfig.hpp"

void VideoPlayerInputConfig::setup(ofxJSONElement json) {
    FilePath = json["filePath"].asString();
    IsInputEnabled = json["isEnabled"].asBool();
    DrawIndex = json["drawIndex"].asInt();
}
