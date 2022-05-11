#!/bin/bash

DROITS=641
nb=`ipcs -m | grep $USER | grep $DROITS | wc -l`

if [ $nb -eq 0 ]
then
    echo "aucun segment à détruire"
else
    pluriel=""
    if [ $nb -gt 1 ]; then pluriel="s"; fi
    echo "vous avez $nb segment$pluriel non détruit$pluriel";

    for id in `ipcs -m | grep $USER | grep $DROITS | awk '{print $2;}'`
    do
        echo "  destruction segment " $id
        ipcrm -m $id
    done

    nb=`ipcs -m | grep $USER | grep $DROITS | wc -l`
    pluriel=""
    if [ $nb -gt 1 ]; then pluriel="s"; fi
    echo "il reste $nb segment$pluriel non détruit$pluriel";
fi
