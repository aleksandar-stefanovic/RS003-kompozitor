#include "microphone_recorder.hpp"
#include <iostream>
#include <chrono>

MicrophoneRecorder &MicrophoneRecorder::get_instance() {
    static MicrophoneRecorder instance;
    return instance;
}

void MicrophoneRecorder::start_recording() {
    _recorder.start();
}

sf::SoundBuffer MicrophoneRecorder::stop_recording() {
    _recorder.stop();
    sf::SoundBuffer buffer = _recorder.getBuffer();
    return buffer;
}

void MicrophoneRecorder::save_recording(const std::string& file_name) {
    sf::SoundBuffer buffer = _recorder.getBuffer();
    buffer.saveToFile(file_name);
}

