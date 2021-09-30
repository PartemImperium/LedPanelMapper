#pragma once

#include "ofxDeckLink.h"

#include "Config.hpp"
#include "BaseInput.hpp"

class DeckLinkInput: public BaseInput {
    public:
        virtual void setup(Config config);
        virtual void draw();
        virtual void update();
        virtual std::string InputName();

    private:
        Config c;
        ofxDeckLinkAPI::Input deckLinkInput;
};
