#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "fields.h"
#include "jval.h"
#include "jrb.h"


int main(int argc, char *argv[])
{
    if(argc == 4)
    {
        printf("Basarili.\n");
    }
    else
    {
         printf("Geçersiz parametre. Üç parametre bulunmalıdır.\n");
    }
      return 0;
}