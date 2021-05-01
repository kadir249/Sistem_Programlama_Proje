#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "fields.h"
#include "jval.h"
#include "jrb.h"


int encode(char **args)
{
    printf("Encode calisti.\n");
    return 1;
}

int decode(char **args)
{
    printf("Decode calisti.\n");
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