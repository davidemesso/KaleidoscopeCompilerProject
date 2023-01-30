#!/bin/bash

./kfe -v -o run $1 && clang++ -o run run.o && ./run