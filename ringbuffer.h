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

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <string.h>
#include <vector>
#include <numeric>

template <typename T> class RingBuffer {
public:

    RingBuffer() : size(1024) {
        initialize();
    }

    RingBuffer(int size) : size(size) {
        initialize();
    }

    virtual ~RingBuffer() {
        //delete[] buffer;
    }

    void addElement(T element) {
        if (currentPosition < size)
            buffer.at(currentPosition++) = element;
        currentPosition %= size;
    }

    T getElementAt(int pos) {
        return currentPosition + pos < size ? buffer.at(currentPosition + pos) : buffer.at(currentPosition + pos - size);
    }

    void toArray(T* array) {
        memcpy(array, buffer.data() + currentPosition, (size - currentPosition) * sizeof (T));
        memcpy(array + (size - currentPosition), buffer.data(), (size - (size - currentPosition)) * sizeof (T));
    }

    T getMean() {
        T mean = 0;
        for (int i = 0; i < size; i++) {
            mean += buffer.at(i);
        }
        return mean / buffer.size();
    }

    int getSize() {
        return size;
    }

    void setSize(int value) {
        this->size = value;
    }

    void initialize() {
        std::vector<T>().swap(buffer);
        buffer.clear();
        buffer.resize(size, 0);
        currentPosition = 0;
    }

private:

    int size;
    std::vector<T> buffer;
    //T* buffer;
    int currentPosition;
};

#endif /* RINGBUFFER_H */

