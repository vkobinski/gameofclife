#!/bin/sh

set -xe

CFLAGS="-Wall -Wextra  -pedantic"
cc $CFLAGS -o main main.c
