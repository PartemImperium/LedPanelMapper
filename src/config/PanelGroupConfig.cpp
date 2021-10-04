#include "PanelGroupConfig.hpp"

void PanelGroupConfig::setup(ofxJSONElement json) {
    PanelWidth = json["panelWidth"].asInt();
    PanelHeight = json["panelHeight"].asInt();

    PanelsToFillWidth = json["panelsToFillWidth"].asInt();
    PanelsToFillHeight = json["panelsToFillHeight"].asInt();
    
	ofxJSONElement panels = json["panels"];
	for (int i = 0; i < panels.size(); i++) {
		PanelConfig p;
        p.setup(panels[i]);

		Panels.push_back(p);
	}
}