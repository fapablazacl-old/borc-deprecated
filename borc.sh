#!/bin/bash

action=$1

if [ $action == "run" ]
then
    # run the specified target
    object=$2

    ./build/src/$object/$object
else
    echo "Unknown '$action' command"
fi
