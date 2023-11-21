# Assignment 2

## Description:

This test harness (sorting) is a command line option program that accepts certain commands to print the sorted array, comparing different sorting function.

## Building with Makefile
The following commands will build the sorting executable.
```
make
```
```
make all
```
```
make sorting
```

## Cleaning with Makefile:
The following command will remove all files that are compiler generated.
```
make clean
```

## Formatting with Makefile:
The following command will format all source code, including the header files.
```
make format
```

## Running with command-line options

SYNOPSIS

   A collection of comparison-based sorting algorithms.

USAGE

   ./sorting [-Hasbhqn:p:r:] [-n length] [-p elements] [-r seed]

   For example, the following will run all sorts with 75 elements in random array generated with seed 1234
```
./sorting -a -n 75 -r 1234
```

OPTIONS

 -H              Display program help and usage.

 -a              Enable all sorts.

 -s              Enable Shell Sort.

 -b              Enable Batcher Sort.

 -h              Enable Heap Sort.

 -q              Enable Quick Sort.

 -n length       Specify number of array elements (default: 100).

 -p elements     Specify number of elements to print (default: 100).

 -r seed         Specify random seed (default: 13371453).


## Citation
Ben Grant, bit masking, bit tracking, bit length calculation

Ben Grant, set functions, set compare

Miles, batcher sort, stats tracking

https://www.geeksforgeeks.org/sorting-algorithms/


