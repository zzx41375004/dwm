#!/bin/bash

# setxkbmap us colemak
fcitx5 &
sleep 1
setxkbmap us colemak -option -option caps:swapescape
