# Cistercian keyboard

Keypad with cipher numerals.

![Cistercian keyboard](doc/IMG_9179.jpg)

<img src="doc/IMG_9125.jpg" width="300" height="200">
<img src="doc/IMG_9132.jpg" width="300" height="200">
<img src="doc/IMG_9133.jpg" width="300" height="200">
<img src="doc/IMG_9134.jpg" width="300" height="200">
<img src="doc/IMG_9136.jpg" width="300" height="200">
<img src="doc/IMG_9146.jpg" width="300" height="200">
<img src="doc/IMG_9152.jpg" width="300" height="200">
<img src="doc/IMG_9158.jpg" width="300" height="200">
<img src="doc/IMG_9159.jpg" width="300" height="200">
<img src="doc/IMG_9161.jpg" width="300" height="200">
<img src="doc/IMG_9163.jpg" width="300" height="200">
<img src="doc/IMG_9176.jpg" width="300" height="200">
<img src="doc/IMG_9180.jpg" width="300" height="200">

<img src="doc/IMG_9140.jpg" width="300" height="200">

## Story

This keyboard is for me more of an art project. And the opportunity to learn how things work. What is the underlying code and history! Arouse people's curiosity.

### What are Cistercian numerals

The medieval number system was invented by Cistercian order in Europe in the 13th century. Cistercian are a Catholic religious order of monks and nuns. They used, amongst themselves, a secret number notation. No one really knows about it until about 20 years ago, a Brithis orientalist and historian [David A. King](https://en.wikipedia.org/wiki/David_A._King_(historian)) wrote a book about it. It was used by various different groups for kinds of medieval cyphers and secret number systems. It is a system that can only write every number from 0 to 9999. It can not to any other numbers. It is really easy to use for dates and page numbers of books.

![Cistercian numerals](doc/numbrid.jpg)

## Hardware components

- Seeed XIAO-RP2040
- Custom PCB (Made by [Seeed Fusion](https://www.seeedstudio.com/fusion.html))
- Keyboard switches (20 pcs)
- USB-C to USB-A cable
- Selfmade keyboard housing (birch plywood, screws)
- Selfmade keycaps (solid oak and birch plywood)

### XIAO-RP2040

It uses Raspberry Pi RP2040 chip like Pico.

XIAO RP2040 has:

- Small size 20x17.5 mm
- USB-C
- 11 pins + power pins
- Reset button
- Boot button
- RGB LED (user-programmable)
- Power LED (2 colour)
- User LED
- 264KB SRAM and 2MB Flash memory
- Dual-core ARM Cortex M0+ processor, 133 MHz
- 3.3V!

![XIAO-RP2040 front](doc/xia_front.jpg)

![XIAO-RP2040 pins](doc/xia_pin.jpg)

### Custom PCB

My design contains four columns and five rows of switches.
Next time, I'd leave more space between the switches. Right now they are quite tight.
It's the first time when I ordered yellow PCBs. I think it's a good fit with my wooden mechanical keycaps and housing.

PCBs are made by [Seeed Fusion](https://www.seeedstudio.com/fusion.html). I ordered five and two assembled. I think they look nice. Pads are gold plated. Only one PCB has some kind of colour drip. Otherwise they look and feel good.

![Schematic](doc/skeem.png)

![My PCB](doc/pcb01.png)

<img src="doc/IMG_8955_01.jpg" width="300" height="200">
<img src="doc/IMG_8975.jpg" width="300" height="200">
<img src="doc/IMG_8982.jpg" width="300" height="200">
<img src="doc/IMG_8989.jpg" width="300" height="200">
<img src="doc/IMG_8995.jpg" width="300" height="200">
<img src="doc/IMG_9014.jpg" width="300" height="200">

### Keycaps

Keycaps are made the same way as on my previous keyboard. Which can be found [here](https://taunoerik.art/portfolio/keyboard/). Only that this time engraving them by hand. Not with a laser.

<img src="doc/klahvid01.jpg" width="300" height="200">
<img src="doc/IMG_9060.jpg" width="200" height="300">
<img src="doc/IMG_9064.jpg" width="300" height="200">
<img src="doc/IMG_9078.jpg" width="300" height="200">
<img src="doc/IMG_9079.jpg" width="300" height="200">
<img src="doc/IMG_9099.jpg" width="300" height="200">
<img src="doc/IMG_9107.jpg" width="300" height="200">
<img src="doc/IMG_9114.jpg" width="300" height="200">
<img src="doc/IMG_9119.jpg" width="300" height="200">

Viimistlus!!


### Design ideas

The main components are the keycaps. And everything else is as minimum as possible.

images!!!!

## Software

First I planned to use PlatformIO with the Arduino framework, but this board (XIAO-RP2040) is not yet supported.

There have a multiple choices to program it:

- CircuitPython/MicroPython and [Thonny](https://projects.raspberrypi.org/en/projects/getting-started-with-the-pico/2)
- Arduino IDE
- [Raspberry Pi Pico C/C++ SDK](https://www.raspberrypi.com/documentation/microcontrollers/raspberry-pi-pico.html)
- PlatformIO with the Arduino framework

## Links

- [The Forgotten Number System - Numberphile
](https://www.youtube.com/watch?v=9p55Qgt7Ciw)
- [Cistercian numerals](https://en.wikipedia.org/wiki/Cistercian_numerals)
- [Cipher](https://en.wikipedia.org/wiki/Cipher)
- [Cipher runes](https://en.wikipedia.org/wiki/Cipher_runes)
- [Seeed XIAO RP2040](https://www.seeedstudio.com/XIAO-RP2040-v1-0-p-5026.html)
- [Seeed XIAO RP2040 wiki](https://wiki.seeedstudio.com/XIAO-RP2040-with-Arduino/)
- [David A. King](https://en.wikipedia.org/wiki/David_A._King_(historian))
- 
