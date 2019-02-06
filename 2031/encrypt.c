//
// EECS2031 encrypt.c
//
//
// Name: Sharumilan Vijayaratnam 
// Student Number: 213656962


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int encrypt(char *file_Name, int shift);



int main(int argc, char *argv[])
{
    //check valid input.
    if (argc != 3)
    {
        printf("Invalid input!\n");
        printf("encrypt (filename) (shift number)\n");
        return 1;
    }

    // this will read the first input.
    char* file_Name = argv[1];
    char *p;

    // we need to read the shift amount and this will do that.
    int shift = atoi(argv[2]);

    // This will make sure the shift amount won’t exceed 25 and it is valid
    // if over, then make it to be.
    if(shift <1 || shift >25){
	//this will print if it is not valid
   	printf("It should be between 1-25"); 
    }
	//if it is valid, this will proceed to shift
    encrypt(file_Name,shift);
    

    return 0;
}

int encrypt(char *filename, int shift)
{


    const char* mode = "rb";

    FILE *inFile = fopen(filename, mode);

    const char* newfilename = strcat(filename,".enc");

    FILE *fire = fopen(newfilename, "w+");
	//if the file is empty
    if (inFile == NULL|| fire == NULL)
    {
        printf("file cannot be opened");
        return 1;
    }

    char b;

	//checks lower case and upper case 
    char B;
    while ((b = fgetc(inFile)) != EOF)
    {
        if(isalpha(b))
        {
            if(islower(b))
                B = (b + shift - 'a') % 26 + 'a';

            else
                B = (b + shift - 'A') % 26 + 'A';

        }
        else


            B = b;


        if (fputc(B, fire) == EOF)
        {



        }
    }

    fclose(inFile);
    fclose(fire);

    return 0;
}


