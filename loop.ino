//prototype will respond to this loop based system and base each variable function to each condition.

void loop() {

    conductivity = analogRead(A0); //values from ~A0
    SerialUSB.println(conductivity); //the UNO R4 only understands and connects to SerialUSB, not Serial
                                     //serial monitor will print out conductivity units as a response to the sensor
    delay(200); //serial monitor will delay considering that it prints @ 9600 baud

    if (conductivity < threshold && conductivity > 200) {
        analogWrite(pumpPin, pumpSpeed); //first pump performs its function
        analogWrite(pump2Pin, 0); //second pump speed set to 0 to prevent it from running
    }
    else{                         //if conductivity exceeds the value of 200, but is less than the threshold
        analogWrite(pumpPin, 0);  // first pump speed set to 0
        analogWrite(pump2Pin, pump2Speed); //second pump performs its function
    }
