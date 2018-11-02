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
#ifndef SDL2IMAGE_H
#define SDL2IMAGE_H

#include <SDL2/SDL.h>
#include <observable.h>
#include <SDL2Helper.h>
#include <SDL_timer.h>
#include <SDL2_rotozoom.h>
#include <WindowEventHandler.h>
#include <SDLU.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>
using namespace std;

class SDL2Image : public Observable {
public:

    SDL2Image(const char* title, int x, int y, int width, int height) : windowTitle(title), x_position(x), y_position(y), width(width), height(height) {
        window = sdl2Helper.sdl_setup(this->windowTitle, this->x_position, this->y_position, this->width, this->height);
        rasterImage = sdl2Helper.createSurface(this->width, this->height, this->window);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        texture = SDL_CreateTexture(renderer, sdl2Helper.getFormat(this->rasterImage), SDL_TEXTUREACCESS_STREAMING, this->rasterImage->w, this->rasterImage->h);
    }

    SDL2Image(const char* title, int x, int y, int width, int height, int bitsPerPixel) : windowTitle(title), x_position(x), y_position(y), width(width), height(height) {

        window = sdl2Helper.sdl_setup(this->windowTitle, this->x_position, this->y_position, this->width, this->height);
        rasterImage = sdl2Helper.createSurface(this->width, this->height, this->window, bitsPerPixel);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        texture = SDL_CreateTexture(renderer, sdl2Helper.getFormat(this->rasterImage), SDL_TEXTUREACCESS_STREAMING, this->rasterImage->w, this->rasterImage->h);
    }

    /**
     * \brief Use this constructor to enable mixing opengl with sdl2 accelerated rendering
     *
     *  \return 0 on success, or -1 if there was an error
     */

    SDL2Image(const char* title, int x, int y, int width, int height, int bitsPerPixel, int windowFlags) : windowTitle(title), x_position(x), y_position(y), width(width), height(height), windowFlags(windowFlags) {
        /** We want OpenGL **/
        SDL_SetHintWithPriority("SDL_RENDER_DRIVER", "opengl", SDL_HINT_OVERRIDE);
        window = sdl2Helper.sdl_setup(this->windowTitle, this->x_position, this->y_position, this->width, this->height, this->windowFlags);
        rasterImage = sdl2Helper.createSurface(this->width, this->height, this->window, bitsPerPixel);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        texture = SDL_CreateTexture(renderer, sdl2Helper.getFormat(this->rasterImage), SDL_TEXTUREACCESS_STREAMING, this->rasterImage->w, this->rasterImage->h);
    }

    void initTTF() {
        if (TTF_Init() != 0) {
            cout << "TTF_Init() has failed" << endl;
        }
    }

    TTF_Font * openTrueTypeFont(const string filename, int fontSize) {
        return TTF_OpenFont(filename.c_str(), fontSize);
    }

    void addObserver(Observer* observer) {
        addObserver(observer);
    }

    void deleteObserver(Observer* observer) {
        deleteObserver(observer);
    }

    void deleteObservers() {
        deleteObservers();
    }

    void notifyObservers() {
        notifyObservers();
    }

    template <typename Object> inline void notifyObservers(Object* object) {
        notifyObservers(object);
    }

    int numObservers() {
        return numObservers();
    }

    virtual ~SDL2Image() {
        SDL_DestroyWindow(getWindow());
        SDL_DestroyRenderer(getRenderer());
        SDL_DestroyTexture(getTexture());
    }

    //sdl_thread = SDL_CreateMemberThread(this, &SDL2Image::run);

    /*
            if (NULL == sdl_thread)
                cout << "SDL_CreateThread failed: " << SDL_GetError() << endl;
            else {
                cout << "blubb" << endl;
                SDL_WaitThread(sdl_thread, &sdl_threadReturnValue);
                cout << "Paint thread returned: " << sdl_threadReturnValue << endl;
            }
     */

    void setPosition(int x, int y) {
        this->x_position = x;
        this->y_position = y;
        SDL_SetWindowPosition(this->window, this->x_position, this->y_position);
    }

