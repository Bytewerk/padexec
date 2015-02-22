# padexec
Execute shell commands with your game controller (&lt;70 LOC, based on SDL2).


## Requirements
* git (to get the source code)
* SDL2
* very little C programming knowledge *(you'll need to hack a C file `:O!`)*

## Usage
* Grab the source code:
`git clone https://github.com/Bytewerk/padexec.git`
* Read [padexec.c](https://github.com/Bytewerk/padexec/blob/master/padexec.c), it contains a full explanation on how this works and what you'll need to do
* ???
* PROFIT!

## Example Output
*Button 9 has been mapped to `mpc toggle` and gets pressed twice:*
```
./padexec.x86_64 
To make any use of this program, you'll need to hack up the source for your needs.

CONFIG_JOYSTICK_NAME: YuanChen Game Controller

Here's a list of attached joystick(s) (1 total):
        #0: YuanChen Game Controller

Yay, found the pad we were looking for \o/
Number of Axes: 5
Number of Buttons: 12
Button: 9
Alice Cooper - Bed of Nails
[paused]  #4/14   0:54/4:20 (20%)
volume: 25%   repeat: off   random: off   single: off   consume: off
Button: 9
Alice Cooper - Bed of Nails
[playing] #4/14   0:54/4:20 (20%)
volume: 25%   repeat: off   random: off   single: off   consume: off
```
