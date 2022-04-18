# Tamer Elsawaf
# cssc0445@edoras.sdsu.edu
# CS 570 Spring 2022
# Project #1, Hex & Binary Converter
# makefile
all: xed

xed: xed.cpp
	g++ -o xed xed.cpp
clean:
	rm -f xed
