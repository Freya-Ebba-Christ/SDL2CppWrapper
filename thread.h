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

#ifndef THREAD_H
#define	THREAD_H
#include <thread>
#include <threadworker.h>

class Thread {
public:

    Thread() {
    }

    void start() {
        running = true;
        aThread = std::thread([this] {
            this->run(); });
        aThread.detach();
    }

    void stop() {
        running = false;
    }

    void setThreadWorker(ThreadWorker* value) {
        this->threadWorker = value;
    }

    ~Thread() {
    }
private:

    void run() {
        while (running) {
            if (threadWorker->isActive()) {
                threadWorker->execute();
            } else {
            }
        }
    }

    ThreadWorker* threadWorker;
    std::thread aThread;
    bool running = true;
};

#endif	/* THREAD_H */

