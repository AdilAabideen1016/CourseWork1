
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaring this value so I can use it in different places
#define buffer_size 100
char LineBuffer[buffer_size] ;
char Date[11] ;
char Time[6] ;
char Steps[100] ;

/**
 * @brief Struct to hold each Fitness Data, Contains the date and the time as a string as the steps as an Integer.
 *
 */
// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;





/**
 * @brief Adapted version of the tokeniseRecord function which you should now be familiar with - this one is adapted for this data file
 *        as it has fewer outputs and gives you the bloodIron as a float
 *
 * @param input the line of the file to be split
 * @param delimiter what character it should split on
 * @param date the place where the date will be stored
 * @param steps the place where the Number of steps will be stored. 
 */
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps)
{
	// Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}




/**
 * @brief Opens the file in the correct mode
 *
 * @param filename the name of the file to open
 * @param mode the mode (r/w/a/r+/w+/a+)
 * @return FILE* The file object to store the opened file in.
 */
FILE *open_file( char fileName[], char mode[])
{
    // Opening the File using the Filename and Mode
    FILE * file = fopen(fileName, mode);

    // Printing Error or Success Whether the File is found or not or cannot open
    if (file == NULL) {
        printf("Error: Could not find or open the file.\n");
        exit(1);
    } else {
        printf("File Succesfully Loaded.\n");
    };

    // Returning the File
    return file ;
}


void total_records(FILE *file, FITNESS_DATA* dataArray)
{
    
    int num_of_records = 0 ;
    while (fgets(LineBuffer, buffer_size, file) != NULL) {
        tokeniseRecord(LineBuffer, ",", Date, Time, Steps);
        strcpy(dataArray[num_of_records].date, Date);
        strcpy(dataArray[num_of_records].time, Time);
        dataArray[num_of_records].steps = atoi(Steps) ;

        num_of_records++ ;
    }
    printf("Total records: %d\n", num_of_records);
}

#endif // FITNESS_DATA_STRUCT_H
