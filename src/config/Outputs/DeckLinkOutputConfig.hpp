#pragma once

#include <string>

class DeckLinkOutputConfig {
    public:
        bool IsOutputEnabled;
        int DeviceId;
        unsigned int VideoMode;//TODO: Figure out how to make this a string again... The values are using 'Hp59' which somehow converts to unsigned int
};
