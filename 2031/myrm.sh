#!/bin/bash

 mkdir -p /tmp/sharmzz/eecs2031m/a1/recycle-bin
#$* has infite amount of possibilites
number=$*
#as long as it is greater than 0 go into the if statement 
if [ "$number" > 0 ]
        then 
        for  x in $number #x is the specific file in number file
    do
        echo deleting $x #deleting individually so one by one
         mv $x  /tmp/sharmzz/eecs2031m/a1/recycle-bin

        
        done



#if its 0 then print this 
else
        echo “Error:no target specified”
        echo “Usage:./da.sh  -files-”

fi
