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
 * handles SDL window events:
 * 
 *      SDL_WINDOWEVENT_CLOSE
        SDL_WINDOWEVENT_ENTER
        SDL_WINDOWEVENT_EXPOSED
        SDL_WINDOWEVENT_FOCUS_GAINED
        SDL_WINDOWEVENT_FOCUS_LOST
        SDL_WINDOWEVENT_HIDDEN
        SDL_WINDOWEVENT_LEAVE
        SDL_WINDOWEVENT_MAXIMIZED
        SDL_WINDOWEVENT_MINIMIZED
        SDL_WINDOWEVENT_MOVED
        SDL_WINDOWEVENT_RESIZED
        SDL_WINDOWEVENT_RESTORED
        SDL_WINDOWEVENT_SHOWN
        SDL_WINDOWEVENT_SIZE_CHANGED
 * Created on December 30, 2013, 12 : 05 PM
 */

#ifndef WINDOWEVENTHANDLER_H
#define WINDOWEVENTHANDLER_H
#include <iostream>
#include <SDL2Eventhandler.h>
#include <SDL2/SDL_events.h>

using namespace std;

class WindowEventhandler : public SDL2Eventhandler {
public:

    WindowEventhandler() {
    }

    ~WindowEventhandler() {
    }

    void perform(SDL_Event& event) {
        if (event.window.windowID == getWindowID()) {
            switch (event.window.event) {
                case SDL_WINDOWEVENT_CLOSE:
                {
                    onClose();

                }
                    break;
                case SDL_WINDOWEVENT_ENTER:
                {
                    onEnter();
                }
                    break;
                case SDL_WINDOWEVENT_EXPOSED:
                {
                    onExposed();
                }
                case SDL_WINDOWEVENT_FOCUS_GAINED:
                {
                    onFocusGained();
                }
                    break;
                case SDL_WINDOWEVENT_FOCUS_LOST:
                {
                    onFocusLost();
                }
                    break;
                case SDL_WINDOWEVENT_HIDDEN:
                {
                    onHidden();
                }
                    break;
                case SDL_WINDOWEVENT_LEAVE:
                {
                    onLeave();
                }
                case SDL_WINDOWEVENT_MAXIMIZED:
                {
                    onMaximized();
                }
                    break;
                case SDL_WINDOWEVENT_MINIMIZED:
                {
                    onMinimized();
                }
                case SDL_WINDOWEVENT_MOVED:
                {
                    onMoved();
                }
                    break;
                case SDL_WINDOWEVENT_RESIZED:
                {
                    onResized();
                }
                    break;
                case SDL_WINDOWEVENT_RESTORED:
                {
                    onRestored();
                }
                    break;
                case SDL_WINDOWEVENT_SHOWN:
                {
                    onShown();
                }
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                {
                    onSizeChanged();
                }
                    break;
            }
        }
    }

    virtual void onEnter() {
        cout << "SDL_WINDOWEVENT_ENTER" << endl;
    }

    virtual void onClose() {
        cout << "SDL_WINDOWEVENT_CLOSE" << endl;
    }

    virtual void onExposed() {
        cout << "SDL_WINDOWEVENT_EXPOSED" << endl;
    }

    virtual void onFocusGained() {
        cout << "SDL_WINDOWEVENT_FOCUS_GAINED" << endl;
    }

    virtual void onFocusLost() {
        cout << "SDL_WINDOWEVENT_FOCUS_LOST" << endl;
    }

    virtual void onHidden() {
        cout << "SDL_WINDOWEVENT_HIDDEN" << endl;
    }

    virtual void onLeave() {
        cout << "SDL_WINDOWEVENT_LEAVE" << endl;
    }

    virtual void onMaximized() {
        cout << "SDL_WINDOWEVENT_MAXIMIZED" << endl;
    }

    virtual void onMinimized() {
        cout << "SDL_WINDOWEVENT_MINIMIZED" << endl;
    }

    virtual void onMoved() {
        cout << "SDL_WINDOWEVENT_MOVED" << endl;
    }

    virtual void onResized() {
        cout << "SDL_WINDOWEVENT_RESIZED" << endl;
    }

    virtual void onRestored() {
        cout << "SDL_WINDOWEVENT_RESTORED" << endl;
    }

    virtual void onShown() {
        cout << "SDL_WINDOWEVENT_SHOWN" << endl;
    }

    virtual void onSizeChanged() {
        cout << "SDL_WINDOWEVENT_SIZE_CHANGED" << endl;
    }
private:

};

#endif /* WINDOWEVENTHANDLER_H */

