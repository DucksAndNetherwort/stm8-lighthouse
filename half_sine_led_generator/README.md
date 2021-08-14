# STM-8 Lighthouse

A project using the STM-8 microcontroller to blink an LED in a half sine pattern, for the sake of imitating lighthouses.  
With configurable frequency/amplitude, this is perfect for lighthouses.  
Complete with four brightness settings, and 6 frequency settings, you can have it look exactly as you want.  

The button nearer the USB connector will adjust the frequency with which the LED blinks,  
and the other button adjusts the brightness.

Holding a button will show a representation of the new setting on the LED, with the brightness shown rising with the brightness/frequency.

note: add information about enclosures and programmer

The standard enclosure doesn't have sufficient room to accommodate programming pins, though it is rather a bit smaller than the dev version, allowing it to be integrated in smaller spaces.

The dev version of the enclosure has more length and a cutout for a programming header, allowing the STM-8 to be reprogrammed without too much hassle.

## Programmer Setup

The programmer should come with a little strip of four wires with connectors, you'll need that.

The programmer itself has it's pinout printed on it, so use that to reference what goes where.

- put the white wire on `rst`
- put the brown wire on `swim`
- put the black wire on `gnd`
- put the red wire on `3.3v`
- wrap the end opposite the programmer in tape, making sure the connectors are in a line, and the wires are in the order of white, black, brown, red
- if you'll be programming an STM-8 that is going in a standard enclosure, this is when you put a strip of four header pins in the end of the connector, making sure the pins stick out parallel to the board of the STM-8

## How To Program The STM-8

  Note: you will need at least two vacant USB ports on the same computer for this to work.

- plug the STM-8 into the machine being used for programming via the micro USB port
- plug the programmer into the same machine
- if the STM-8 is going in the standard enclosure:
  -  slot the header pins into the programming holes, making sure the red wire goes to `3v3` (right side of board)
  -  click `upload` in Arduino IDE
  -  hold some torque on the programming pins to ensure proper contact with the holes
  -  keep holding until the indicator on the programmer stops flashing
- if the STM-8 is in a dev enclosure, just slide the programmer on so that the red wire goes to the right when the buttons face down, before clicking `upload` and waiting for it to finish

## Build Guide:

First, program the STM-8.

Then, install the buttons.

- start by flipping the base upside down
- make sure the holes are free of any debris
- ensure the leads of the buttons are straight
- next, insert the buttons in the square holes, making sure the leads go into the slots
- if the buttons won't go in, use a file to remove a little material from the sides of the holes
- flip the enclosure over, and make sure the leads of the buttons are sticking out of the slots

Finally, just about everything else. (for the 4-wire buttons, just make sure the ground and signal wires are diagonal from each other)

 - solder a short piece of wire to one lead of one button
 - use another bit of wire to connect the lead you soldered to a lead of the other button
 - solder a longer piece of wire to one of the soldered button leads (this needs to reach the LED) and feed it through the hole
 - orient the STM so the USB connector is facing up, and the end with the connector faces the end of the enclosure with the slot
 - take another wire of the same length (different color recommended) and solder it to the pin marked `C3`, and feed it through the hole
 - solder short-ish bits of wire to the unsoldered leads of the buttons, these need to go to the STM, while fitting under it when assembled
 - solder the wire of the button closer to the end of the STM with the USB connector to `D2`
 - solder the wire of the other button to `D1`  (which button goes where isn't really important, so long as you remember which is which)
 - press the STM into the enclosure, making sure it seats all the way at the bottom, and that you can access the USB connector
 - slide the lid on the enclosure, if it doesn't go on all the way, reverse it and try again
 - solder an LED to the ends of the protruding wires, making sure the ground lead (flat side/short lead) goes to the ground wire
 - plug it into USB power and make sure it works
 - Done