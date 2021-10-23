#include "PanelCalculations.hpp"

ofRectangle PanelCalculations::getDestination() {
    return ofRectangle(destinationX, destinationY, destinationWidth, destinationHeight);
}

ofRectangle PanelCalculations::getSource() {
    return ofRectangle(sourceX, sourceY, sourceWidth, sourceHeight);
}


void PanelCalculations::draw(ofTexture& texture) {
    texture.drawSubsection(getDestination(), getSource());
}
