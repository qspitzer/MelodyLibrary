#include "Melody.h"
#include "Arduino.h"

/*#include <Thread.h>
#include <StaticThreadController.h>

Thread tone1 = Thread();
Thread tone2 = Thread();
Thread tone3 = Thread();

tone1.onRun(Melody::pt1);
tone2.onRun(Melody::pt2);
tone3.onRun(Meoldy::pt3);

StaticThreadController<3> playTones (&tone1, &tone2, &tone3);*/

float Melody::_time = 0;
int Melody::_buzzer1 = 0;
int Melody::_buzzer2 = 0;
int Melody::_buzzer3 = 0;
float Melody::_len = 0;
float Melody::_n1 = 0;
float Melody::_n2 = 0;
float Melody::_n3 = 0;

Melody::Melody(float playTime, int b1, int b2, int b3) {
    _time = playTime;
    _buzzer1 = b1;
    _buzzer2 = b2;
    _buzzer3 = b3;
    
    _len = _time;
    
    pinMode(_buzzer1, OUTPUT);
    pinMode(_buzzer2, OUTPUT);
    pinMode(_buzzer3, OUTPUT);
}
void Melody::playNotes(float n1, float noteLength) {
    _len = _time / noteLength;
    _n1 = n1;
    _n2 = 0;
    _n3 = 0;
    //playTones.run();
}

void Melody::playNotes(float n1, float n2, float noteLength) {
    _len = _time / noteLength;
    _n1 = n1;
    _n2 = n2;
    _n3 = 0;
    //playTones.run();
}


void Melody::playNotes(float n1, float n2, float n3, float noteLength) {
    _len = _time / noteLength;
    _n1 = n1;
    _n2 = n2;
    _n3 = n3;
    //playTones.run();
}

void Melody::playTone2() {
    long sleepTime = 500/(_n2);
    int cycles = _n2 * (_time /*- (_time *0.025)*/);
    for(int x = 0; x<cycles; x++) {
        digitalWrite(_buzzer2, HIGH);
        delay(sleepTime);
        digitalWrite(_buzzer2, LOW);
        delay(sleepTime);
    }
    //delay((_time *0.025)*1000);
}
void Melody::playTone3() {
    double sleepTime = 500/(_n3);
    int cycles = _n3 * (_time /*- (_time *0.025)*/);
    for(int x = 0; x<cycles; x++) {
        digitalWrite(_buzzer3, HIGH);
        delay(sleepTime);
        digitalWrite(_buzzer3, LOW);
        delay(sleepTime);
    }
    //delay((_time *0.025)*1000);
}
