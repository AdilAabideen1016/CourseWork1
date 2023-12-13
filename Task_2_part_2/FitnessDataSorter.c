#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}




// Function for Sorting the Array in Descending order of Steps
void BubbleSort(FitnessData arr[], int num_of_records){

    // Defining temporary Variables 
    int i, j ; 
    FitnessData temp ; 

    // Loops through array and Organises in Descening Order
    for ( j = 0 ; j < num_of_records ; j++){
        for ( i = 0 ; i < num_of_records ; i++){

            // If not in order of size then a swap process occurs
            if ( arr[i + 1].steps > arr[i].steps ) {
                temp = arr[i] ; 
                arr[i] = arr[i+1] ; 
                arr[i + 1] = temp ; 
        }

        }
    }
}


int main() {
    

    // Defining temporary Variables
    char Date[11] ; 
    char Time[6] ; 
    int Steps ;
    int num_of_records = 0 ;
    int i ; 
    int bufferSize = 100;
    char LineBuffer[bufferSize] ; 


    // Defining the Array of Type Struct and Filename 
    FitnessData fitnessData[1000] ;
    char fileName[100] ; 


    // Requests Filename from User and Opens File for Read
    printf("Enter Filename : ") ; 
    scanf("%s", fileName) ; 
    FILE * file = fopen(fileName, "r") ;

    // If file name is incorrect give error message
    if (file == NULL) {
        printf("Error : Invalid File \n");
        return 1 ; 
    }


    // Loops through File and assigns data to Array
    while (fgets(LineBuffer, bufferSize, file) != NULL){

        // Tokenise record 
        tokeniseRecord(LineBuffer, ',', Date, Time, &Steps) ;
        
        
        // Validate if data in the file is in correct format , Date
        if (strlen(Date) != 10 || Date[4] != '-' || Date[7] != '-') {
            printf("Error : Invalid File \n");
            return 1;

        // Verifying Time Input
        } else if (strlen(Time) != 5 || Time[2] != ':') {
            printf("Error : Invalid File \n");
            return 1;

        // Verifying Steps Input
        } else if (Steps <= 0) {
            printf("Error : Invalid File \n");
            return 1;
        }

        

      

        // Assign data to the array Struct
        strcpy(fitnessData[num_of_records].date, Date);
        strcpy(fitnessData[num_of_records].time, Time);
        fitnessData[num_of_records].steps = Steps ;

        num_of_records++ ; 

        
    }

    fclose(file) ; 


    // Calls Function to sort in descending order
    BubbleSort(fitnessData, num_of_records);

    // Open new File is .tsv form for Write Mode
    strcat(fileName, ".tsv") ;
    FILE * outputFile = fopen(fileName, "w"); 
    if ( file == NULL ) {
        printf("Error : invalid file\n");
        return 1;
    }

    // Loop through the Array and Print each record to New Output File with /t
    for ( i = 0 ; i < num_of_records ; i++) {
        fprintf(outputFile,"%s\t%s\t%d\n",fitnessData[i].date, fitnessData[i].time, fitnessData[i].steps);
    }

    // Printing out result
    printf("Data Sorted and Written to %s\n", fileName);

    

    
}
