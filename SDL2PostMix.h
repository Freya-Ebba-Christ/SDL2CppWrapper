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

#ifndef SDL2POSTMIX_H
#define SDL2POSTMIX_H
#include <iostream>
#include <thread>

class SDL2SoundSystem;

using namespace std;

class SDL2PostMix {
public:

    SDL2PostMix() : active(false) {
    }

    void initialize(int channels, int chunksize, int bytesPerSample = 2) {
        this->channels = channels;
        this->chunksize = chunksize;
        this->bytesPerSample = bytesPerSample;
        samples.resize(chunksize / bytesPerSample, 0);
    }

    int getBytesPerSample() {
        return this->bytesPerSample;
    }

    int getChunkSize() {
        return this->chunksize;
    }

    int getChannels() {
        return this->channels;
    }

    virtual void execute(SDL2SoundSystem* soundSystem, Uint8 *_stream, int _len) {
        Uint16* streamPtr = (Uint16*) _stream;
        const int length = _len / this->bytesPerSample;
        std::copy(streamPtr, streamPtr + length, samples.begin());
    }

    void setActive(bool value) {
        this->active = value;
    }

    bool isActive() {
        return this->active;
    }

    void setIndex(int value) {
        this->index = value;
    }

    int getIndex() {
        return this->index;
    }

    virtual ~SDL2PostMix() {
    }

    const vector<uint16_t>& getSamples() {
        return samples;
    }

private:
    int index;
    bool active;
    vector<uint16_t> samples;
    int channels;
    int chunksize;
    int bytesPerSample;
};

#endif /* SDL2POSTMIX_H */

