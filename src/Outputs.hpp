#ifndef Outputs_hpp
#define Outputs_hpp

#include <stdio.h>

#endif /* Outputs_hpp */
#include "SyphonOutput.hpp"
#include "NdiOutput.hpp"

class Outputs {
    public:
        SyphonOutput Syphon;
        NdiOutput Ndi;
};
