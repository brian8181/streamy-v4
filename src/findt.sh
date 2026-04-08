#!/usr/bin/env bash

# func:"main" ~ file:"src/driver.cpp" ~ line:178 ~ Apr  8 2026, 10:05:51

FILE=$(head -n1 tmp_trace.txt | grep --text TRACE | sed -E "s|^.*func:\"(.*)\" ~ file:\"(.*)\" ~ line:(.*) ~ .*$|\2|")
LINE=$(head -n1 tmp_trace.txt | sed -E "s|^.*func:\"(.*)\" ~ file:\"(.*)\" ~ line:(.*) ~ .*$|\3|")
#head -n1 "./${FILE}" | sed -n "${LINE}p"