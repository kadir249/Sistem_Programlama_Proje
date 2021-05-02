#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "fields.h"
#include "jval.h"
#include "jrb.h"
#include <unistd.h>
#include <fcntl.h>

int kilitOkuma()
{
    IS is;
    int i;
    char *temp1;  
    char *temp2;

    is = new_inputstruct(".kilit");
    if (is == NULL) 
    {
        perror(".kilit");
        exit(1);
    }

    while(get_line(is) >= 0) 
    {
        if(is->NF > 1)
        {
            temp1 = strtok(is->fields[0], ":");
            temp1 = strtok(temp1, "\"\"");
            printf("%s\n", temp1);

            temp2 = strtok(is->fields[1], ",");
            temp2 = strtok(is->fields[1], "\"\"");
            printf("%s\n", temp2);
        }
    }

    jettison_inputstruct(is);
    return 1;
}


int dosyayaYazma(char **args)
{
    IS is;
    
    int i;
    is = new_inputstruct(args[2]);

    if (is == NULL) 
    {
        perror(args[2]);
        exit(1);
    }
     
    int fileDescriptor, tempFile;
    char *temp;

    fileDescriptor = open(args[3], O_WRONLY | O_CREAT | O_TRUNC);

    if (fileDescriptor < 0)
    {
        perror(args[3]);
        exit(1);
    }

    while(get_line(is) >= 0)
    {
        for (i = 0; i < is->NF; i++) 
        {
            temp = (char *) malloc(strlen(is->fields[i] + 1));
            strcpy(temp, is->fields[i]);
            strcat(temp, " ");
            tempFile = write(fileDescriptor, temp, strlen(temp));
        }
    }

    close(fileDescriptor);
    jettison_inputstruct(is);
    return 1;
}


int encode(char **args)
{
    printf("Encode calisti.\n");
    kilitOkuma();
    dosyayaYazma(args);
    return 1;
}

int decode(char **args)
{
    printf("Decode calisti.\n");
    kilitOkuma();
    dosyayaYazma(args);
    return 1;
}

static int calistir(char **args)
{
    if (args[0] != NULL) 
    {
        if (strcmp(args[1], "-e") == 0 && strcmp(args[3], "encripted") == 0) encode(args);
        else if (strcmp(args[1], "-d") == 0 && strcmp(args[3], "decripted") == 0) decode(args);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc == 4)
    {
        calistir(argv);
    }
    else
    {
         printf("Geçersiz parametre. Üç parametre bulunmalıdır.\n");
    }
      return 0;
}