# The Charlies Planck Layout

### Quick Info
This repo contains the main files needed to make the Layout (with the exclusion of the *config.h* file which had the line: **#define BACKLIGHT_ENABLE** added to it.)

### Pictures
 [![My Planck](https://i.imgur.com/wmDgN6m.jpg)](https://imgur.com/a/vA7WB)
<!-- <img src="https://i.imgur.com/wmDgN6m.jpg" height="400" width="500"/> -->
[More Images](https://imgur.com/a/vA7WB).

### Visualized Keyboard Layers
[`Link to Keyboard Layout Editor`](http://www.keyboard-layout-editor.com/#/gists/f07e0c5b0fc7812dc0930851a72e94d3)

## Building keymap and flashing to planck
First obtain and install dfu-programmer on your linux system
To build your keymap, simply navigate to the root of the keymap folder in question (e.g Garry), begin a terminal session from that directory and run the 'make' command.
If all goes well and there are not build errors, the .hex file will get written to the root of the directory containing the entire project (where the main readme is located).
Open a terminal from root directory of the planck project (e.g. '/home/$USER/OLKB_planck/qmk_firmware-planck-4.1') put your planck in reset mode and run the following commands:

> sudo dfu-programmer atmega32u4 erase

> sudo dfu-programmer atmega32u4 flash $NAME_OF_GENERATED_HEX_FILE.hex

NOTE: Where $NAME_OF_GENERATED_HEX_FILE is a valid name of the hex file generated from the make operation.

