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

#ifndef FILEIO_H
#define FILEIO_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

class FileIO {
public:

    FileIO() {
    }

    virtual ~FileIO() {
    }

    template <typename T> inline void write(std::vector<T>& data, string path) {
        std::ofstream file(path, std::ios::out | std::ios::binary);
        file.write(reinterpret_cast<const char*> (data.data()), data.size() * sizeof (T));
    }

    template <typename T> inline void append(std::vector<T>& data, string path) {
        std::ofstream file(path, std::ios::out | std::ios::binary | std::ios::app);
        file.write(reinterpret_cast<const char*> (data.data()), data.size() * sizeof (T));
    }

    template <typename T> inline void read(vector<T>& data, string path) {
        std::ifstream file(path, std::ios::in | std::ios::binary);
        std::vector<char> buffer;
        buffer.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
        data.resize(buffer.size() / sizeof (T));
        copy(buffer.begin(), buffer.end(), (char*) data.data());
    }

    template <typename T> inline void writeTxT(std::vector<T>& data, std::string delimiter, string path) {
        std::ofstream file(path, std::ios::out | std::ios::app);
        for (int i = 0; i < data.size() - 1; i++) {
            file << (int) data.at(i) << delimiter;
        }
        file << (int) data.at(data.size() - 1) << endl;
        file.close();
    }

    inline void insertComment(std::string comment, std::string path) {
        std::ofstream file(path, std::ios::out | std::ios::app);
        file << "#" << comment << endl;
        file.close();
    }

    template <typename T> inline void writeText(std::vector<T>& data, string path) {
        std::ofstream file(path, std::ios::out);
        file.write(reinterpret_cast<const char*> (data.data()), data.size() * sizeof (T));
    }

    template <typename T> inline void appendText(std::vector<T>& data, string path) {
        std::ofstream file(path, std::ios::out | std::ios::app);
        file.write(reinterpret_cast<const char*> (data.data()), data.size() * sizeof (T));
    }

    template <typename T> inline void readText(std::vector<T>& data, string path) {
        std::ifstream file(path, std::ios::in);
        std::vector<char> buffer;
        buffer.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
        data.resize(buffer.size() / sizeof (T));
        copy(buffer.begin(), buffer.end(), (char*) data.data());
    }

private:

};

#endif /* FILEIO_H */

