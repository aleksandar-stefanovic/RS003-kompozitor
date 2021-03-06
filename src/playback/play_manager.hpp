#ifndef KOMPOZITOR_PLAY_MANAGER_HPP
#define KOMPOZITOR_PLAY_MANAGER_HPP


#include <src/ui_model/track.hpp>
#include <SFML/Audio/Sound.hpp>
#include <cmath>
#include <src/ui_model/note_track.hpp>
#include <src/ui_model/sample_track.hpp>

#define FIXED_OCTAVE 4

class PlayManager {
public:
    [[nodiscard]]
    static PlayManager& get_instance();

    PlayManager(const PlayManager& other) = delete;
    PlayManager& operator=(const PlayManager& other) = delete;
    PlayManager(PlayManager&& other) = delete;
    PlayManager& operator=(PlayManager&& other) = delete;

    void play(int index);
    void stop(int index);
    void pause(int index);
    void add(int index, Track * track);

private:
    PlayManager() = default;
    std::map<int, std::pair<sf::Sound, sf::SoundBuffer>> sound_data;
    const std::vector<double> main_octave_frequencies {261.63, 277.18, 293.66, 311.13,
                                                       329.63, 349.23, 369.99, 392.00,
                                                       415.30, 440.00, 466.16, 493.88, 523.25};
    float pitch_to_frequency(int pitch);
    void createKeyboardSound(int index, NoteTrack *note_track);
    void createVoiceSound(int index, SampleTrack *sample_track);
};


#endif //KOMPOZITOR_PLAY_MANAGER_HPP
