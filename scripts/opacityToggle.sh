#!/bin/bash

a=$(ps aux | grep -F " picom " | grep -v grep)
if [ -n "$a" ]
then
    killall picom
else
    picom -b
fi
