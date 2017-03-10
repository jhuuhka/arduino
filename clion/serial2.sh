#!/bin/bash

PORT="/dev/ttyUSB0"
BAUD="115200"
while [[ $# -gt 1 ]]
do
key="$1"

case $key in
    -b|--baud)
    BAUD="$2"
    shift # past argument
    ;;
    -p|--port)
    PORT=/dev/tty"$2"
    ;;
    -i|--ip)
    PORT=192.168.8."$2"
    ;; 
    *)
            # unknown option
    ;;
esac
shift # past argument or value
done

platformio device monitor -p $PORT -b $BAUD
