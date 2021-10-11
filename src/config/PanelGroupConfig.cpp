#include "PanelGroupConfig.hpp"

void PanelGroupConfig::setup(ofxJSONElement json) {
    setName("Panel Info");
    
    PanelWidth = json["panelWidth"].asInt();
    PanelWidth.setName("Panel Width");
    PanelWidth.setMin(0);
    PanelWidth.setMax(512);// TODO: Figure out what to put for max value
    
    add(PanelWidth);
    
    PanelHeight = json["panelHeight"].asInt();
    PanelHeight.setName("Panel Height");
    PanelHeight.setMin(0);
    PanelHeight.setMax(512);// TODO: Figure out what to put for the max value
    add(PanelHeight);
    
    
    PanelsToFillWidth = json["panelsToFillWidth"].asInt();
    PanelsToFillWidth.setName("Number of Panels to Fill Width");
    PanelsToFillWidth.setMin(1);
    PanelsToFillWidth.setMax(32);// TODO: Figure out what to put for the max value
    add(PanelsToFillWidth);
    
    PanelsToFillHeight = json["panelsToFillHeight"].asInt();
    PanelsToFillHeight.setName("Number of Panels to Fill Height");
    PanelsToFillHeight.setMin(1);
    PanelsToFillHeight.setMax(32);// TODO: Figure out what to put for the max value
    add(PanelsToFillHeight);
    
	ofxJSONElement panels = json["panels"];
	for (int i = 0; i < panels.size(); i++) {
		PanelConfig p;
        p.setup(panels[i], i);
        add(p);

		Panels.push_back(p);
	}
}

ofxJSONElement PanelGroupConfig::getJson() {
    ofxJSONElement json;
    
    json["panelWidth"] = PanelWidth.get();
    json["panelHeight"] = PanelHeight.get();
    
    json["panelsToFillWidth"] = PanelsToFillWidth.get();
    json["panelsToFillHeight"] = PanelsToFillHeight.get();
    
    ofxJSONElement panelsJson;
    for (int i = 0; i < Panels.size(); i++) {
        panelsJson[i] = Panels[i].getJson();
        panelsJson[i].setComment("//Panel " + std::to_string(i + 1), Json::commentBefore);
    }
    json["panels"] = panelsJson;
    
    return json;
}
