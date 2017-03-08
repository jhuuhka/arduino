#!/bin/bash

PORT="USB0"
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
    PORT="$2"
    ;;
    *)
            # unknown option
    ;;
esac
shift # past argument or value
done

platformio device monitor -p /dev/tty$PORT -b $BAUD
