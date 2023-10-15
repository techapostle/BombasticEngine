// src/AudioManager.cpp

#include "AudioManager.h"
#include <iostream>
#include <AL/alut.h>

namespace BombasticEngine {

  // Constructor implementation.
  AudioManager::AudioManager() : device(nullptr), context(nullptr) {}

  // Destructor implementation.
  AudioManager::~AudioManager() {
    // Cleanup resources.
    for (auto& pair : soundSources) {
      alDeleteSources(1, &pair.second);
    }
    for (auto& pair : soundBuffers) {
      alDeleteBuffers(1, &pair.second);
    }
    alcMakeContextCurrent(nullptr);
    alcDestroyContext(context);
    alcCloseDevice(device);
  }

  // Initialize implementation.
  bool AudioManager::initialize() {
    if (!alutInitWithoutContext(nullptr, nullptr)) {
      std::cerr << "Failed to initialize ALUT: " << alutGetErrorString(alutGetError()) << std::endl;
      return false;
    }
    device = alcOpenDevice(nullptr);
    if (!device) {
      std::cerr << "Failed to open OpenAL device!" << std::endl;
      return false;
    }
    context = alcCreateContext(device, nullptr);
    if (!context) {
      std::cerr << "Failed to create OpenAL context!" << std::endl;
      return false;
    }
    alcMakeContextCurrent(context);
    return true;
  }

  // loadSound implementation.
  bool AudioManager::loadSound(const std::string& id, const std::string& filePath) {
    ALuint buffer;
    ALenum format;
    ALvoid* data;
    ALsizei size;
    ALfloat freq;
    ALboolean loop;

    // Load WAV file using ALUT.
    alGenBuffers(1, &buffer);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) {
      std::cerr << "Failed to generate OpenAL buffer: " << alGetString(error) << std::endl;
      return false;
    }

    data = alutLoadMemoryFromFile(filePath.c_str(), &format, &size, &freq);
    if (!data) {
      std::cerr << "Failed to load sound file " << filePath << "!" << std::endl;
      return false;
    }

    alBufferData(buffer, format, data, size, static_cast<ALsizei>(freq));
    error = alGetError();
    if (error != AL_NO_ERROR) {
      std::cerr << "Failed to load sound file " << filePath << " into OpenAL buffer: " << alGetString(error) << std::endl;
      return false;
    }
    // alutUnloadMemory(data, size, freq);
    free(data);

    // Generate a source for the sound.
    ALuint source;
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);

    soundBuffers[id] = buffer;
    soundSources[id] = source;

    return true;
  }

  // playSound implementation.
  void AudioManager::playSound(const std::string& id, bool loop) {
    ALuint source = soundSources[id];
    alSourcei(source, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
    alSourcePlay(source);
  }

  // stopSound implementation.
  void AudioManager::stopSound(const std::string& id) {
    ALuint source = soundSources[id];
    alSourceStop(source);
  }

  // pauseSound implementation.
  void AudioManager::pauseSound(const std::string& id) {
    ALuint source = soundSources[id];
    alSourcePause(source);
  }

  // setVolume implementation.
  void AudioManager::setVolume(const std::string& id, float volume) {
    ALuint source = soundSources[id];
    alSourcef(source, AL_GAIN, volume);
  }

  // setPitch implementation.
  void AudioManager::setPitch(const std::string& id, float pitch) {
    ALuint source = soundSources[id];
    alSourcef(source, AL_PITCH, pitch);
  }

  // setPosition implementation.
  void AudioManager::setPosition(const std::string& id, float x, float y, float z) {
    ALuint source = soundSources[id];
    alSource3f(source, AL_POSITION, x, y, z);
  }

  // setVelocity implementation.
  void AudioManager::setVelocity(const std::string& id, float x, float y, float z) {
    ALuint source = soundSources[id];
    alSource3f(source, AL_VELOCITY, x, y, z);
  }

  // setListenerPosition implementation.
  void AudioManager::setListenerPosition(float x, float y, float z) {
    alListener3f(AL_POSITION, x, y, z);
  }

  // setListenerVelocity implementation.
  void AudioManager::setListenerVelocity(float x, float y, float z) {
    alListener3f(AL_VELOCITY, x, y, z);
  }

  // setListenerOrientation implementation.
  void AudioManager::setListenerOrientation(float atX, float atY, float atZ, float upX, float upY, float upZ) {
    ALfloat orientation[] = { atX, atY, atZ, upX, upY, upZ };
    alListenerfv(AL_ORIENTATION, orientation);
  }

} // namespace BombasticEngine