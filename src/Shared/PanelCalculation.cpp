#include "PanelCalculation.hpp"

ofRectangle PanelCalculation::getDestination() {
    return ofRectangle(destinationX, destinationY, destinationWidth, destinationHeight);
}

ofRectangle PanelCalculation::getSource() {
    return ofRectangle(sourceX, sourceY, sourceWidth, sourceHeight);
}


void PanelCalculation::draw(ofTexture& texture) {
    texture.drawSubsection(getDestination(), getSource());
}
