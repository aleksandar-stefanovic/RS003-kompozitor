#include <playback/sound_manager.hpp>
#include <src/playback/record_manager.hpp>
#include <utility>
#include "main_model.hpp"
#include "playback/playback.hpp"
#include <iostream>

#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection" // Qt uses this function
#pragma ide diagnostic ignored "MemberFunctionCanBeStatic"
void MainModel::playSomething() {
    Playback::play(timer);
}

void MainModel::recordSomething() {
    Playback::record();
}

void MainModel::playNote(float frequency) {
    SoundManager::get_instance().add_note(frequency);
}

void MainModel::stopNote(float frequency) {
    SoundManager::get_instance().remove_note(frequency);
}

void MainModel::MyTimerSlot() {
    Playback::my_timer_slot();
}

void MainModel::startRecording() {
    _isRecording = true;
    RecordManager::get_instance().start_recording();
    emit isRecordingChanged();
}

void MainModel::stopRecording() {
    _isRecording = false;
    RecordManager::get_instance().stop_recording();
    emit isRecordingChanged();
}

QList<Track *> MainModel::tracks() const {
    return _tracks;
}

void MainModel::set_tracks(QList<Track *> tracks) {
    _tracks = std::move(tracks);
    emit onTracksChanged();
}

void MainModel::addMicrophoneTrack() {
    _tracks.push_back(new Track(2, Track::MICROPHONE, {
            new TrackNote(3, 0, 2),
            new TrackNote(10, 0, 3),
            new TrackNote(7, 4, 10),
    }));
    emit onTracksChanged();
}

void MainModel::addKeyboardTrack() {
    _tracks.push_back(new Track(2, Track::KEYBOARD, {
            new TrackNote(3, 0, 2),
            new TrackNote(10, 0, 3),
            new TrackNote(7, 4, 10),
    }));
    emit onTracksChanged();
}

void MainModel::octaveChanged(QString octave) {
    std::string octaveString = octave.toStdString();

    if (!std::isdigit(octaveString[0])) {
        std::cout << "Non valid entry!" << std::endl;
        return;
    }
    int octaveNumber = std::stoi(octaveString);
    if (octaveNumber < 0 || octaveNumber > 8) {
        std::cout << "Non valid entry!" << std::endl;
        return;
    }
    std::cout << octaveNumber << std::endl;
}
