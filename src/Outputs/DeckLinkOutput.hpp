#pragma once

#include "BaseOutput.hpp"

#include "ofxDeckLink.h"

class DeckLinkOutput: public BaseOutput {
    public:
        DeckLinkOutput() {};
        virtual ~DeckLinkOutput() {};
    
        virtual void setup(Config config);
        virtual void draw(ofFbo output);
    
        virtual std::string OutputName();

    private:
        Config c;
        ofxDeckLinkAPI::Output deckLinkOut;
};
