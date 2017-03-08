#!/bin/bash

BOARD="uno"
while [[ $# -gt 1 ]]
do
key="$1"

case $key in
    -b|--board)
    BOARD="$2"
    shift # past argument
    ;;
    *)
            # unknown option
    ;;
esac
shift # past argument or value
done
platformio init --ide clion --board $BOARD
