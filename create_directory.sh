#!/bin/sh

#######################
# DEFINE:             #
#######################
#NAME="<your_name>"
#PISCINE_FOLDER="$HOME/afs/<your_piscine_path>"
#SCRIPT_PATH="$HOME/afs/<your_chlorine_path>"
#
# Exemple:            
#   NAME="flo"
#   PISCINE_FOLDER="$HOME/afs/Documents/Piscine/EXERCISES"
#   SCRIPT_PATH="$HOME/afs/Documents/Piscine/piscine_chlorine_test"
#######################

FOLDER=""
PROJECT=""
REGEXEND="_test.c"

if [ $# -ge 1 ]; then
    while [ $# -ne 0 ]; do
        if [ "${FOLDER}" == "" ]; then
            FOLDER=$1
        else
            PROJECT=$1
        fi

        shift
    done

    if [ "$FOLDER" != "" ]; then
        FOLDER_NAME="$SCRIPT_PATH/$FOLDER"
        mkdir $FOLDER_NAME
        if [ "$PROJECT" != "" ]; then
            SCRIPT="$FOLDER_NAME/${PROJECT}_${NAME}$REGEXEND"
        else
            SCRIPT="$FOLDER_NAME/${NAME}$REGEXEND"
        fi
        touch "$SCRIPT"

        mkdir "$PISCINE_FOLDER/$FOLDER"
        cp "$SCRIPT_PATH/Makefile" "$PISCINE_FOLDER/$FOLDER"

        if [ "$PROJECT" != "" ]; then
            touch "$PISCINE_FOLDER/$FOLDER/$PROJECT.c"
        fi

        ln -s $SCRIPT "$PISCINE_FOLDER/$FOLDER"

        cd "$PISCINE_FOLDER/$FOLDER"
    fi
fi
