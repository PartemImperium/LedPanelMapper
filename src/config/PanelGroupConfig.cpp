#include "PanelGroupConfig.hpp"

void PanelGroupConfig::setup(ofxJSONElement json) {
    setName("Panel Info");
    
    PanelWidth.set("Panel Width", json["panelWidth"].asInt(), 0, 512);// TODO: Figure out what to put for max value
    add(PanelWidth);
    
    PanelHeight.set("Panel Height",json["panelHeight"].asInt(),0,512);// TODO: Figure out what to put for the max value
    add(PanelHeight);
    
    
    PanelsToFillWidth.set("Number of Panels to Fill Width", json["panelsToFillWidth"].asInt(), 1, 32);// TODO: Figure out what to put for the max value
    add(PanelsToFillWidth);
    
    PanelsToFillHeight.set("Number of Panels to Fill Height", json["panelsToFillHeight"].asInt(),1,32);// TODO: Figure out what to put for the max value
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
