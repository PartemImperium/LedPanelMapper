#pragma once

#include <string>

class DeckLinkOutputConfig {
    public:
        bool IsOutputEnabled;
        int DeviceId;
        std::string VideoMode;
};
