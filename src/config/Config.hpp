#pragma once
#ifndef config_hpp
#define config_hpp

#include <stdio.h>

#endif /* config_hpp */
#include <string>
#include "ofxJSONElement.h"
#include "Panel.hpp"

class Config {
    public:
        std::string SyphonApplication;
        std::string SyphonServer;
        
        std::vector<Panel> Panels;

        void setup(ofxJSONElement json);
        Config();
};
