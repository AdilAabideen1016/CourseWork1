#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
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

// Complete the main function
int main() {

    // Defining Temporary Variables
    char Date[11] ;
    char Time[6] ;
    char Steps[100] ;
    int num_of_records = 0 ;
    int i ;

    // Creating Strruct and Opening the file for READ
    FITNESS_DATA fitnessData[1000]; 
    char fileName[] = "FitnessData_2023.csv";

    FILE * file = fopen(fileName, "r") ;
    if (file == NULL) {
        perror("");
        return 1 ;
    };


    // Reading data from File and Storing it in a Struct
    int bufferSize = 100 ;
    char LineBuffer[bufferSize] ;

    while (fgets(LineBuffer, bufferSize, file) != NULL) {
        tokeniseRecord(LineBuffer,",", Date, Time, Steps) ;
        strcpy(fitnessData[num_of_records].date, Date);
        strcpy(fitnessData[num_of_records].time, Time);
        fitnessData[num_of_records].steps = atoi(Steps) ;

        num_of_records++ ;   
    }

    // Writing Appropriate Information to the Screen
    printf("Number of records in file: %d\n",num_of_records);
    for (i=0 ; i<3 ; i++) {
        printf("%s/%s/%d\n",fitnessData[i].date, fitnessData[i].time, fitnessData[i].steps);
    }

}
