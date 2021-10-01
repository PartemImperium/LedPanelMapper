#include "PanelCalculations.hpp"

void PanelCalculations::draw(ofTexture& texture) {
    texture.drawSubsection(destinationX, destinationY, destinationWidth, destinationHeight, sourceX, sourceY, sourceWidth, sourceHeight);
}
