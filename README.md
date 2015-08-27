# Remote Interface for LeoCAD

This project has the goal to add a remote interface to LeoCAD. It should be
possible to add and remove (some) bricks.

# Interface

With this version, LeoCAD starts a TCP server on port 29994. Since the interface
is textual, a client like telnet is all you need.

## Syntax
    Line      = Command Newline
    Command   = Nop | Hello | Clear | Add
    Nop       =
    Hello     = "hello" Plate Color Server
    Plate     = "plate12x12"
    Server    = String
    Clear     = "clear"
    Add       = "add" Type Color Position Angle
    Type      = "3001" | "3003"
    Color     = "black" | "blue" | "green" | "red" | "brown" | "yellow" | "white"
    Position  = INTEGER INTEGER INTEGER
    Angle     = "0" | "90" | "180" | "270"
    String    = Symbol { Symbol }
    Symbol    = 'a..z' | 'A..Z' | '0..9' | "-" | "_" | "." | "*" | "@" | "%" | "&"
    Newline   = "\n" | "\r" | "\n\r" | "\r\n"

### Examples

Connect to the running LeoCAD server:

    telnet 127.0.0.1 29994

Add a 4*2 brick at the center with a rotation of 90 degree:

    add 3001 red 0 0 0 90

Add a 2*2 brick on top of the last:

    add 3003 blue -1 0 1 0

And remove all

    clear

### Semantic

Only a subset of bricks are supported. These are:

* 3001, 2*4
* 3003, 2*2

Only a subset of colors are supported. These are

* black
* blue
* green
* red
* brown
* yellow
* white

The position is in "brick coordinates". It is:

      ^ +------------+
    1 | | o  o  o  o |
    0 | | o  o  o  o |
      y +------------+
        x------------>
          0  1  2  3
    
    1 ^  _-__-__-__-_
      | |            |
    0 | |____________|
      z

The angle is in degrees, only 0, 90, 180 and 270 is officially supported.

