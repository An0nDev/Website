#!/bin/bash

if [ -z "$COMPILER" ]; then COMPILER=clang++-10; fi

$COMPILER \
    -std=c++2a \
    -fPIC -shared \
    -lHTStack \
    App.cpp -o App.so
