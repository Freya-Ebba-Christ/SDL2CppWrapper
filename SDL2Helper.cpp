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

#include <SDL2Helper.h>
#include <SDL2/SDL.h>

using namespace std;

SDL2Helper::SDL2Helper() {
}

SDL2Helper::SDL2Helper(const SDL2Helper& orig) {
}

SDL2Helper::~SDL2Helper() {
}

SDL_Surface * SDL2Helper::createSurface(int width, int height, const SDL_Surface * display) {
    const SDL_PixelFormat& fmt = *(display->format);
    return SDL_CreateRGBSurface(display->flags, width, height, fmt.BitsPerPixel, fmt.Rmask, fmt.Gmask, fmt.Bmask, fmt.Amask);
}

SDL_Surface * SDL2Helper::createSurface(int width, int height, SDL_Window* window, int bitsPerPixel) {
    SDL_PixelFormat* fmt = SDL_AllocFormat(SDL_GetWindowPixelFormat(window));
    bitsPerPixel = (bitsPerPixel == fmt->BitsPerPixel) ? bitsPerPixel : fmt->BitsPerPixel;
    return SDL_CreateRGBSurface(0, width, height, bitsPerPixel, fmt->Rmask, fmt->Gmask, fmt->Bmask, fmt->Amask);
}

SDL_Surface * SDL2Helper::createSurface(int width, int height, SDL_Window* window) {
    SDL_PixelFormat* fmt = SDL_AllocFormat(SDL_GetWindowPixelFormat(window));
    return SDL_CreateRGBSurface(0, width, height, fmt->BitsPerPixel, fmt->Rmask, fmt->Gmask, fmt->Bmask, fmt->Amask);
}

Uint32 SDL2Helper::getFormat(SDL_Surface * surface) {
    return SDL_MasksToPixelFormatEnum(surface->format->BytesPerPixel * surface->format->BitsPerPixel / surface->format->BytesPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, surface->format->Amask);
}

SDL_Window* SDL2Helper::sdl_setup(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "failed to set up SDL" << endl;
        return NULL;
    }

    return SDL_CreateWindow(title,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            width, height,
            SDL_WINDOW_SHOWN);
}

SDL_Window* SDL2Helper::sdl_setup(const char* title, int x, int y, int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "failed to set up SDL" << endl;
        return NULL;
    }

    return SDL_CreateWindow(title,
            x, y,
            width, height,
            SDL_WINDOW_SHOWN);
}

SDL_Window* SDL2Helper::sdl_setup(const char* title, int x, int y, int width, int height, int windowFlags) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "failed to set up SDL" << endl;
        return NULL;
    }

    return SDL_CreateWindow(title,
            x, y,
            width, height,
            windowFlags);
}

bool SDL2Helper::draw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {
    if (Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }

    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;

    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

    return true;
}

bool SDL2Helper::fileExists(const char * filename) {
    FILE *file;
    if (file = fopen(filename, "r")) {
        fclose(file);
        return 1;
    }
    return 0;
}