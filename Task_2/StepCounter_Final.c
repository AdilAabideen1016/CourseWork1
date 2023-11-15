#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Define an appropriate struct


// Define any additional variables here



// Complete the main function
int main() {

    

    // Defining Temporary Variables 
    char Date[11] ;
    char Time[6] ;
    char Steps[100] ;
    char choice ; 
    int num_of_records = 0 ;
    int i ;
    FILE * file ;

    // Creating Struct and Opening the file for READ
    FITNESS_DATA fitnessData[1000]; 
    char fileName[256] = "FitnessData_2023.csv";
    
 

    while (1) {

        printf("Menu Options :\n") ;
        printf("A: Specify the filename to be imported\n");                       
        printf("B: Display the total number of records in the file\n");                    
        printf("C: Find the date and the timeslot with the fewest steps\n");                     
        printf("D: Find the date and the timeslot with the largest number of steps\n");                    
        printf("E: Find the mean step count of all the records in the file\n");       
        printf("F: Find the longest countinues period where the step count is above 500 steps\n");             
        printf("Q: Quit\n");

        choice = getchar() ;

        while (getchar() != '\n') ;

        switch (choice) 
        {
            case 'A' :
            case 'a':
                printf("Input filename : ");
                scanf("%s", fileName);
                file = open_file(fileName, "r");
                fclose(file);
                break ;
            
            case 'B' :
            case 'b' :
                file = open_file(fileName, "r");
                total_records(file, fitnessData);
                fclose(file) ;
                break ;
            case 'C':
            case 'c':
                file = open_file(fileName, "r");
                fewest_steps(file, fitnessData);
                fclose(file);
                break;
            case 'D':
            case 'd':
                file = open_file(fileName, "r");
                Largest_steps(file, fitnessData);
                fclose(file);
                break ;

            case 'E':
            case 'e':
                file = open_file(fileName, "r");
                mean_steps(file, fitnessData);
                fclose(file);
                break;

            case 'F':
            case 'f':
                file = open_file(fileName, "r");
                longest_period(file, fitnessData);
                fclose(file);
                break;

            case 'G':
            case 'g':
                return 0;
                break;

            case 'Q':
            case 'q':
                return 0;
                break;

            // if they type anything else:
            default:
                printf("Invalid choice\n");
                break;
            
        }

        

    }

    

    

}
