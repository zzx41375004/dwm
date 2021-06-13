#!/bin/bash

id=$(xinput list | grep Touchpad | sed -r 's/.*id=([0-9]*).*/\1/')
if [ $id ]
then
    str=$(xinput list-props $id | grep Enabled)
    if [ -n "$str" ]
    then
        status=$(echo $str | sed -r 's/.*:\s*([0-9]).*/\1/')
        id1=$(echo $str | sed -r 's/.*\((.*)\).*/\1/')
        if [ $status == 0 ]
        then
            xinput set-prop $id $id1 1
        else
            xinput set-prop $id $id1 0
        fi
    fi
fi

