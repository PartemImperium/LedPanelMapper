#include "SharedDeckLinkHelpers.hpp"

int SharedDeckLinkHelpers::convertHumanReadibleDeviceId(int deviceId) {
    return  deviceId - 1;
}
