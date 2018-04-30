# Figures

## Configuration instructions

### Required hardware:
	
1. [Raspberry Pi](https://en.wikipedia.org/wiki/Raspberry_Pi), 
	Model 3B ( further: [RPi](https://en.wikipedia.org/wiki/Raspberry_Pi) )

2. ["RJ45" Ethernet cable](https://en.wikipedia.org/wiki/Modular_connector#8P8C) 
	( further: [e-cable](https://en.wikipedia.org/wiki/Modular_connector#8P8C) )

3. Power supply for the [RPi](https://en.wikipedia.org/wiki/Raspberry_Pi) 
	( one of the following ):
	- USB cable + seperate device's USB port ( PC, laptop, etc. )
	- [Common external power supply](https://en.wikipedia.org/wiki/Common_external_power_supply)

4. Main operating computer ( PC, laptop, etc.; further: MOC )

### Required hardware set-up:

1. Connect the [RPi](https://en.wikipedia.org/wiki/Raspberry_Pi) to the 
	Internet using the [e-cable](https://en.wikipedia.org/wiki/Modular_connector#8P8C)

2. Connect the [RPi](https://en.wikipedia.org/wiki/Raspberry_Pi) to the power supply

## Installation instructions

### Required software:
	
1. [RPi](https://en.wikipedia.org/wiki/Raspberry_Pi) files ( 
	[RPi](https://en.wikipedia.org/wiki/Raspberry_Pi) )

2. [PuTTY](https://en.wikipedia.org/wiki/PuTTY) ( 
	[MOC](https://github.com/roman-bezusiak/Sound-proj.#required-hardware) )

## Operating instructions

1. Launch the [RPi](https://en.wikipedia.org/wiki/Raspberry_Pi)

2. Connect to the [RPi](https://en.wikipedia.org/wiki/Raspberry_Pi) via 
	[PuTTY](https://en.wikipedia.org/wiki/PuTTY)

3. Make the object files and the _sound.a_ application by running 
	the following command:

```
~$ make
```

4. Run the application by entering the following command:

```
~$ ./figures.a
```

## File manifest

### List:

- [RPi](https://en.wikipedia.org/wiki/Raspberry_Pi) ( **_5_** ):
	- **_.c_ files** ( **_3_** ):
		- display.c
		- main.c
		- makeFigure.c
	- **_.h_ files** ( **_1_** ):
		- comm.h
	- **_Other_ files** ( **_1_** ):
		- makefile

- Other ( **_2_** ):
	- README.md
	- LICENCE

#### Total: **_7_** files

## Copyright and licensing information

This project is licensed under the 
[**GNU General Public License**](https://en.wikipedia.org/wiki/GNU_General_Public_License). 
See the [_LICENSE_](LICENSE) file for details

## Credits and acknowledgments

### Authors:
- **Roman Bezusiak** - _Initial work_ - 
	[Roman Bezusiak ( GitHub profile )](https://github.com/roman-bezusiak)

### Used resources:
- **[Wikimedia Foundation Inc.](https://wikimediafoundation.org/wiki/Home), 
	Wikipedia** - _Encyclopedia materials_ - 
	[wikipedia.org](https://www.wikipedia.org/)