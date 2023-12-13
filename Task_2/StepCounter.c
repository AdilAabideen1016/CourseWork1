#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"


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

    // Creating Struct and Stating the Filename
    FITNESS_DATA fitnessData[1000]; 
    char fileName[256] = "FitnessData_2023.csv";
    
    
 
    // Printing the Menu System 
    while (1) {

        printf("Menu Options :\n") ;
        printf("A: Specify the filename to be imported\n");                       
        printf("B: Display the total number of records in the file\n");                    
        printf("C: Find the date and the timeslot with the fewest steps\n");                     
        printf("D: Find the date and the timeslot with the largest number of steps\n");                    
        printf("E: Find the mean step count of all the records in the file\n");       
        printf("F: Find the longest countinues period where the step count is above 500 steps\n");             
        printf("Q: Quit\n");


        // Getting Choice
        fflush(stdin);
        choice = getchar() ;

        while (getchar() != '\n') ;

        // Switch to Allow the Choices in Menu Systems
        switch (choice) 
        {
            case 'A' :
            case 'a':
                
                // Requesting User Input of FileName and Opening File
                printf("Input filename : ");
                scanf("%s", fileName);

                // Flushes the Input Buffer allowing for getchar() to work
                while ((choice = getchar()) != '\n' && choice != EOF);
                file = open_file(fileName, "r", 1);
                
                break ;
            
            case 'B' :
            case 'b' :

                // Passing Filename and array to Void Function to get Total Records
                file = open_file(fileName, "r",0);
                total_records(file, fitnessData);
                fclose(file);

                break ;
            case 'C':
            case 'c':

                // Passing FileName and Array to Void Function to Get Fewest Steps
                file = open_file(fileName, "r",0);
                fewest_steps(file, fitnessData);
                fclose(file);

        
                break;
            case 'D':
            case 'd':

                // Passing FileName and Array to Void Function to Get Largest Steps
                file = open_file(fileName, "r",0);
                Largest_steps(file, fitnessData);
                fclose(file);
                break ;

            case 'E':
            case 'e':

                // Passing FileName and Array to Void Function to Get Mean Steps
                file = open_file(fileName, "r",0);
                mean_steps(file, fitnessData);
                fclose(file);
                break;

            case 'F':
            case 'f':

                // Passing FileName and Array to Void Function to Get The Longest period where steps > 500
                file = open_file(fileName, "r",0);
                longest_period(file, fitnessData);
                fclose(file);
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
