#!/bin/bash

DROITS=641
nb=`ipcs -q | grep $USER | grep $DROITS | wc -l`

if [ $nb -eq 0 ]
then
    echo "aucune file à détruire"
else
    pluriel=""
    if [ $nb -gt 1 ]; then pluriel="s"; fi
    echo "vous avez $nb file$pluriel non détruite$pluriel";

    for id in `ipcs -q | grep $USER | grep $DROITS | awk '{print $2;}'`
    do
        echo "  destruction file " $id
        ipcrm -q $id
    done

    nb=`ipcs -q | grep $USER | grep $DROITS | wc -l`
    pluriel=""
    if [ $nb -gt 1 ]; then pluriel="s"; fi
    echo "il reste $nb file$pluriel non détruite$pluriel";
fi
