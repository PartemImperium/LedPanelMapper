#pragma once

#include "ofxDeckLink.h"

#include "Config.hpp"
#include "BaseInput.hpp"

class DeckLinkInput: public BaseInput {
    public:
        DeckLinkInput() {};
        virtual ~DeckLinkInput() {};
    
        virtual void setup(Config *config);
        virtual void draw();
        virtual void update();
        virtual std::string InputName();

    private:
        ofxDeckLinkAPI::Input deckLinkInput;
};
