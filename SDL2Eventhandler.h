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

#ifndef SDL2EVENTHANDLER_H
#define SDL2EVENTHANDLER_H

class SDL2Eventhandler {
public:

    SDL2Eventhandler() {

    }

    SDL2Eventhandler(const SDL2Eventhandler& orig) {
    }

    virtual ~SDL2Eventhandler() {
    }

    virtual void perform(SDL_Event& value) = 0;

    virtual SDL_Event& getEvent() {
        return this->event;
    }

    virtual void setEvent(SDL_Event value) {
        this->event = value;
    }

    virtual void setWindowID(int value) {
        this->windowID = value;
    }

    virtual int getWindowID() {
        return this->windowID;
    }

private:
    int windowID = 666;
    SDL_Event event;
};

#endif /* SDL2EVENTHANDLER_H */























































































/*
 Iron Maiden: The Number of the Beast 
 
"Woe to you, oh Earth and sea, for the Devil sends the Beast with wrath
Because he knows the time is short
Let him who hath understanding reckon the number of the Beast 
For it is a human number, its number is six hundred and sixty six"
I left alone my mind was blank
I needed time to think to get the memories from my mind
What did I see can I believe that what I saw
That night was real and not just fantasy
Just what I saw
In my old dreams were they reflections of my warped mind staring back at me
'Cause in my dreams 
It's always there 
The evil face that twists my mind and brings me to despair 
Yeah
The night was black was no use holding back
'Cause I just had to see was someone watching me
In the mist dark figures move and twist
Was all this for real or some kind of hell
Six six six the number of the Beast
Hell and fire was spawned to be released
Torches blazed and sacred chants were praised
As they start to cry hands held to the sky
In the night the fires burning bright
The ritual has begun Satan's work is done
Six six six the number of the beast
Sacrifice is going on tonight
This can't go on I must inform the law
Can this still be real or some crazy dream
But I feel drawn towards the chanting hordes
They seem to mesmerize me can't avoid their eyes?
Six six six the number of the Beast
Six six six the one for you and me
I'm coming back I will return
And I'll possess your body and I'll make you burn
I have the fire I have the force
I have the power to make my evil take it's course
Songwriters: Stephen Percy Harris
The Number of the Beast (Live Long Beach Arena) lyrics © Kobalt Music Publishing Ltd.
 */