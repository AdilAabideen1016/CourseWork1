
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


/**
 * @brief Calculates the total Number of records within an File 
 *
 * @param file the File to read from 
 * @param dataArray The array of type Struct where the Records will be stored 
 */
void total_records(FILE *file, FITNESS_DATA* dataArray)
{
    
    // Loops through the file and adds each record to the Array of type Struct
    int num_of_records = 0 ;
    while (fgets(LineBuffer, buffer_size, file) != NULL) {
        tokeniseRecord(LineBuffer, ",", Date, Time, Steps);
        strcpy(dataArray[num_of_records].date, Date);
        strcpy(dataArray[num_of_records].time, Time);
        dataArray[num_of_records].steps = atoi(Steps) ;

        num_of_records++ ;
    }

    // Prints the total number of records
    printf("Total records: %d\n", num_of_records);
}

/**
 * @brief Loops through the File and Returns the Date and Time of Fewest Steps 
 *
 * @param file the File to read from 
 * @param dataArray The array of type Struct where the Records will be stored 
 */
void fewest_steps(FILE *file, FITNESS_DATA* dataArray)
{
    // Defining Temporary Variables 
    int num_of_records = 0 ;
    int Lowest_steps = 10000;
    int count ;

    // Loops through the file and adds each record to the Array of type Struct 
    while (fgets(LineBuffer, buffer_size, file) != NULL) {
        tokeniseRecord(LineBuffer, ",", Date, Time, Steps);
        strcpy(dataArray[num_of_records].date, Date);
        strcpy(dataArray[num_of_records].time, Time);
        dataArray[num_of_records].steps = atoi(Steps) ;

        // If the Current Steps in record is less than Record Lowest then It Reassigns Record Lowest
        if (dataArray[num_of_records].steps < Lowest_steps) {
            Lowest_steps = dataArray[num_of_records].steps;
            count = num_of_records;
        }
        num_of_records++ ;

    }

    // Print Answer
    printf("Fewest steps: %s %s\n", dataArray[count].date, dataArray[count].time) ;

}


/**
 * @brief Loops through the File and Returns the Date and Time of Largest Steps 
 *
 * @param file the File to read from 
 * @param dataArray The array of type Struct where the Records will be stored 
 */
void Largest_steps(FILE *file, FITNESS_DATA* dataArray)
{
    // Define Temporary Variables 
    int num_of_records = 0 ;
    int Lowest_steps = 0;
    int count ;

     // Loops through the file and adds each record to the Array of type Struct
    while (fgets(LineBuffer, buffer_size, file) != NULL) {
        tokeniseRecord(LineBuffer, ",", Date, Time, Steps);
        strcpy(dataArray[num_of_records].date, Date);
        strcpy(dataArray[num_of_records].time, Time);
        dataArray[num_of_records].steps = atoi(Steps);

        // If current Steps in Record is Larger than Largest then Reassign Largest
        if (dataArray[num_of_records].steps > Lowest_steps) {
            Lowest_steps = dataArray[num_of_records].steps;
            count = num_of_records;
        }
        num_of_records++ ;

    }

    // Print Answer
    printf("Largest steps: %s %s\n", dataArray[count].date, dataArray[count].time) ;

}


/**
 * @brief Loops through the File and Returns the Mean Steps 
 *
 * @param file the File to read from 
 * @param dataArray The array of type Struct where the Records will be stored 
 */
void mean_steps(FILE *file, FITNESS_DATA* dataArray)
{
    // Define Temporary Variables
    int num_of_records = 0 ;
    int total_steps = 0 ;
    float mean_steps ;

    // Loops through the file and adds each record to the Array of type Struct
    while (fgets(LineBuffer, buffer_size, file) != NULL) {
        tokeniseRecord(LineBuffer, ",", Date, Time, Steps);
        strcpy(dataArray[num_of_records].date, Date);
        strcpy(dataArray[num_of_records].time, Time);
        dataArray[num_of_records].steps = atoi(Steps) ;

        // Total all amount of steps and Keep count of amount of Records
        total_steps = total_steps + dataArray[num_of_records].steps ;
        num_of_records++ ;

    } 

    // Divide Total steps with amount of records of Steps and Print Answer
    mean_steps =  (total_steps / num_of_records ) ;
    printf("Mean step count: %.0f\n", mean_steps);

}


/**
 * @brief Loops through the File and Returns the Longest Countinues Period Where Steps is > 500 
 *
 * @param file the File to read from 
 * @param dataArray The array of type Struct where the Records will be stored 
 */
void longest_period(FILE *file, FITNESS_DATA* dataArray)
{
    // Define Temporary Variables 
    int num_of_records = 0 ;
    int max_count = 0 ;
    int count = 0 ;
    int i ;
    int start ;
    int max_start, max_end ; 

    // Loop through the file and adds each record to the Array of type Struct
    while (fgets(LineBuffer, buffer_size, file) != NULL) {
        tokeniseRecord(LineBuffer, ",", Date, Time, Steps);
        strcpy(dataArray[num_of_records].date, Date);
        strcpy(dataArray[num_of_records].time, Time);
        dataArray[num_of_records].steps = atoi(Steps) ;

        num_of_records ++ ;

        
    } 


    // Loop through the Array of type the Struct 
    for ( i = 0 ; i < num_of_records ; i++) {

        // If the Steps is > 500 then Remember the Start Index
        if ( dataArray[i].steps > 500 )
        {
            start = i - count ;
            count = count + 1 ;
        } else {

            // Else if the Steps have gone < 500 then Save the Variables if the Longest Period
            if (count > max_count) {
                max_count = count ;
                max_start = start;
                max_end = i - 1;
                count = 0 ;
            }
            
        }
    }

    // Print Answer
    printf("Longest period start: %s %s\n", dataArray[max_start].date, dataArray[max_start].time);
    printf("Longest period End: %s %s\n", dataArray[max_end].date, dataArray[max_end].time);
}


#endif // FITNESS_DATA_STRUCT_H
