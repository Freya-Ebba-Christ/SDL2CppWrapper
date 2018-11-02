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

#ifndef SDL2SOUNDHOOK_H
#define SDL2SOUNDHOOK_H

class SDL2SoundSystem;

class SDL2SoundHook {
public:

    SDL2SoundHook() {
    }

    virtual void execute(SDL2SoundSystem* soundSystem, Uint8 *_stream, int _len) {
        std::cout << "overload me" << std::endl;
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

    virtual ~SDL2SoundHook() {
    }

private:
    int index;
    bool active;
};

#endif /* SDL2SOUNDHOOK_H */

