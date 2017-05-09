#!/bin/sh

export PROJROOT="./"
export OUTDIR="${PROJROOT}/build/"
OUTFILE=${OUTDIR}/$1

COMMENT_FILE(){
  cat $1 | sed -e 's/^/\/\/ /' >> $OUTFILE
}

ECHO_FILE(){
  echo -e $1 >> $OUTFILE
}

CAT_FILE(){
  cat $1 >> $OUTFILE
}

if [ -e $OUTFILE ]; then
  rm -rf $OUTFILE
fi

ECHO_FILE "// NOTE: file generated automatically from 'sorted' source; do not edit by hand\n"

COMMENT_FILE "${PROJROOT}/LICENSE"
# ECHO_FILE "\n// Changelog:"
# COMMENT_FILE "${PROJROOT}/ChangeLog"

ECHO_FILE "\n"
ECHO_FILE "#ifndef __SORTED_H__"
ECHO_FILE "#define __SORTED_H__"
ECHO_FILE "\n"


CAT_FILE "${PROJROOT}/src/cdefs.h"
ECHO_FILE "\n\n"

if [ -z "$2" ]; then
  FILES=`ls src/*.h | sed -e 's/^.*cdefs.h//'`
  for f in $FILES; do
    ECHO_FILE "// ${f}"
    CAT_FILE $f
    ECHO_FILE "\n\n"
  done
else
  CAT_FILE "${PROJROOT}/$2"
fi


ECHO_FILE "#endif"



echo "DONE!"
