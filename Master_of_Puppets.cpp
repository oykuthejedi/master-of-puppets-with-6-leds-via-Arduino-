#include "pitches.h"

int notes;
int duration;

// LED pins
int ledPins[] = {8, 9, 10, 11, 12, 13}; 

// This is for an Arduino with an active buzzer and 6 LEDs.

int intro1[] = {NOTE_E3, 0, NOTE_D4, NOTE_CS4, NOTE_C4};
int intro1NoteDurations[] = {4, 2, 4, 4, 1};
int intro1Count = 5;

int intro2[] = {NOTE_E3, NOTE_E3, NOTE_E4, NOTE_E3, NOTE_E3, NOTE_DS4, NOTE_E3, NOTE_E3, NOTE_D4, NOTE_CS4, NOTE_C4};
int intro2NoteDurations[] = {8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 2};
int intro2Count = 11;

int intro3[] = {NOTE_E3, NOTE_E3, NOTE_B3, NOTE_E3, NOTE_E3, NOTE_AS3, NOTE_E3, NOTE_E3, NOTE_A3, NOTE_E3, NOTE_GS3, NOTE_E3, NOTE_G3, NOTE_E3, NOTE_FS3, NOTE_E3};
int intro3NoteDurations[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
int intro3Count = 16;

int preverse1[] = {NOTE_E3, NOTE_F3, NOTE_B3, NOTE_E3, NOTE_F3, NOTE_C4, NOTE_E3, NOTE_F3, NOTE_CS4, NOTE_E3, NOTE_F3, NOTE_C4, NOTE_E3, NOTE_F3, NOTE_B3, NOTE_B3};
int preverse1NoteDurations[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
int preverse1Count = 16;

int preverse2[] = {NOTE_E3, NOTE_F3, NOTE_B3, NOTE_E3, NOTE_F3, NOTE_C4, NOTE_E3, NOTE_F3, NOTE_CS4, NOTE_E3, NOTE_F3, NOTE_C4, NOTE_E3, NOTE_F3, NOTE_B3, 0};
int preverse2NoteDurations[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
int preverse2Count = 16;

int preverse3[] = {NOTE_E3, NOTE_F3, NOTE_B3, NOTE_E3, NOTE_F3, NOTE_C4, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_FS3, NOTE_E3, NOTE_G3, NOTE_FS3, NOTE_E3, NOTE_G3, NOTE_FS3};
int preverse3NoteDurations[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
int preverse3Count = 16;

int endIntro[] = {NOTE_G3, NOTE_FS3, NOTE_E3, NOTE_G3, NOTE_FS3, NOTE_E3, NOTE_G3, NOTE_FS3, NOTE_E3, NOTE_DS4, NOTE_A5, NOTE_E3, NOTE_DS4, NOTE_A5, NOTE_E3, NOTE_DS4, NOTE_A5, NOTE_E3, NOTE_DS4, NOTE_A5, NOTE_E3, NOTE_DS4, NOTE_A5};
int endIntroNoteDurations[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 2};
int endIntroCount = 23;

int eightVampE[] = {NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3};
int eightVampENoteDurations[] = {8, 8, 8, 8, 8, 8, 8, 8};
int eightVampECount = 8;

int verse1[] = {0, NOTE_G3, NOTE_A3, 0, NOTE_AS3, NOTE_A3, NOTE_G3, NOTE_A3};
int verse1NoteDurations[] = {8, 8, 8, 8, 8, 8, 8, 8};
int verse1Count = 8;

int verse2[] = {NOTE_A3, 0, NOTE_A3, 0};
int verse2NoteDurations[] = {8, 8, 8, 8};
int verse2Count = 4;

int eightVampFSharp[] = {NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_FS3};
int eightVampFSharpNoteDurations[] = {8, 8, 8, 8, 8, 8, 8, 8};
int eightVampFSharpCount = 8;

void playInput(int notes[], int durations[], int count, int ledPins[]) {
  for (int thisNote = 0; thisNote < count; thisNote++) {
    int noteDuration = 1000 / durations[thisNote];
    tone(3, notes[thisNote], noteDuration);

    // Turn on LEDs based on the pitch of the note
    for (int i = 0; i < 6; i++) { 
      if (notes[thisNote] != 0) { 
        if (i == (notes[thisNote] % 6)) {
          digitalWrite(ledPins[i], HIGH);
        } else {
          digitalWrite(ledPins[i], LOW);
        }
      } else {
        digitalWrite(ledPins[i], LOW); 
      }
    }

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    for (int i = 0; i < 6; i++) { 
      digitalWrite(ledPins[i], LOW);
    }
  }
}

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Intro
  playInput(intro1, intro1NoteDurations, intro1Count, ledPins);
  playInput(intro2, intro2NoteDurations, intro2Count, ledPins);
  playInput(intro3, intro3NoteDurations, intro3Count, ledPins);
  playInput(intro2, intro2NoteDurations, intro2Count, ledPins);
  playInput(intro3, intro3NoteDurations, intro3Count, ledPins);
  playInput(preverse1, preverse1NoteDurations, preverse1Count, ledPins);
  playInput(preverse2, preverse2NoteDurations, preverse2Count, ledPins);
  playInput(preverse1, preverse1NoteDurations, preverse1Count, ledPins);
  playInput(preverse3, preverse3NoteDurations, preverse3Count, ledPins);
  playInput(endIntro, endIntroNoteDurations, endIntroCount, ledPins);

  // Verse 1
  playInput(eightVampE, eightVampENoteDurations, eightVampECount, ledPins);
  playInput(verse1, verse1NoteDurations, verse1Count, ledPins);
  playInput(eightVampE, eightVampENoteDurations, eightVampECount, ledPins);
  playInput(verse2, verse2NoteDurations, verse2Count, ledPins);
  playInput(eightVampE, eightVampENoteDurations, eightVampECount, ledPins);
  playInput(verse1, verse1NoteDurations, verse1Count, ledPins);
  playInput(eightVampE, eightVampENoteDurations, eightVampECount, ledPins);
  playInput(verse2, verse2NoteDurations, verse2Count, ledPins);
  playInput(eightVampFSharp, eightVampFSharpNoteDurations, eightVampFSharpCount, ledPins);

  noTone(3);
}

void loop() {
}

// Thanks to alexfornuto for the sheet 
