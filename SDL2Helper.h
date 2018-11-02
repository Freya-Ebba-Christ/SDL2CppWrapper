/* 
 *    Copyright [2012] Olaf - blinky0815 - christ ]
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

#ifndef SDL2HELPER_H
#define SDL2HELPER_H

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <string>
#include <common.h>
#include <SDL2_gfxPrimitives.h>

class SDL2Helper {
public:
    SDL2Helper();
    SDL2Helper(const SDL2Helper& orig);
    virtual ~SDL2Helper();

    SDL_Window* sdl_setup(const char* title, int width, int height);
    SDL_Window* sdl_setup(const char* title, int x, int y, int width, int height);
    SDL_Window* sdl_setup(const char* title, int x, int y, int width, int height, int windowFlags);
    SDL_Surface* createSurface(int width, int height, const SDL_Surface* display);
    SDL_Surface* createSurface(int width, int height, SDL_Window* window);
    SDL_Surface* createSurface(int width, int height, SDL_Window* window, int bitsPerPixel);
    Uint32 getFormat(SDL_Surface * surface);
    bool draw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
    bool fileExists(const char * filename);

private:
};

#endif