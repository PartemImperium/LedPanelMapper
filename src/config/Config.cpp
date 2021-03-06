#include "Config.hpp"
#include "PanelConfig.hpp"

Config::Config() {}

void Config::setup(ofxJSONElement json) {
    setName("Configuration");
    
	// Inputs
	Inputs.setup(json["inputs"]);

	// Outputs
	Outputs.setup(json["outputs"]);

	// Panels
    PanelInfo.setup(json["panelInfo"]);
    add(PanelInfo);
    
    saveE.addListener(this, &Config::save);
    saveE.set("Save Config");
}

void Config::save() {
    ofxJSONElement json;
    
    json["panelInfo"] = PanelInfo.getJson();
            
    json.save("temp.json", true);
}
