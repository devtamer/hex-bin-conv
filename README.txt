README
===========
    Tamer Elsawaf 
    cssc0445@edoras.sdsu.edu 
    CS 570 Spring 2022 
    Project #1, Hex & Binary Converter 
    README.txt

File Manifest
=============

-   source file: xed.cpp
-   include file: include_file.txt
-   makefile

Requirements
============

-   g++ (GCC) v4.8.5 or newer
-   Make

Compilation
===========

The code can be compiled with the provided makefile using the standard
`make` command.

Compilation Continued & Operation Instructions
==============================================

first compile the program via the make command by running the below in
the command line

    make

If run without command line arguments like below

    ./xed

the following error usage message will be displayed.

    No file provided!

so make sure you provide an include file to convert!

to print hex, run using

    ./xed <filename>

the input file will be printed in hex, for example

    |00000210: 2073 6571 7561 7475 722e 2071 7569 6420    sequatur. quid |
    |00000220: 7265 7075 676e 6574 2e20 7669 6465 6e74   repugnet. vident|
    |00000230: 2e20 4961 6d20 6964 2069 7073 756d 2061   . Iam id ipsum a|
    |00000240: 6273 7572 6475 6d2e 206d 6178 696d 756d   bsurdum. maximum|

to print in binary, run using

    ./xed -b <filename>

the input file will be printed in binary, for example

    |00000460: 01111000 01101001 01110011 01110100 01101001 01101101  xistim|
    |00000470: 01100001 01110010 01100101 00101110 00100000 01110001  are. q|
    |00000480: 01110101 01101001 00100000 01101100 01100101 01100111  ui leg|
    |00000490: 01100101 01110010 01101001 01101110 01110100 00101110  erint.|

if you want to delete (clean) the program for recompilation

    make clean


then to recompile just run

    make


as we did at the beginning

Design Decisions
================

-   Setup helper functions for hex conversion and binary respectively
-   Was able to allocate less memory reading into buffer designated\
    for exact file size versus storing in a vectory and looping through
    it

Extra Features / Functionality
==============================

-   Included a frame around the print to make it look cleaner when the
    output was printed
-   Included buffer to allocate exact memory needed by whatever file the
    user inputs

Lessons Learned
===============

-   my first attempted I used multiple vectors to loop through the
    files\
    this in turn took up more memory and complicated my helper functions
-   taking a step back I was able to approach the problem differently
    allowing for less memory allocation and more efficient run time
