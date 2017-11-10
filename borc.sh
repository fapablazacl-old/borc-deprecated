#!/bin/bash

action=$1

# run action
if [ $action == "run" ]
then
    # run the specified target
    object=$2

    ./build/src/$object/$object

    exit
fi

# 
if [ $action == "build" ]
then
    cd build
    make 
    cd ..

    exit
fi

echo "Unknown '$action' command"
