#!/usr/bin/bash

EXE=$0

function PrintSrc
{
    local FMT_GREY='\x1B[90m'
    local FMT_ITALIC='\x1B[3m'
    local FMT_RESET=

    echo -e "${FMT_GREY}${FMT_ITALIC}<code>\n$(cat $0)\n</code>"
}

echo .
echo "-[@#$%^&*()_+{}|:\"<>?=\;',.\/[-"; echo "-[@#$%^&*()_+{}|:\"<>?=\;',.\/[-" | sed -E  "s/[]~@#$%^&*()_+{}|:\"<>?=\;',.\/[-]/./g"
echo .
echo bye.

PrintSrc ${EXE}
echo -e '\x1B[0m'
