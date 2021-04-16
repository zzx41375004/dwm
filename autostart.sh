#!/bin/bash

xrandr --auto --output HDMI-A-0 --output DisplayPort-0 --same-as eDP --size 1920*1080
xrandr --auto --output DisplayPort-0 --same-as eDP --size 1920*1080
# xrandr --auto --output DisplayPort-0 --same-as eDP --size 1920*1080
~/dwm/scripts/dwm-status.sh
~/dwm/scripts/exchangeCaps.sh
~/dwm/scripts/inverse-scroll.sh