    const char* getWindowTitle() {
        return SDL_GetWindowTitle(getWindow());
    }

    void getPosition(int& x, int& y) {
        x = this->x_position;
        y = this->y_position;
    }

    const SDL_Rect* getViewport() {
        SDL_RenderGetViewport(getRenderer(), this->rect);
        return this->rect;
    }

    void setViewport(int h, int w, int x, int y) {
        this->rect->h = h;
        this->rect->w = w;
        this->rect->x = x;
        this->rect->y = y;
        SDL_RenderSetViewport(getRenderer(), this->rect);
    }

    int _pixelColor(Sint16 x, Sint16 y, Uint32 color) {

        return pixelColor(this->renderer, x, y, color);
    }

    int _pixelRGBA(Sint16 x, Sint16 y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return pixelRGBA(this->renderer, x, y, r, g, b, a);
    }

    int _hlineColor(Sint16 x1, Sint16 x2, Sint16 y, Uint32 color) {

        return hlineColor(this->renderer, x1, x2, y, color);

    }

    int _hlineRGBA(Sint16 x1, Sint16 x2, Sint16 y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return hlineRGBA(this->renderer, x1, x2, y, r, g, b, a);
    }

    int _vlineColor(Sint16 x, Sint16 y1, Sint16 y2, Uint32 color) {

        return vlineColor(this->renderer, x, y1, y2, color);
    }

    int _vlineRGBA(Sint16 x, Sint16 y1, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return vlineRGBA(this->renderer, x, y1, y2, r, g, b, a);
    }

    int _rectangleColor(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color) {

        return rectangleColor(this->renderer, x1, y1, x2, y2, color);
    }

    int _rectangleRGBA(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return rectangleRGBA(this->renderer, x1, y1, x2, y2, r, g, b, a);
    }

    int _roundedRectangleColor(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 rad, Uint32 color) {

        return roundedRectangleColor(this->renderer, x1, y1, x2, y2, rad, color);
    }

    int _roundedRectangleRGBA(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return roundedRectangleRGBA(this->renderer, x1, y1, x2, y2, rad, r, g, b, a);
    }

    int _boxColor(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color) {

        return boxColor(this->renderer, x1, y1, x2, y2, color);
    }

    int _boxRGBA(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return boxRGBA(this->renderer, x1, y1, x2, y2, r, g, b, a);
    }

    int _roundedBoxColor(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 rad, Uint32 color) {

        return roundedBoxColor(this->renderer, x1, y1, x2, y2, rad, color);
    }

    int _roundedBoxRGBA(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return roundedBoxRGBA(this->renderer, x1, y1, x2, y2, rad, r, g, b, a);
    }

    int _lineColor(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color) {

        return lineColor(this->renderer, x1, y1, x2, y2, color);
    }

    int _lineRGBA(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return lineRGBA(this->renderer, x1, y1, x2, y2, r, g, b, a);
    }

    int _aalineColor(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color) {

        return aalineColor(this->renderer, x1, y1, x2, y2, color);
    }

    int _aalineRGBA(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return aalineRGBA(this->renderer, x1, y1, x2, y2, r, g, b, a);
    }

    int _thickLineColor(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 width, Uint32 color) {

        return thickLineColor(this->renderer, x1, y1, x2, y2, width, color);
    }

    int _thickLineRGBA(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint8 width, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return thickLineRGBA(this->renderer, x1, y1, x2, y2, width, r, g, b, a);
    }

    int _circleColor(Sint16 x, Sint16 y, Sint16 rad, Uint32 color) {

        return circleColor(this->renderer, x, y, rad, color);
    }

    int _circleRGBA(Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return circleRGBA(this->renderer, x, y, rad, r, g, b, a);
    }

