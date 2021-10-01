#include "VideoPlayerInput.hpp"

std::string VideoPlayerInput::InputName() {
    return "Video Player";
}

void VideoPlayerInput::setup(Config config) {
    c = config;
    videoPlayer.load(c.Inputs.VideoPlayer.FilePath);
    videoPlayer.setVolume(0);
    videoPlayer.play();
}

void VideoPlayerInput::draw() {
    videoPlayer.draw(0,0);
}

void VideoPlayerInput::update() {
    videoPlayer.update();
}
