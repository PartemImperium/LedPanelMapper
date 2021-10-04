#include "SyphonOutputConfig.hpp"

void SyphonOutputConfig::setup(ofxJSONElement json) {
    Name = json["name"].asString();
	IsOutputEnabled = json["isEnabled"].asBool();
}