    int _arcColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint32 color) {

        return arcColor(this->renderer, x, y, rad, start, end, color);
    }

    int _arcRGBA(Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return arcRGBA(this->renderer, x, y, rad, start, end, r, g, b, a);
    }

    int _aacircleColor(Sint16 x, Sint16 y, Sint16 rad, Uint32 color) {

        return aacircleColor(this->renderer, x, y, rad, color);
    }

    int _aacircleRGBA(Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return aacircleRGBA(this->renderer, x, y, rad, r, g, b, a);
    }

    int _filledCircleColor(Sint16 x, Sint16 y, Sint16 r, Uint32 color) {

        return filledCircleColor(this->renderer, x, y, r, color);
    }

    int _filledCircleRGBA(Sint16 x, Sint16 y, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        filledCircleRGBA(this->renderer, x, y, rad, r, g, b, a);
    }

    int _ellipseColor(Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint32 color) {

        return ellipseColor(this->renderer, x, y, rx, ry, color);
    }

    int _ellipseRGBA(Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        ellipseRGBA(this->renderer, x, y, rx, ry, r, g, b, a);
    }

    int _aaellipseColor(Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint32 color) {

        return aaellipseColor(this->renderer, x, y, rx, ry, color);
    }

    int _aaellipseRGBA(Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return aaellipseRGBA(this->renderer, x, y, rx, ry, r, g, b, a);
    }

    int _filledEllipseColor(Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint32 color) {

        return filledEllipseColor(this->renderer, x, y, rx, ry, color);
    }

    int _filledEllipseRGBA(Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return filledEllipseRGBA(this->renderer, x, y, rx, ry, r, g, b, a);
    }

    int _pieColor(Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint32 color) {

        return pieColor(this->renderer, x, y, rad, start, end, color);
    }

    int _pieRGBA(Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return pieRGBA(this->renderer, x, y, rad, start, end, r, g, b, a);
    }

    int _filledPieColor(Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint32 color) {

        return filledPieColor(this->renderer, x, y, rad, start, end, color);
    }

    int _filledPieRGBA(Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return filledPieRGBA(this->renderer, x, y, rad, start, end, r, g, b, a);
    }

    int _trigonColor(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3, Uint32 color) {

        return trigonColor(this->renderer, x1, y1, x2, y2, x3, y3, color);
    }

    int _trigonRGBA(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return trigonRGBA(this->renderer, x1, y1, x2, y2, x3, y3, r, g, b, a);
    }

    int _aatrigonColor(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3, Uint32 color) {

        return aatrigonColor(this->renderer, x1, y1, x2, y2, x3, y3, color);
    }

    int _aatrigonRGBA(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return aatrigonRGBA(this->renderer, x1, y1, x2, y2, x3, y3, r, g, b, a);
    }

    int _filledTrigonColor(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3, Uint32 color) {

        return filledTrigonColor(this->renderer, x1, y1, x2, y2, x3, y3, color);
    }

    int _filledTrigonRGBA(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 x3, Sint16 y3, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return filledTrigonRGBA(this->renderer, x1, y1, x2, y2, x3, y3, r, g, b, a);
    }

    int _polygonColor(const Sint16 * vx, const Sint16 * vy, int n, Uint32 color) {

        return polygonColor(this->renderer, vx, vy, n, color);
    }

    int _polygonRGBA(const Sint16 * vx, const Sint16 * vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return polygonRGBA(this->renderer, vx, vy, n, r, g, b, a);
    }

    int _aapolygonColor(const Sint16 * vx, const Sint16 * vy, int n, Uint32 color) {

        return aapolygonColor(this->renderer, vx, vy, n, color);
    }

    int _aapolygonRGBA(const Sint16 * vx, const Sint16 * vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return aapolygonRGBA(this->renderer, vx, vy, n, r, g, b, a);
    }

    int _filledPolygonColor(const Sint16 * vx, const Sint16 * vy, int n, Uint32 color) {

        return filledPolygonColor(this->renderer, vx, vy, n, color);
    }

    int _filledPolygonRGBA(const Sint16 * vx, const Sint16 * vy, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return filledPolygonRGBA(this->renderer, vx, vy, n, r, g, b, a);
    }

    int _texturedPolygon(const Sint16 * vx, const Sint16 * vy, int n, SDL_Surface * texture, int texture_dx, int texture_dy) {

        return texturedPolygon(this->renderer, vx, vy, n, texture, texture_dx, texture_dy);
    }

    int _bezierColor(const Sint16 * vx, const Sint16 * vy, int n, int s, Uint32 color) {

        return bezierColor(this->renderer, vx, vy, n, s, color);
    }

    int _bezierRGBA(const Sint16 * vx, const Sint16 * vy, int n, int s, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return bezierRGBA(this->renderer, vx, vy, n, s, r, g, b, a);
    }

    int _characterColor(Sint16 x, Sint16 y, char c, Uint32 color) {

        return characterColor(this->renderer, x, y, c, color);
    }

    int _characterRGBA(Sint16 x, Sint16 y, char c, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return characterRGBA(this->renderer, x, y, c, r, g, b, a);
    }

    int _stringColor(Sint16 x, Sint16 y, const char *s, Uint32 color) {

        return stringColor(this->renderer, x, y, s, color);
    }

    int _stringRGBA(Sint16 x, Sint16 y, const char *s, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

        return stringRGBA(this->renderer, x, y, s, r, g, b, a);
    }

    SDL_Surface *_rotozoomSurface(SDL_Surface * src, double angle, double zoom, int smooth) {

        return rotozoomSurface(src, angle, zoom, smooth);
    }

    SDL_Surface *_rotozoomSurfaceXY(SDL_Surface * src, double angle, double zoomx, double zoomy, int smooth) {

        return rotozoomSurfaceXY(src, angle, zoomx, zoomy, smooth);
    }

    void _rotozoomSurfaceSize(int width, int height, double angle, double zoom, int *dstwidth, int *dstheight) {

        rotozoomSurfaceSize(width, height, angle, zoom, dstwidth, dstheight);
    }

    void _rotozoomSurfaceSizeXY(int width, int height, double angle, double zoomx, double zoomy, int *dstwidth, int *dstheight) {

        rotozoomSurfaceSizeXY(width, height, angle, zoomx, zoomy, dstwidth, dstheight);
    }

    SDL_Surface *_zoomSurface(SDL_Surface * src, double zoomx, double zoomy, int smooth) {

        return zoomSurface(src, zoomx, zoomy, smooth);
    }

    void _zoomSurfaceSize(int width, int height, double zoomx, double zoomy, int *dstwidth, int *dstheight) {

        zoomSurfaceSize(width, height, zoomx, zoomy, dstwidth, dstheight);
    }

    SDL_Surface *_shrinkSurface(SDL_Surface * src, int factorx, int factory) {

        return shrinkSurface(src, factorx, factory);
    }

    SDL_Surface* _rotateSurface90Degrees(SDL_Surface* src, int numClockwiseTurns) {

        return rotateSurface90Degrees(src, numClockwiseTurns);
    }

    SDL_Texture* getTexture() {
        return this->texture;
    }

    SDL_Renderer* getRenderer() {
        return this->renderer;
    }

    SDL_Window* getWindow() {
        return this->window;
    }

    const SDL_Surface* getRasterImage() {
        return this->rasterImage;
    }

    virtual void cacheAcceleratedRendererState() {

        glShadeModel(GL_SMOOTH);
        SDLU_GL_RenderCacheState(getRenderer());
    }

    virtual void restoreAcceleratedRendererState() {

        glShadeModel(GL_FLAT);
        SDLU_GL_RenderRestoreState(getRenderer());
    }

    virtual void updateAcceleratedRenderer() {
        //SDL_UpdateTexture(getTexture(), NULL, getRasterImage()->pixels, getRasterImage()->w * getRasterImage()->format->BitsPerPixel);
        //SDL_UpdateTexture(getTexture(), NULL, getRasterImage()->pixels, getRasterImage()->pitch);

        SDL_RenderClear(getRenderer());
        SDL_RenderCopy(getRenderer(), getTexture(), NULL, NULL);
    }

    virtual void paint() {

        SDL_RenderPresent(getRenderer());
    }

    virtual int getHeight() {

        return this->height;
    }

    virtual int getWidth() {
        return this->width;
    }

private:

    int windowFlags;
    int x_position;
    int y_position;
    int width;
    int height;
    SDL_Texture* texture;
    SDL_Surface* rasterImage;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL2Helper sdl2Helper;
    SDL_Rect * rect;
    const char* windowTitle;
};

#endif /* SDL2IMAGE_H */


