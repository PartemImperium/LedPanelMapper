#pragma once

#include "ofxDeckLink.h"

#include "Config.hpp"
#include "BaseInput.hpp"

#include "SharedDeckLinkHelpers.hpp"

class DeckLinkInput: public BaseInput {
    public:
        DeckLinkInput() {};
        virtual ~DeckLinkInput() {};
    
        virtual void setup(Config *config);
        virtual void draw();
        virtual void update();
        virtual std::string InputName();
        virtual ofTexture getTexture();

    private:
        ofxDeckLinkAPI::Input deckLinkInput;
        std::string name;
};
