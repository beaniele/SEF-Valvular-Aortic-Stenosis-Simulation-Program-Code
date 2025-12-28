//setting up the loop so that the system understands what the prototype needs to do when it meets a specific condition

void setup() {

pinMode(pumpPin, OUTPUT); //first pump set as output for specific condition

pinMode(pump2Pin, OUTOUT); //second pump set at output for specific considiton

SerialUSB.begin(9600); //serial monitor prints values @ 9600 baud rate

SerialUSB.println("Initiate Conductivity"); //serial monitor prints the phrase "Initiate Conductivity" to determine valid function of SM
}
