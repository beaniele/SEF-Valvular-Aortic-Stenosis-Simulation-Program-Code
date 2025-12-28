This is a response based prototype system that relies solely on conductivity values picked up by a simple sensor made by pure aluminum foil. Inspired by the rising problem and concern regarding calcification that occurs in aortic stenosis (valvular diseases, refer to the US Medical Library), this model acts as a blood incision based transfusion system, where a calcium mock (distilled water) will be sucked and exported out from the aortic valve (pump on ~11), and deposited into a separate compartment. After, blood mock (tap water) will be pumped back into the valve (pump on ~10) in order to stimulate the tissue within the valve once more i.e. stiff tissue prior to the procedure. This is purely a simulation as to what could be considered a self-proclaimed medical procedure that can be considered in the future if the success of the project is deemed as triumphant.

Note: Distilled water has conductivity greater than 0, but less than 1023
Note: Tap water has exactly 1023 conductivity, or fluctuates 2-3 units below the standard
Note: Serial monitor to be used for monitoring conductivity flow and accuracy.

## INSTALLATION SHOWN BELOW AKA THE PROCEDURE
#### In the case that anyone would like to replicate, execute and commit to this project, follow the procedure presented below, and feel free to tweak anything along the way!

Code/Main Algorithm
Using a Windows 11 Dell laptop, download or start up the application Arduino IDE
This is where the code for the prototype function and understanding will be written and applied
As mentioned prior, write and algorithm suited for the prototype and its main function to succeed on i.e. first pump when conductivity is low and calcium is needed to be deposited, second pump when conductivity reached analog threshold and blood is pumped in to help stimulate the tissue of the aorta, and the sensor to understand conductivity units, and send them back to the Serial Monitor to process and display as digital values
Make sure to call all variables being used (e.g. int pumpPin = 11 → states that the code will help a pump perform its function, and said pump receives electrical charge from ~11 i.e. pin 11 on the Arduino R4)
Once the code is done being written, take an Arduino Uno R4 Minima, and connect it to the laptop via USB-C cable.
Ensure that on the Serial Monitor, it displays “Port: COM6” alongside/or “Connected to Arduino Uno R4 Minima.” This is to ensure that the USB-C cable and the IDE are cooperating with each other, and that both electrical charge and data is capable of being sent back and forth through the USB-C cable
Compile the code, then upload it onto the Arduino using the pre-set buttons provided in the IDE’s platform. 
If the code successfully compiles without problem, and is able to upload onto the board without any error, move on to the next section of the procedure i.e. building the circuit that will act as the “foundation” of the prototype
Else i.e. there is an error or problem during the compiling and uploading process of the code, acknowledge error messages displayed in the “OUTPUT” tab - otherwise known as the terminal in Arduino IDE - and debug the code accordingly until there is no error present during the compiling and uploading process.

Circuit
Using various electrical components - jump wires, connectors, etc. - build a circuit that will respond well and send energy throughout metallic channels for the pumps and sensor to receive.
Take a breadboard and position it so that the letters a-j (respectively lowercase) are facing upright and are at the very top of the presented breadboard
5V pin on Arduino: main source of electrical charge that the circuit will be receiving from; connect to LP1 i.e. the very first port of the positive channel on the left powerbus of the breadboard via jump wire.
GND pin on Arduino: otherwise known as “ground” - return reference point for energy once it has finished one cycle around the circuit i.e. the return path and spot for the electrical current before circulating back into the port for 5V; connect to LN1 that is the very first port of the negative channel on the left powerbus of the breadboard via jump wire.
~A0: analog pin, provides digital numbers 0-1023 once voltage from sensors has been detected, basically analog units being converted to digital, readable units that are therefore displayed on the Serial Monitor; connect to f20 on the breadboard
~11: pin that the first pump will receive electrical currents from in order to carry out its function; connect to g7 on the breadboard.
Resistor (100k ohms): recycler of excess energy that is not being used by MOSFET. Connect from i16 - i20. This makes it so that any energy being shared by the sensor and the first pump does not exceed the limit to which they are allowed. Resistors keep the circuit from short-circuiting.
MOSFET: redirector of energy and overload. Connect f5-f7. Plays a key role in energy recycling, but not as "huge" compared to a resistor
Use a second breadboard to replicate a separate “server” for the second pump
~10 = pin the second pump received electrical currents from. Connect to g7 of the second breadboard.
MOSFET = f5-f7 of second breadboard.
Resistor = i16 - i20 of second breadboard.
Connect the second breadboard to the first breadboard through the connector pieces instilled on their main body. The first breadboard’s bottom edge should be connected to the second breadboard's top edge. 
Using connector pieces, connect the two very bottom ports of the left power bus of the first breadboard to the two topmost ports of the second breadboard. Repeat this process for the right powerbus. (topmost of the second breadboard and bottom most of the first breadboard connected via electrical connectors).
On the bottom most ports of the second breadboard, run a connector from LP30 to RP30. Do the same for the negative probe -> LN1 - RN30. This ensures that electrical energy is able to run through both boards and both sides of power buses.
Connect Analog to the second breadboard, where a connector will be used to redirect the energy from the pin on the first breadboard, to the second breadboard (refer to CCAD at the very bottom.)
Ensure that every pin that is connected to the breadboard is also connected to the Arduino R4.

Main Body
Take three glass containers, one of medium size, and two that are somewhat smaller that the medium sized one, yet are able to hold a sizable amount of liquid in each.
Label the medium sized one "Main aorta body." Label one of the smaller ones "calcium deposit." Label the remaining small container "blood mock"
Rearrange the bowls so that it goes from: Main Aorta body → blood mock → calcium deposit.
Make a sensor out of aluminum foil, by cutting a small strip and folding it lengthwise, before placing it in the main aorta body. Make sure that there are flaps that are at least 1-2 centimeters above the rim of the container. This is to ensure that the sensor can be connected to the circuit via alligator clips (do so once the step has been completed.)
Connect the positive probe of the suction pump to RP1 and the negative probe to j6 on the first breadboard using alligator clips or connectors.
Place the suction pump in the container labeled main aorta body.
Connect the positive probe of the second pump to RP2 and negative to j6 of the second breadboard using connectors.
As a final thought, rearrange all of the components of the prototype so that the containers are lined up, the breadboard is in front of the containers, and the arduino is in front of the breadboard.

# for the code, reference the commits in this repositoty. For the CCAD and the regular CAD, reference the files presented in this repository.
