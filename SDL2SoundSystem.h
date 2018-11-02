/* 
 *    Copyright [2016] Olaf - blinky0815 - christ ]
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 * 
 * Author: blinky0815
 * email: christ_o@gmx.de
 */

#ifndef SDL2SOUNDSYSTEM_H
#define SDL2SOUNDSYSTEM_H

#include <SDL2/SDL.h>
#include <SDL_thread.h>
#include <SDL_mixer.h>
#include <iostream>
#include <vector>
#include <list>
#include <ringbuffer.h>
#include <SDL2PostMix.h>
#include <SDL2SoundHook.h>
#include <functional>
#include <readerwriterqueue.h>

class SDL2SoundSystem {
public:

    SDL2SoundSystem() {
        if (SDL_Init(SDL_INIT_AUDIO) < 0) {
            std::cout << "SDL could not initialize! SDL Error " << SDL_GetError() << std::endl;
        }
    }

    virtual ~SDL2SoundSystem() {
        Mix_FreeChunk(chunk);
        Mix_FreeMusic(music);
        SDL_CloseAudio();
    }

    void init(int frequency, Uint16 format, int channels, int chunksize, int flags, int bytesPerSample = 2) {
        this->frequency = frequency;
        this->format = format;
        this->channels = channels;
        this->chunksize = chunksize;
        this->flags = flags;
        this->bytesPerSample = bytesPerSample;
        if (Mix_OpenAudio(frequency, format, channels, chunksize) < 0) {
            std::cout << "Mix_OpenAudio() failed" << std::endl;
        }

        if (Mix_Init(flags) < 0) {
            std::cout << "unable to load libraries using Mix_Init" << std::endl;
        }

        //initialize all postMixers
        for (int i = 0; i < postMixers.size(); i++) {
            postMixers.at(i).get().initialize(channels, chunksize, bytesPerSample);
        }

        Mix_SetPostMix(postmix, this);
    }

    int getBytesPerSample() {
        return this->bytesPerSample;
    }

    void stopChannel(int channel) {
        Mix_HaltChannel(channel);
    }

    void stopMusic() {
        Mix_HaltMusic();
    }

    void rewindMusic() {
        Mix_RewindMusic();
    }

    void resumeMusic() {
        Mix_ResumeMusic();
    }

    void resumeChannel(int channel) {
        Mix_Resume(channel);
    }

    void pauseChannel(int channel) {
        Mix_Pause(channel);
    }

    void pauseMusic() {
        Mix_PauseMusic();
    }

    void playMusic(int loops) {
        Mix_PlayMusic(music, loops);
    }

    void playChunk() {
        Mix_PlayChannel(-1, chunk, 1);
    }

    void loadMusic(std::string filename) {
        music = Mix_LoadMUS(filename.c_str());
        if (music == nullptr) {
            std::cout << "unable to load: " << filename << std::endl;
        }
    }

    void loadChunk(std::string filename) {
        chunk = Mix_LoadWAV(filename.c_str());
        if (chunk == nullptr) {
            std::cout << "unable to load: " << filename << std::endl;
        }
    }

    int getFrequency() {
        return this->frequency;
    }

    Uint16 getFormat() {
        return this->format;
    }

    int getChannels() {
        return this->channels;
    }

    int getChunkSize() {
        return this->chunksize;
    }

    int getFlags() {
        return this->flags;
    }

    void addPostMixer(SDL2PostMix& value) {
        this->postMixers.push_back(value);
    }

    void eraseLastPostMixer() {
        postMixers.erase(postMixers.end());
    }

    void eraseFirstPostMixer() {
        postMixers.erase(postMixers.begin());
    }

    void clearPostMixers() {
        postMixers.clear();
    }

    void erasePostMixer(int index) {
        postMixers.erase(postMixers.begin() + index);
    }

    int numberOfPostMixers() {
        return this->postMixers.size();
    }

    ////////////////////////////////////////

    void addSoundHook(SDL2SoundHook& value) {
        this->soundHooks.push_back(value);
    }

    void eraseLastSoundHook() {
        soundHooks.erase(soundHooks.end());
    }

    void eraseFirstSoundHook() {
        soundHooks.erase(soundHooks.begin());
    }

    void clearSoundHooks() {
        soundHooks.clear();
    }

    void eraseSoundHook(int index) {
        soundHooks.erase(soundHooks.begin() + index);
    }

    int numberOfSoundHooks() {
        return this->soundHooks.size();
    }

private:

    static void postmix(void *udata, Uint8 *_stream, int _len) {
        SDL2SoundSystem* soundSystem = (SDL2SoundSystem*) udata;
        int item;
        for (int i = 0; i < soundSystem->postMixers.size(); i++) {
            soundSystem->postMixers.at(i).get().execute(soundSystem, _stream, _len);
            for (int n = 0; n < soundSystem->postMixers.at(i).get().getSamples().size(); n++) {
                soundSystem->postMixers.at(i).get().getSamples().at(n);
            }

            /*
            for (int n = 0; n < soundSystem->postMixers.at(i).get().getQueue().size_approx(); n++) {
                soundSystem->postMixers.at(i).get().getQueue().wait_dequeue(item);
                //cout << "item " << item << endl;
            }
             */
        }
    }

    static void hook(void *udata, Uint8 *_stream, int _len) {
        SDL2SoundSystem* soundSystem = (SDL2SoundSystem*) udata;
        for (int i = 0; i < soundSystem->soundHooks.size(); i++) {
            soundSystem->soundHooks.at(i).get().execute(soundSystem, _stream, _len);
        }
    }

    int frequency;
    Uint16 format;
    int channels;
    int chunksize;
    int flags;
    int bytesPerSample;
    Mix_Music *music = nullptr;
    Mix_Chunk *chunk = nullptr;
    std::vector<std::reference_wrapper < SDL2PostMix>> postMixers;
    std::vector<std::reference_wrapper < SDL2SoundHook >> soundHooks;
};

#endif /* SDL2SOUNDSYSTEM_H */

