#!/bin/bash

if [ $# -lt 1 ]
then
    echo "Usage: $0 [-f] results_path"
    exit
fi

FORCECLEAN=false
CLEANDIR=$1

if [ "$1" == "-f" ]
then
    FORCECLEAN=true
    CLEANDIR=$2
fi

for D in $CLEANDIR/*; do
    if [[ ! -f $D/generation150.ser.gz && $FORCECLEAN == false ]]
    then
        echo -n "[$D]: Not yet finished: "
        ls $D/generation*
    else
        ls -l $D/fitness.* > /dev/null 2>&1
        if [ "$?" = "0" ]
        then
            rm -f $D/fitness.*                            
            echo "{$D} Cleaning fitness files..."
        fi

        ls -l $D/worker* > /dev/null 2>&1
        if [ "$?" = "0" ]
        then
            rm -f $D/worker*
            echo "{$D} Cleaning worker files..."
        fi
        if [ -f $D/global.err ]
        then
            rm -f $D/global.err
            echo "{$D} Cleaning error file..."
        fi
        if [ -f $D/*.tmp ]
        then
            rm -f $D/*.tmp
            echo "{$D} Cleaning tmp files..."
        fi
    fi
done


