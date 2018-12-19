#ifndef Melody_h
#define Melody_h
#include "Arduino.h"
#include "Pitches.h"
class Melody {
    public:
        Melody(float playTime, int b1, int b2, int b3);
        
        void playNotes(float note, float noteLength);
        
        void playNotes(float n1, float n2, float noteLength);
        
        void playNotes(float n1, float n2, float n3, float noteLength);
        
        //static void pt1();
        //static void pt2();
        //static void pt3();
        static void playTone2();
        static void playTone3();
        
    //private:
        static float _time;
        static float _n1;
        static float _n2;
        static float _n3;
        static float _len;
        static int _buzzer1;
        static int _buzzer2;
        static int _buzzer3;
        static int _b1Port;
        static int _b2Port;
        static int _b3Port;
        
};
#endif
