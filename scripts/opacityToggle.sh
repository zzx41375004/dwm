#!/bin/bash

a=$(ps aux | grep picom | grep -v grep)
if [ -n "$a" ]
then
    killall picom
else
    picom
fi
