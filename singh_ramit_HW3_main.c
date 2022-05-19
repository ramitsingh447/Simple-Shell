/**************************************************************
* Class: CSC-415-02 Spring 2022
* Name: Ramit Singh
* Student ID: 918213925 
* GitHub Name: ramitsingh447
* Project: Assignment 3 – Simple Shell
*
* File: singh_ramit_HW3_main.c
*
* Description: Implementation of a simple shell that will run on top of the other
*
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h> 
#include <string.h>

#define Size 180

    int main(int argc, char *argv[] ) {
    char *parameter[ 180 / 2 +1]; // the paramater can only run till 180 bytes, +1 is the NULL
    char *command;// implementing the command
    char *commandLine = malloc(180); //Creating buffer of size 180
    char* args[100]; //args is passed 
    char* path = "/bin/"; // Defining the path of execvp
    char fullPath[20]; // Will hold the '/bin/' file

        while(1) {
        printf("Prompt"); 
        char temp_userInputstr[50];
      if (fgets(commandLine, 180, stdin)) { 
          parameter[0] = strtok(commandLine, " \n");
          
          int i = 0;
          while (parameter[i] != NULL){
              parameter[++i] = strtok(NULL, " \n");
          }
        } else {
                exit(0); //end of the file
        }
        if(strcmp(commandLine, "exit") == 0){ //Processing exit value here if the user enters exit
            break; 
        }
        int status; // declaring the status variable
        int pid = fork(); // declaring the fork

        if(pid == 0){
            execvp( parameter[0], parameter);
            exit(1);
            
        }else{
            wait(&status); // waiting for parent 
            if(WIFEXITED(status)) // wait for child process
            printf("Child %d, exit with %d\n", pid , WEXITSTATUS(status)); // gets child process
        }
    }
free(commandLine); // Will deallocate the memory
    return 0; // end of main
} // End of main function
