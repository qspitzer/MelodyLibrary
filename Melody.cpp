#include "Melody.h"
#include "Arduino.h"
#define CLR(x,y) (x&=(~(1<<y)))
#define SET(x,y) (x|=(1<<y))

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
int Melody::_b1Port = PORTB;
int Melody::_b2Port = PORTB;
int Melody::_b3Port = PORTB;

Melody::Melody(float playTime, int b1, int b2, int b3) {
    _time = playTime;
    _buzzer1 = b1;
    _buzzer2 = b2;
    _buzzer3 = b3;
    
    _len = _time;
    
    if(b1>=2 && b1<=7) {
        //DDRD = B00000000;
        switch(b1) {
            case 2:
                SET(DDRD, 2 - 1);
                break;
            case 3:
                SET(DDRD, 3 - 1);
                break;
            case 4:
                SET(DDRD, 4 - 1);
                break;
            case 5:
                SET(DDRD, 5 - 1);
                break;
            case 6:
                SET(DDRD, 6 - 1);
                break;
            case 7:
                SET(DDRD, 7 - 1);
                break;
        }
    _b1Port = PORTD;
    } else if(b1>=8 && b1<=13) {
        //DDRB = B000000;
        switch(b1) {
            case 8:
                SET(DDRB, 0);
                _buzzer1 = 0;
                break;
            case 9:
                SET(DDRB, 1);
                _buzzer1 = 1;
                break;
            case 10:
                SET(DDRB, 2);
                _buzzer1 = 2;
                break;
            case 11:
                SET(DDRB, 3);
                _buzzer1 = 3;
                break;
            case 12:
                SET(DDRB, 4);
                _buzzer1 = 4;
                break;
            case 13:
                SET(DDRB, 5);
                _buzzer1 = 5;
                break;
        }
    //_b1Port = PORTB;
    }
    
    if(b2>=2 && b2<=7) {
        //DDRD = B00000000;
        switch(b2) {
            case 2:
                SET(DDRD, 2 - 1);
                break;
            case 3:
                SET(DDRD, 3 - 1);
                break;
            case 4:
                SET(DDRD, 4 - 1);
                break;
            case 5:
                SET(DDRD, 5 - 1);
                break;
            case 6:
                SET(DDRD, 6 - 1);
                break;
            case 7:
                SET(DDRD, 7 - 1);
                break;
        }
    _b2Port = PORTD;
    } else if(b2>=8 && b2<=13) {
        //DDRB = B000000;
        switch(b2) {
            case 8:
                SET(DDRB, 0);
                _buzzer2 = 0;
                break;
            case 9:
                SET(DDRB, 1);
                _buzzer2 = 1;
                break;
            case 10:
                SET(DDRB, 2);
                _buzzer2 = 2;
                break;
            case 11:
                SET(DDRB, 3);
                _buzzer2 = 3;
                break;
            case 12:
                SET(DDRB, 4);
                _buzzer2 = 4;
                break;
            case 13:
                SET(DDRB, 5);
                _buzzer2 = 5;
                break;
        }
    //_b2Port = PORTB;
    }
    
    if(b3>=2 && b3<=7) {
        //DDRD = B00000000;
        switch(b3) {
            case 2:
                SET(DDRD, 2 - 0);
                break;
            case 3:
                SET(DDRD, 3 - 0);
                break;
            case 4:
                SET(DDRD, 4 - 0);
                break;
            case 5:
                SET(DDRD, 5 - 0);
                break;
            case 6:
                SET(DDRD, 6 - 0);
                break;
            case 7:
                SET(DDRD, 7 - 0);
                break;
        }
    _b3Port = PORTD;
    } else if(b3>=8 && b3<=13) {
        //DDRB = B000000;
        switch(b3) {
            case 8:
                SET(DDRB, 0); 
                _buzzer3 = 0;
                break;
            case 9:
                SET(DDRB, 1);
                _buzzer3 = 1;
                break;
            case 10:
                SET(DDRB, 2);
                _buzzer3 = 2;
                break;
            case 11:
                SET(DDRB, 3);
                _buzzer3 = 3;
                break;
            case 12:
                SET(DDRB, 4);
                _buzzer3 = 4;
                break;
            case 13:
                SET(DDRB, 5);
                _buzzer3 = 5;
                break;
        }
    //_b3Port = PORTB;
    }
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
    float sleepTimeA = 500/(_n2);
    long int cycles = 1000000000;//_n2 * (_time);
    for(int x = 0; x<cycles; x++) {
        SET(PORTD,7);
        delay(sleepTimeA);
        CLR(PORTD, 7);
        delay(sleepTimeA);
    }
}
void Melody::playTone3() {
    double sleepTimeB = 500/(_n3);
    int cycles = _n3 * (_time /*- (_time *0.025)*/);
    for(int x = 0; x<cycles; x++) {
        bitSet(PORTD, 6);
        delay(sleepTimeB);
        bitClear(PORTD, 6);
        delay(sleepTimeB);
    }
}
