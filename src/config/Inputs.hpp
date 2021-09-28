#ifndef Inputs_hpp
#define Inputs_hpp

#include <stdio.h>

#endif /* Inputs_hpp */
#include "VideoPlayerInput.hpp"
#include "SyphonInput.hpp"
#include "NdiInput.hpp"

class Inputs {
    public:
        VideoPlayerInput VideoPlayer;
        SyphonInput Syphon;
        NdiInput Ndi;
};
