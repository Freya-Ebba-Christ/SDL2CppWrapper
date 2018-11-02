/* 
 *    Copyright [2018] Olaf - blinky0815 - christ ]
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

#ifndef SDL2PANEL_H
#define SDL2PANEL_H
#include <iostream>
#include <string>
#include <SDL2Image.h>
#include <RGBA.h>
#include <Point.h>

class SDL2Panel {
public:

    SDL2Panel() {
        setAlpha(255);
    }

    virtual ~SDL2Panel() {
    }

    virtual inline void setAlpha(uint8_t value) {
        color.setColor(color.getR(), color.getG(), color.getB(), value);
    }

    virtual inline uint8_t getAlpha() {
        return this->color.getA();
    }

    void setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
        color.setColor(r, g, b, a);
    }

    RGBA& getColor() {
        return this->color;
    }

    virtual inline void setPosition(Point<int> value) {
        this->position.setX(value.getX());
        this->position.setY(value.getY());
    }

    virtual inline Point<int>& getPosition() {
        return this->position;
    }

    virtual inline void setDimensions(int width, int height) {
        this->width = width;
        this->height = height;
    }

    virtual inline int getWidth() {
        return width;
    }

    virtual inline int getHeight() {
        return height;
    }

    virtual void paint(SDL2Image* image) = 0;

private:
    Point<int> position;
    int width;
    int height;
    RGBA color;
private:

};

#endif /* SDL2PANEL_H */

