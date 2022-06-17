#!/bin/sh
bin=$(basename -- "$1")

# Detect and kill potentially existing zombie/phantom instances 
pid=$(pgrep "$bin")
if [ ! -z "$pid" ]
then 
    echo "Killing existing zombie/phantom instance(s) (pid(s): $pid)"
    kill -9 $pid
fi

echo "Launching $bin"
exec ./$1
