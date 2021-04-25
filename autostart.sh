#!/bin/bash

xrandr --auto --output HDMI-A-0 --same-as eDP --size 1920*1080
xrandr --auto --output DisplayPort-0 --same-as eDP --size 1920*1080
# xrandr --auto --output DisplayPort-0 --same-as eDP --size 1920*1080
fcitx5&
~/dwm/scripts/dwm-status.sh
~/dwm/scripts/exchangeCaps.sh
~/dwm/scripts/inverse-scroll.sh
