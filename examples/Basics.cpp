/*
Simple touchMux example:
  --setup some 4067 mux
  --read and display touch values via Serial
  --see if some plates are touched
*/
#include <Arduino.h>
#include <touchmux.h>

touchMux mux(0, 1, 2, 3, 4); //declaration of S0, S1, S2, S3 and readpin of 4067

void setup() {
  Serial.begin(115200);
}

void loop() {
  for(int i=0; i<16; i++) {
    Serial.print("Channel " + i );
    Serial.print(", value = " + mux.read(i));
    Serial.println(", touched ? " + mux.touched(i));
  }
  delay(100);
}
/*
int touchRead_pin[11] = {0, 1, 3, 4, 15, 16, 17, 18, 19, 22, 23};
int midi_note[11] = {54, 56, 58, 61, 63, 66, 68, 70, 73, 75, 78};
int buffer;
int data;
bool touched[11], last_state[11];

void setup() {
  Serial.begin(57600);

}

void loop() {
  for(int i=0; i<11; i++) {
    data = touchRead(touchRead_pin[i]);
    touched[i] = data >= 1000 ? 1 : 0;
    Serial.print(touched[i]);
    Serial.print(" ");
    if(touched[i] == 1 && touched[i] != last_state[i]) {
      last_state[i] = touched[i];
      usbMIDI.sendNoteOn(midi_note[i], 99, 1); //MIDI
    }
    if(touched[i] == 0 && touched[i] != last_state[i]) {
      last_state[i] = touched[i];
      usbMIDI.sendNoteOff(midi_note[i], 0, 1);  //MIDI
    }
  }
  Serial.println("");
  delay(100);
}
*/
