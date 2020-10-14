#!/bin/bash

cd HTStack
git pull origin master
cd ..

clang++-10 \
    -std=c++2a \
    -fPIC -shared \
    -lHTStack \
    App.cpp -o App.so
