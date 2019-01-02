# MelodyLibrary
(Nonfunctional) Arduino library to play notes on a buzzer.

**Currently only tested on Arduino Uno**

# Usage
## Initialization
```Melody song = Melody(<measure length>, <buzzer pin 1>, <buzzer pin 2>, <buzzer pin 3>);```

## Playing notes
You can play up to 3 notes at a time on one buzzer
```
song.playNotes(<frequency>, [<frequency 2>], [<frequency 3>], <note length>);
```
The note length is set to `1/x` were `x` is the value in `note length`.
So if you wanted a note to play a quarter note, you would set the note length to 4.

### TODO
- [ ] Fix/finish both `playTone` functions
- [ ] Fix `buzzer pin` assignment
- [ ] Add protothreading to allow for multiple notes to play at once
- [ ] Test on more Arduinos, add support if necessary
