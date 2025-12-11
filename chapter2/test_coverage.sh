#!/bin/sh
./main_test
for i in *gcda; do 
    gcov $i;
done;

grep -C3 '#####' *.c.gcov