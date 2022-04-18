// Tamer Elsawaf
// cssc0445@edoras.sdsu.edu
// CS 570 Spring 2022
// Project #1, Hex & Binary Converter
// xed.cpp


#include <iostream>
#include <stdio.h>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <bitset>

using namespace std;

// Converts a decimal value into a hexadecimal value, padding it with a 0 or chopping off extra data if necessary.
string hexVal(int dec) {
	stringstream tmp;
    tmp << std::hex << dec;
    string hex = tmp.str();
	if (hex.length() > 2) {
		hex = hex.substr(hex.length() - 2);
	} else if (hex.length() == 1) {
		hex = "0" + hex;
	}
	return hex;
}

// Converts a decimal value into a binary value
string binVal(int dec) {
	stringstream tmp;
	tmp << bitset<8>(dec);
	// print binary value
    return tmp.str();
}

int main(int argc, char ** argv) {
	// error checking for improper arguments
	if (argc <= 1) {
		cout << "No file provided!" << endl;
	} else {
		// variables for file 
		// buffer to store read file contents
		// filelen to store file char length for looping through with ease
		FILE *fileptr;
		char *buffer;
		long filelen;

		string currentFile; 
		// in case of binary conversion
        if (argc == 3)
        {
                if (strcmp(argv[1], "-b") == 0)
                {
                    
					// For each file provided as an argument
					currentFile = argv[2];

					// create file handle
					fileptr = fopen(currentFile.c_str(), "rb"); 

					// Check if we can open the file for reading
					if (fileptr == NULL) { 
						cout << "File could not be opened: " << currentFile << endl;
					}
                    // seek to read entire file to end
					fseek(fileptr, 0, SEEK_END);
					// store file length 
					filelen = ftell(fileptr); 
					// reset to beginning of the file
					rewind(fileptr); 

					// memory space with the size of the file we are reading
					buffer = (char *)malloc((filelen + 1) * sizeof(char));
					// read file into buffer
					fread(buffer, filelen, 1, fileptr); 
					// close file handler
					fclose(fileptr);
					

					// replace non printable characters with a period
					for (int i = 0; i < filelen; i++) { 
						if ((+buffer[i] >= 48 && +buffer[i] <= 57) || (+buffer[i] >= 65 && +buffer[i] <= 90) || (+buffer[i] >= 97 && +buffer[i] <= 122) || +buffer[i] == 32 || +buffer[i] == 46 ) {
							buffer[i] = buffer[i];
						} else {
							buffer[i] = '.';
						}
					}
					
					// find how many rows we are going to print
			        int rows = ceil(filelen / 6) + 1; 
					int placeholder = 0;

					// for each section of 16 bytes in the file
                    for (int i = 0, offset = i * 16; i < rows; i++) { 
						offset = i * 16;
						// place holder for 6 binarys octets
						placeholder = i * 6;

					// stream to print each output respectively 
				    stringstream binStream;
				    stringstream charStream;
					// index for tracking and implement proper spacing
                    int index = 0;
                    for (int x = 0; x < 6; x++)
                    { // For each byte (up until the 16th from the current offset) and not past the end of the file...
                        index++;
                        binStream << binVal((int)buffer[placeholder + x]) << (index % 6 == 0 ? "" : " ");
                        charStream << (isprint(buffer[placeholder + x]) ? buffer[placeholder + x] : '.');
                    }

                    printf("|%08x: %-48s  %-6s|\n", offset, binStream.str().c_str(), charStream.str().c_str());
			        }
					// free up memory
					free(buffer);
                }
				else {
					cout << "enter flag -b before the input file to convert to binary" << endl;
				}
                
        }
		// in case for hex conversion
		else { 
			
			// For each file provided as an argument
			currentFile = argv[1];

			// create file handle
			fileptr = fopen(currentFile.c_str(), "rb"); 

			// Check if we can open the file for reading
			if (fileptr == NULL) { 
				cout << "File could not be opened: " << currentFile << endl;
			}
			// seek to read entire file to end
			fseek(fileptr, 0, SEEK_END);
			// store file length 
			filelen = ftell(fileptr); 
			// reset to beginning of the file
			rewind(fileptr); 

			 // memory space with the size of the file we are reading
			buffer = (char *)malloc((filelen + 1) * sizeof(char));
			// read file into buffer
			fread(buffer, filelen, 1, fileptr); 
			// close file handler
            fclose(fileptr);

            // replace non printable characters with a period
            for (int i = 0; i < filelen; i++) { 
                if ((+buffer[i] >= 48 && +buffer[i] <= 57) || (+buffer[i] >= 65 && +buffer[i] <= 90) || (+buffer[i] >= 97 && +buffer[i] <= 122) || +buffer[i] == 32 || +buffer[i] == 46 ) {
                    buffer[i] = buffer[i];
                } else {
                    buffer[i] = '.';
                }
            }

			// find how many rows we are going to print
            int rows = ceil(filelen / 16) + 1; 

			// for each section of 16 bytes in the file
			for (int i = 0, offset = i * 16; i < rows; i++) { 
			// offset equals current row * 16
			offset = i * 16; 
			// stream to print each output respectively 
			stringstream hexStream;
			stringstream charStream;
			// index for tracking (proper spacing)
			int index = 0;
				 // for each byte (up until the 16th from the current offset) and not past the end of the file...
                    for (int x = 0; x < 16 && (offset + x < filelen - 1); x++)
                    {
                        index++;

                        hexStream << hexVal((int)buffer[offset + x]) << (index % 2 == 0 ? (" ") : "");
                        charStream << (isprint(buffer[offset + x]) ? buffer[offset + x] : '.');
                    }

				printf("|%08x: %-40s  %-16s|\n", offset, hexStream.str().c_str(), charStream.str().c_str());
			}
			// free up memory
			free(buffer); 
		}
	}
}