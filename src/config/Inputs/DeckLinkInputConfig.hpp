#pragma once

#include <string>

class DeckLinkInputConfig {
    public:
        bool IsInputEnabled;
        int DeviceId;
        std::string VideoMode;
};
