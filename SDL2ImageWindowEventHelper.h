/* 
 *    Copyright [2013] Olaf - blinky0815 - christ ]
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

#ifndef SDL2IMAGEWINDOWEVENTHELPER_H
#define	SDL2IMAGEWINDOWEVENTHELPER_H

#include <SDL2Image.h>
#include <WindowEventHandler.h>
#include <iostream>
using namespace std;

class SDL2ImageWindowEventHelper : public WindowEventhandler {
public:

    SDL2ImageWindowEventHelper() {

    }

    virtual ~SDL2ImageWindowEventHelper() {

    }

    void perform(unsigned char windowEvent){
        perform(windowEvent);
    }
    
    void onEnter() {
        cout << "SDL_WINDOWEVENT_ENTER" << endl;

    }

    void onClose() {
        cout << "SDL_WINDOWEVENT_CLOSE_blah" << endl;
    }

    void onExposed() {
        cout << "SDL_WINDOWEVENT_EXPOSED" << endl;
    }

    void onFocusGained() {
        cout << "SDL_WINDOWEVENT_FOCUS_GAINED" << endl;
    }

    void onFocusLost() {
        cout << "SDL_WINDOWEVENT_FOCUS_LOST" << endl;
    }

    void onHidden() {
        cout << "SDL_WINDOWEVENT_HIDDEN" << endl;
    }

    void onLeave() {
        cout << "SDL_WINDOWEVENT_LEAVE" << endl;
    }

    void onMaximized() {
        cout << "SDL_WINDOWEVENT_MAXIMIZED" << endl;
    }

    void onMinimized() {
        cout << "SDL_WINDOWEVENT_MINIMIZED" << endl;
    }

    void onMoved() {
        cout << "SDL_WINDOWEVENT_MOVED" << endl;
    }

    void onResized() {
        cout << "SDL_WINDOWEVENT_RESIZED" << endl;
    }

    void onRestored() {
        cout << "SDL_WINDOWEVENT_RESTORED" << endl;
    }

    void onShown() {
        cout << "SDL_WINDOWEVENT_SHOWN" << endl;
    }

    void onSizeChanged() {
        cout << "SDL_WINDOWEVENT_SIZE_CHANGED" << endl;
    }

private:
};

#endif	/* SDL2IMAGEWINDOWEVENTHELPER_H */

