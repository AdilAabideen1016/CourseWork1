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

    char Date[11] ;
    char Time[6] ;
    char Steps[100] ;
    int counter = 0 ;

    FITNESS_DATA fitnessData[1000]; 
    char fileName[] = "FitnessData_2023.csv";

    FILE * file = fopen(fileName, "r") ;
    if (file == NULL) {
        perror("");
        return 1 ;
    };

    int bufferSize = 100 ;
    char LineBuffer[bufferSize] ;

    while (fgets(LineBuffer, bufferSize, file) != NULL) {
        tokeniseRecord(LineBuffer,",", Date, Time, Steps) ;
        strcpy(fitnessData[counter].date, Date);
        strcpy(fitnessData[counter].time, Time);
        fitnessData[counter].steps = atoi(Steps) ;


        if (counter < 3) {
            printf("%s/%s/%d\n",fitnessData[counter].date,fitnessData[counter].time,fitnessData[counter].steps);
        }

        counter ++ ;   
    }

    printf("%d\n",counter);

}
