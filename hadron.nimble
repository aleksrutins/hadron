# Package

version       = "0.1.0"
author        = "Aleks Rutins"
description   = "A lightweight, cross-platform text editor"
license       = "MIT"
srcDir        = "src"
installExt    = @["nim"]
bin           = @["hadron"]


# Dependencies

requires "nim >= 1.6.10"
requires "nimgl >= 1.0.0"
requires "https://github.com/nimgl/imgui.git"