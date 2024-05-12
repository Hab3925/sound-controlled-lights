### Sound controlled lights

This the code for the lab project in the class TFY4190 Instrumentation as part of my bachelors degree in physics. 

The project assignment was to "Measure and/or control something using sensors and/or actuators, a data acquisition device and a computer". We opted to use an Arduino Uno R3 to sample an electret microphone, and use that data to controll the colour and number of active LEDs on an LED strip to mimic an equaliser following the beat of music playing. 

It uses PlatformIO to program the Arduino, as the Arduino IDE is a pain to work with once you have multiple files. The program itself is divided into "threads" using a modified version of the `ArduinoThread` library to schedule different tasks, mimicing the functionality of a Real Time Operating System (RTOS). 

A custom hat/shield PCB for the Arduino was made with the electronics for filtering and sampling the microphone, aswell as powering and controlling the LEDs. 

The final report for the project is in the root folder, named "Report.pdf"

## The code

The code is separated into 4 "threads/tasks":
* *sampling.cpp*: Samples the filtered microphone signal using the MCP3201 ADC on the Arduino hat/shield and stores it in a buffer
* *fft.cpp*: Performs an FFT using the `ArduinoFFT` library on the data sampled in the buffer to find the most dominant frequency
* *ledStrip.cpp*: Changes the number of LEDs that are on using the amplitude of the signal in the buffer and changes the color of the LEDs based on the dominant frequency
* *blink.cpp*: Blinks the user LED on the hat/shield, indicating that the program is running nominaly, which is used for debugging

Theese are all run at given frequencies by the `ThreadController` through *main.cpp*. 

The colour of the LEDs are mapped using `map()` function to map the recorded peak frequency between 200Hz and 16kHz to a hue value between 0 and 360 which is used as the LED colour. A similar process is done for the amplitude and number of LEDS, mapping the amplitude of the signal from 0 to 2048 (half of the MCP3201s range) to 0 to 60 active LEDs. 

## The PCB

The PCB made to sit on top of the arduino contained an inverted bandpass filter with amplification that filtered the signal to about between 200Hz and 16kHz, and amplified it 1000x, and the MPC3201 ADC to sample the signal faster and with a higher resolution than the internal ADC of the Arduino. The PCB had some design flaws that took some time resolving, resulting in little development time of the code. 

The schematic and layout of the PCB can be found below and in the `PCB schematics folder`

