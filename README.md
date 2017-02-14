# Libftprintf

[![Build Status](https://travis-ci.org/Lexouu77/Libftprintf.svg?branch=master)](https://travis-ci.org/Lexouu77/Libftprintf)

### Printf:

%[[FLAGS]c :
`[FG|BG]_[RED|BLU|GRN|YEL|MAG|CYA|WHI|CSM]`
```[Foreground|Background]_[Red|Blue|Green|Yellow|Magenta|Cyan|White]```
CSM e.g. `%[[FG_CSM$VAL]` $VAL from 0 to 255
`[SP]_[RST|BOL|UND|REV|FGR|BGR]`
```[Special]_[Reset|Bold|Underligned|ReversedColor|ForegroundReset|BackgroundReset]```


e.g. `%[[FG_RED,SP_RST]s` -> display the string in red then reset to black after the display of the string.

Todo:
- Opti everything.
- Remake printf with custom colors.
