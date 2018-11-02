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

#ifndef SDL2FPSCOUNTER_H
#define SDL2FPSCOUNTER_H

#include <ringbuffer.h>

class SDL2FPSCounter {
public:

    SDL2FPSCounter() {
        frameTimes.setSize(300);
        frameTimes.initialize();
    }

    SDL2FPSCounter(int numberOfFrames) {
        frameTimes.setSize(numberOfFrames);
        frameTimes.initialize();
    }

    void init() {
        frameTimes.addElement(SDL_GetTicks());
    }

    float measure() {
        float currentTime = SDL_GetTicks();
        float deltaTime = currentTime - lastTime;
        float fps = 1000.0f / deltaTime;
        frameTimes.addElement(deltaTime);
        lastTime = currentTime;
        return fps;
    }

    virtual ~SDL2FPSCounter() {
    }

    float getMeanFrameTime() {
        return frameTimes.getMean();
    }

private:
    RingBuffer<float> frameTimes;
    float lastTime = 0.0f;
};

#endif /* SDL2FPSCOUNTER_H */

