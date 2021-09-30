#pragma once

#include "SyphonOutputConfig.hpp"
#include "NdiOutputConfig.hpp"
#include "DeckLinkOutputConfig.hpp"

class OutputsConfig {
    public:
        SyphonOutputConfig Syphon;
        NdiOutputConfig Ndi;
        DeckLinkOutputConfig DeckLink;
};
