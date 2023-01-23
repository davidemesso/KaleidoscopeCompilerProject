#!/bin/bash

./kfe -o run $1 && clang++ -o run run.o && ./run