#include "VideoPlayerInput.hpp"

void VideoPlayerInput::setup(Config config) {
    c = config;
    videoPlayer.load(c.Inputs.VideoPlayer.FilePath);
    videoPlayer.play();
}

void VideoPlayerInput::draw() {
    videoPlayer.draw(0,0);
}

void VideoPlayerInput::update() {
    videoPlayer.update();
}
