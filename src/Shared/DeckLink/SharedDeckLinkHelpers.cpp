#include "SharedDeckLinkHelpers.hpp"

int SharedDeckLinkHelpers::convertHumanReadibleDeviceId(int deviceId) {
    return  deviceId - 1;
}

const std::map<BMDDisplayMode,std::string> SharedDeckLinkHelpers::displayModeMapping =  SharedDeckLinkHelpers::create_map();

std::string SharedDeckLinkHelpers::convertDispayMode(BMDDisplayMode mode) {
    return displayModeMapping.at(mode);
}

BMDDisplayMode SharedDeckLinkHelpers::convertDispayMode(std::string mode) {
    auto findResult = std::find_if(std::begin(displayModeMapping), std::end(displayModeMapping),  [&](const std::pair<BMDDisplayMode, std::string> pair)
    {
        return pair.second == mode;
    });
    
    return findResult->first;
}
