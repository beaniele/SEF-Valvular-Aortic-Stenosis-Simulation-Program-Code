/*
It should be noted that this program is intended to run on the Arduino Uno R4 Minima, not the Wi-Fi
a typical input/output response system will be achieved through this program. the prototype,
with the use of a pump, sensor, and LED, will begin function when analog values exceed the
stated threshold through the sensor displaying conductivity units onto the serial monitor.
once conductivity has been recorded to be less than or quivalate to that of the given threshold,
the pump will stop its fucntion, and the LED will turn on, indicating that the system has stopped.
this indicates that the procedure being simulated has been completed successfully.
*/

int conductivity;   //A0 will be used to invalidate all other voltage values, and will use the full capacity of the arduino and distribute throughout
                    //the ciruit of 0-1023
int threshold = 1000; //threshold to which the sensor will display units, and notify proctor that the procedure has been carried out properly
                    // and that there is no more matter detected above 1000.
                    //keep in mind that the monitor tends to fluctuate values here and there
int LEDPin = 9; //the LED does not need as much power as the pump, so it will be connected to pin 9
int LEDSpeed = 255; //LED brightness level, 0-255
int suctionPin = 11; //the pump will be connected to pin 11, as it requires more power than the LED
int sunctionSpeed = 255; //pump speed level, 0-255
                        // the speed of the pump can and will be adjusted to fit the needs of the user

void setup() {

    //Initializes serial communication @9600 baud
    //baud rate can be adjusted either for fun or for best fit
    Serial.begin(9600);

    //Initializes pump function
    pinMode(suctionPin, OUTPUT);

    //Initializes LED function
    //The LED will now know when to turn on and off when called during loop
    //when the threshold has been met, or conductivity is lower than the threshold = on
    //when threshold has been exceeded, or conductivity is at its peak = off
    pinMode(LEDPin, OUTPUT);
}

void loop() {

    //Conductivity's central read
    //The voltage used will be the defalt that the R4 allows for
    conductivity = analogRead(A0);

    //When the serial monitor knows when to start displaying data of 1023 analog units
    //Initiates the serial monitor to display conductivity units
    Serial.println(conductivity);

    //conditional statement to determine whether the pump or LED will be activated
    //if the conductivity read is greater than 1000C units, pump start
    if (conductivity > threshold) {

        //suction, or pump fucntion, will begin
        //is only active when conductivity units exceed the stated threshold
        analogWrite(suctionPin, sunctionSpeed); //activates pump
        
        //no power should be going to the LED
        //should be turned off while the pump is active
        analogWrite(LEDPin, 0); //turns off LED
    }
    //else, when the conductivity read is less than or equal to the stated threshold
    //pump off, LED on
    else {

        //suction function will stop when the threshold is met
        //honestly, it's either 0 is stated to say that no power to the pump
        //or LOW could also be stated as well
        //0 is used here for clarity and mere preference
        analogWrite(suctionPin, 0); //deactivates pump
        
        //The LED should turn on and flash
        //procedure has been completed successfully
        analogWrite(LEDPin, LEDSpeed); //turns on LED
    }
}
