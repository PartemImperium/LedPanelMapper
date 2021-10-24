#pragma once

#include <map>
#include <string>
#include "ofxDeckLinkAPIConstants.h"

class SharedDeckLinkHelpers {
    public:
        static int convertHumanReadibleDeviceId(int deviceId);
        static std::string convertDispayMode(BMDDisplayMode mode);
        static BMDDisplayMode convertDispayMode(std::string mode);
    
    private:
        static map<BMDDisplayMode,std::string> create_map()
                {
                    map<BMDDisplayMode,std::string> m;
                    
                    // SD Modes
                    m[bmdModeNTSC]     = "NTSC";
                    m[bmdModeNTSC2398] = "NTSC 3:2 Pulldown";
                    m[bmdModePAL]      = "PAL";
                    m[bmdModeNTSCp]    = "NTSCp";
                    m[bmdModePALp]     = "PALp";

                    // HD 1080 Modes
                    m[bmdModeHD1080p2398] = "1080p 23.98 fps";
                    m[bmdModeHD1080p24]   = "1080p 24 fps";
                    m[bmdModeHD1080p25]   = "1080p 25 fps";
                    m[bmdModeHD1080p2997] = "1080p 29.97 fps";
                    m[bmdModeHD1080p30]   = "1080p 30 fps";
                    m[bmdModeHD1080i50]   = "1080i 50 fps";
                    m[bmdModeHD1080i5994] = "1080i 59.94 fps";
                    m[bmdModeHD1080i6000] = "1080i 60 fps";
                    m[bmdModeHD1080p50]   = "1080p 50 fps";
                    m[bmdModeHD1080p5994] = "1080p 59.94 fps";
                    m[bmdModeHD1080p6000] = "1080p 60 fps";
                    
                    // HD 720 Modes
                    m[bmdModeHD720p50]   = "720p 50";
                    m[bmdModeHD720p5994] = "720p 59.94 fps";
                    m[bmdModeHD720p60]   = "720p 60 fps";
                    
                    // 2k Modes
                    m[bmdMode2k2398] = "2k 23.98 fps";
                    m[bmdMode2k24]   = "2k 24 fps";
                    m[bmdMode2k25]   = "2k 25 fps";
                    
                    // DCI Modes (Output Only)
                    m[bmdMode2kDCI2398] = "DCI 2k 23.98 fps";
                    m[bmdMode2kDCI24]   = "DCI 2k 24 fps";
                    m[bmdMode2kDCI25]   = "DCI 2k 25 fps";

                    // 4k Modes
                    m[bmdMode4K2160p2398] = "4k 23.98 fps";
                    m[bmdMode4K2160p24]   = "4k 24 fps";
                    m[bmdMode4K2160p25]   = "4k 25 fps";
                    m[bmdMode4K2160p2997] = "4k 29.97 fps";
                    m[bmdMode4K2160p30]   = "4k 30 fps";
                    m[bmdMode4K2160p50]   = "4k 50 fps";
                    m[bmdMode4K2160p5994] = "4k 59.94 fps";
                    m[bmdMode4K2160p60]   = "4k 60 fps";

                    // DCI Modes (Output Only)
                    m[bmdMode4kDCI2398] = "DCI 4k 23.98 fps";
                    m[bmdMode4kDCI24]   = "DCI 4k 24 fps";
                    m[bmdMode4kDCI25]   = "DCI 4k 25 fps";

                    // Special Modes
                    m[bmdModeUnknown] = "Unknown";
                    
                    return m;
                }
        static const map<BMDDisplayMode,std::string> displayModeMapping;
};
