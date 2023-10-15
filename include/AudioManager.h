// include/InputManager.h

#pragma once

#include <AL/al.h>
#include <AL/alc.h>
#include <string>
#include <map>

namespace BombasticEngine {
  class AudioManager {
    public:
      /**
       * @brief Construct a new Audio Manager object
      */
      AudioManager();
      /**
       * @brief Destroy the Audio Manager object
      */
      ~AudioManager();

      /**
       * @brief Initialize the audio manager.
       * 
       * @return true 
       * @return false 
       */
      bool initialize();
      /**
       * @brief Load a sound file into the audio manager.
       * 
       * @param id The id of the sound.
       * @param filePath The file path to the sound file.
      */
      bool loadSound(const std::string& id, const std::string& filePath);
      /**
       * @brief Play a loaded sound with the specified id.
       * 
       * @param id The id of the sound.
       * @param loop Whether the sound should loop or not.
      */
      void playSound(const std::string& id, bool loop = false);
      /**
       * @brief Stop a loaded sound with the specified id.
       * 
       * @param id The id of the sound.
      */
      void stopSound(const std::string& id);
      /**
       * @brief Pause a loaded sound with the specified id.
       * 
       * @param id The id of the sound.
      */
      void pauseSound(const std::string& id);

      /**
       * @brief Set the volume of a loaded sound with the specified id.
       * 
       * @param id The id of the sound.
       * @param volume The volume of the sound.
      */
      void setVolume(const std::string& id, float volume); // volume range: 0.0 (mute) to 1.0 (max)
      /**
       * @brief Set the pitch of a loaded sound with the specified id.
       * 
       * @param id The id of the sound.
       * @param pitch The pitch of the sound.
      */
      void setPitch(const std::string& id, float pitch);   // default pitch is 1.0
      /**
       * @brief Set the position of a loaded sound with the specified id.
       * 
       * @param id The id of the sound.
       * @param x The x position of the sound.
       * @param y The y position of the sound.
       * @param z The z position of the sound.
      */
      void setPosition(const std::string& id, float x, float y, float z);
      /**
       * @brief Set the velocity of a loaded sound with the specified id.
       * 
       * @param id The id of the sound.
       * @param x The x velocity of the sound.
       * @param y The y velocity of the sound.
       * @param z The z velocity of the sound.
      */
      void setVelocity(const std::string& id, float x, float y, float z);
      /**
       * @brief Set the orientation of a loaded sound with the specified id.
       * 
       * @param id The id of the sound.
       * @param atX The x position of the sound.
       * @param atY The y position of the sound.
       * @param atZ The z position of the sound.
       * @param upX The x up vector of the sound.
       * @param upY The y up vector of the sound.
       * @param upZ The z up vector of the sound.
      */
      void setListenerPosition(float x, float y, float z);
      /**
       * @brief Set the velocity of the listener.
       * 
       * @param x The x velocity of the listener.
       * @param y The y velocity of the listener.
       * @param z The z velocity of the listener.
      */
      void setListenerVelocity(float x, float y, float z);
      /**
       * @brief Set the orientation of the listener.
       * 
       * @param atX The x position of the listener.
       * @param atY The y position of the listener.
       * @param atZ The z position of the listener.
       * @param upX The x up vector of the listener.
       * @param upY The y up vector of the listener.
       * @param upZ The z up vector of the listener.
      */
      void setListenerOrientation(float atX, float atY, float atZ, float upX, float upY, float upZ);

    private:
      ALCdevice* device; // The audio device.
      ALCcontext* context; // The audio context.
      std::map<std::string, ALuint> soundBuffers; // Map of sound ids to their corresponding buffers.
      std::map<std::string, ALuint> soundSources; // Map of sound ids to their corresponding sources.
  };
} // namespace BombasticEngine