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

#ifndef TIMECONVERTER_H
#define	TIMECONVERTER_H

#include <limits>
#include <iostream>

using namespace std;

class TimeConverter {
public:

    TimeConverter() {
    }

    //NANOS

    long nanosToNanos(long d) {
        return d;
    }

    long nanosToMicros(long d) {
        return d / (C1 / C0);
    }

    long nanosToMillis(long d) {
        return d / (C2 / C0);
    }

    long nanosToSeconds(long d) {
        return d / (C3 / C0);
    }

    long nanosToMinutes(long d) {
        return d / (C4 / C0);
    }

    long nanosToHours(long d) {
        return d / (C5 / C0);
    }

    long nanosToDays(long d) {
        return d / (C6 / C0);
    }

    long microsToNanos(long d) {
        return x(d, C1 / C0, numeric_limits<long>::max() / (C1 / C0));
    }

    //micros

    long microsToMicros(long d) {
        return d;
    }

    long microsToMillis(long d) {
        return d / (C2 / C1);
    }

    long microsToSeconds(long d) {
        return d / (C3 / C1);
    }

    long microsToMinutes(long d) {
        return d / (C4 / C1);
    }

    long microsToHours(long d) {
        return d / (C5 / C1);
    }

    long microsToDays(long d) {
        return d / (C6 / C1);
    }

    //millis

    long millisToNanos(long d) {
        return x(d, C2 / C0, numeric_limits<long>::max() / (C2 / C0));
    }

    long millisToMicros(long d) {
        return x(d, C2 / C1, numeric_limits<long>::max() / (C2 / C1));
    }

    long millisToMillis(long d) {
        return d;
    }

    long millisToSeconds(long d) {
        return d / (C3 / C2);
    }

    long millisToMinutes(long d) {
        return d / (C4 / C2);
    }

    long millisToHours(long d) {
        return d / (C5 / C2);
    }

    long millisToDays(long d) {
        return d / (C6 / C2);
    }

    //seconds

    long secondsToNanos(long d) {
        return x(d, C3 / C0, numeric_limits<long>::max() / (C3 / C0));
    }

    long secondsToMicros(long d) {
        return x(d, C3 / C1, numeric_limits<long>::max() / (C3 / C1));
    }

    long secondsToMillis(long d) {
        return x(d, C3 / C2, numeric_limits<long>::max() / (C3 / C2));
    }

    long secondsToSeconds(long d) {
        return d;
    }

    long secondsToMinutes(long d) {
        return d / (C4 / C3);
    }

    long secondsToHours(long d) {
        return d / (C5 / C3);
    }

    long secondsToDays(long d) {
        return d / (C6 / C3);
    }

    //minutes

    long minutesToNanos(long d) {
        return x(d, C4 / C0, numeric_limits<long>::max() / (C4 / C0));
    }

    long minutesToMicros(long d) {
        return x(d, C4 / C1, numeric_limits<long>::max() / (C4 / C1));
    }

    long minutesToMillis(long d) {
        return x(d, C4 / C2, numeric_limits<long>::max() / (C4 / C2));
    }

    long minutesToSeconds(long d) {
        return x(d, C4 / C3, numeric_limits<long>::max() / (C4 / C3));
    }

    long minutesToMinutes(long d) {
        return d;
    }

    long minutesToHours(long d) {
        return d / (C5 / C4);
    }

    long minutesToDays(long d) {
        return d / (C6 / C4);
    }

    //hours

    long hoursToNanos(long d) {
        return x(d, C5 / C0, numeric_limits<long>::max() / (C5 / C0));
    }

    long hoursToMicros(long d) {
        return x(d, C5 / C1, numeric_limits<long>::max() / (C5 / C1));
    }

    long hoursToMillis(long d) {
        return x(d, C5 / C2, numeric_limits<long>::max() / (C5 / C2));
    }

    long hoursToSeconds(long d) {
        return x(d, C5 / C3, numeric_limits<long>::max() / (C5 / C3));
    }

    long hoursToMinutes(long d) {
        return x(d, C5 / C4, numeric_limits<long>::max() / (C5 / C4));
    }

    long hoursToHours(long d) {
        return d;
    }

    long hoursToDays(long d) {
        return d / (C6 / C5);
    }

    //days

    long daysToNanos(long d) {
        return x(d, C6 / C0, numeric_limits<long>::max() / (C6 / C0));
    }

    long daysToMicros(long d) {
        return x(d, C6 / C1, numeric_limits<long>::max() / (C6 / C1));
    }

    long daysToMillis(long d) {
        return x(d, C6 / C2, numeric_limits<long>::max() / (C6 / C2));
    }

    long daysToSeconds(long d) {
        return x(d, C6 / C3, numeric_limits<long>::max() / (C6 / C3));
    }

    long daysToMinutes(long d) {
        return x(d, C6 / C4, numeric_limits<long>::max() / (C6 / C4));
    }

    long daysToHours(long d) {
        return x(d, C6 / C5, numeric_limits<long>::max() / (C6 / C5));
    }

    long daysToDays(long d) {
        return d;
    }

    virtual ~TimeConverter() {
    }
    
private:
    static const long C0 = 1L;
    static const long C1 = C0 * 1000L;
    static const long C2 = C1 * 1000L;
    static const long C3 = C2 * 1000L;
    static const long C4 = C3 * 60L;
    static const long C5 = C4 * 60L;
    static const long C6 = C5 * 24L;

    static long x(long d, long m, long over) {
        if (d > over) {
            return numeric_limits<long>::max();
        }
        if (d < -over) {
            return numeric_limits<long>::min();
        }
        return d * m;
    }
};

#endif	/* TIMECONVERTER_H */

