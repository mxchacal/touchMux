# touchMux 
Simple teensy library, extending the number of touchRead.able channels

## Use
Include the library header

    #include <touchmux.h>

Create new instance. readPin must be a teensy touch pin

    touchMux mux(int sig0, int sig1, int sig2, int sig3, readPin)

Read a pin

    mux.read(int pin)

See if a plate is touched, according to treshold

    mux.touched(int pin)
    
Set a treshold for the touched() function

    mux.setTreshold(int treshold)
    
set an automatic treshold level

    mux.autoTreshold()

## Example
Basic program to setup and test the library functions

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

Source: http://little-scale.blogspot.com/2015/11/32-capacitive-touch-sensors-and-ableton.html
