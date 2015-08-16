# Remote Interface for LeoCAD

This project has the goal to add a remote interface to LeoCAD. It should be
possible to add and remove (some) bricks.

# Interface

With this version, LeoCAD starts a TCP server on port 29994. Since the interface
is textual, a client like telnet is all you need.

## Syntax
    Line      = Command NEWLINE
    Command   = Nop | Hello | Clear | Add
    Nop       =
    Hello     = "hello" "from" Name
    Name      = String
    Clear     = "clear"
    Add       = "add" Type Color Position Angle
    Type      = String
    Color     = String
    Position  = INTEGER INTEGER INTEGER
    Angle     = INTEGER
    String    = STRING | ("\"" {STRING | WHITESPACE} "\"")

### Examples

Connect to the running LeoCAD server:

    telnet 127.0.0.1 29994

Add a brick at the center with a rotation of 90 degree:

    add 3001 red 0 0 0 90

Add the same brick on top of the last:

    add "Brick 2 x 4" blue -1 0 1 0

And remove all

    clear

### Semantic

Only a subset of bricks are supported. These are:

* 3001, "Brick 2 x 4"
* 3003, "Brick 2 x 2"
* 3028, "Plate 6 x 12"
* 3867, "Baseplate 16 x 16"

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

