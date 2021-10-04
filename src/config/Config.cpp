#include "Config.hpp"
#include "PanelConfig.hpp"

Config::Config() {}

void Config::setup(ofxJSONElement json) {

	// Inputs
	Inputs.setup(json["inputs"]);

	// Outputs
	Outputs.setup(json["outputs"]);

	// Panels
    PanelInfo.setup(json["panelInfo"]);
}
