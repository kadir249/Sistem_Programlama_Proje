#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "fields.h"
#include "jval.h"
#include "jrb.h"

typedef struct 
{
  char *kelime;
  char *kod;
} Kilit;

JRB kilitOkuma(int kontrol)
{
	IS is;
	JRB agac;
	Kilit *k;
  	int kboyutu, i;
	char *temp1;
	char *temp2;

  	is = new_inputstruct(".kilit");
	agac = make_jrb();

  	if (is == NULL) 
	{
    	perror(".kilit");
    	exit(1);
  	}

	if(kontrol == 0)
	{
		while(get_line(is) >= 0) 
		{
			if(is->NF > 1)
			{
				k = malloc(sizeof(Kilit));

				temp1 = strtok(is->fields[0], ":");
				temp1 = strtok(temp1, "\"\"");

				kboyutu = strlen(temp1);
				k->kelime = (char *) malloc(sizeof(char)*(kboyutu + 1));
      			strcpy(k->kelime, temp1);

				temp2 = strtok(is->fields[1], ",");
				temp2 = strtok(is->fields[1], "\"\"");

				kboyutu = strlen(temp2);
				k->kod = (char *) malloc(sizeof(char)*(kboyutu + 1));
      			strcpy(k->kod, temp2);

				jrb_insert_str(agac, k->kelime, new_jval_s((char *) k->kod));	
			}
		}			
	}
	else
	{
		while(get_line(is) >= 0) 
		{
			if(is->NF > 1)
			{
				k = malloc(sizeof(Kilit));

				temp1 = strtok(is->fields[0], ":");
				temp1 = strtok(temp1, "\"\"");

				kboyutu = strlen(temp1);
				k->kelime = (char *) malloc(sizeof(char)*(kboyutu + 1));
      			strcpy(k->kelime, temp1);

				temp2 = strtok(is->fields[1], ",");
				temp2 = strtok(is->fields[1], "\"\"");

				kboyutu = strlen(temp2);
				k->kod = (char *) malloc(sizeof(char)*(kboyutu + 1));
      			strcpy(k->kod, temp2);

				jrb_insert_str(agac, k->kod, new_jval_s((char *) k->kelime));	
			}
		}			
	}

  	jettison_inputstruct(is);
	return agac;	
}

int dosyaOkuma(char **args, JRB agac, int kontrol)
{
	IS is;
  	int i;
	JRB temp1;

	int fileDescriptor, tempFile;

  	is = new_inputstruct(args[2]);
  	if (is == NULL) 
	{
    	perror(args[2]);
    	exit(1);
  	}

	fileDescriptor = open(args[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  	if (fileDescriptor < 0) 
	{
    	perror(args[3]);
    	exit(1);
  	}

  	while(get_line(is) >= 0) 
	{
    	for (i = 0; i < is->NF; i++) 
		{
			temp1 = jrb_find_str(agac, is->fields[i]);
			if(temp1 == NULL)
			{
				tempFile = write(fileDescriptor, is->fields[i], strlen(is->fields[i]));
				tempFile = write(fileDescriptor, " ", strlen(" "));				
			}
			else
			{
				if(kontrol == 0)
				{
					tempFile = write(fileDescriptor, temp1->val.s, strlen(temp1->val.s));
                	tempFile = write(fileDescriptor, " ", strlen(" "));
				}
				else
				{
					tempFile = write(fileDescriptor, temp1->val.s, strlen(temp1->val.s));
                	tempFile = write(fileDescriptor, " ", strlen(" "));
				}
			}
    	}
  	}

	close(fileDescriptor);
  	jettison_inputstruct(is);
	return 1;	
}

int encode(char **args, JRB agac, int kontrol)
{
	dosyaOkuma(args, agac, kontrol);
	return 1;
}

int decode(char **args, JRB agac, int kontrol)
{
	dosyaOkuma(args, agac, kontrol);
	return 1;
}

static int calistir(char **args)
{
	JRB agac;
	if (args[0] != NULL) 
	{
		if (strcmp(args[1], "-e") == 0) 
		{
			int kontrol = 0;
			agac = kilitOkuma(kontrol);	
			encode(args, agac, kontrol);
		}
		else if (strcmp(args[1], "-d") == 0) 
		{
			int kontrol = 1;
			agac = kilitOkuma(kontrol);			
			decode(args, agac, kontrol);
		}
		else
		{
	 		printf("Hatali komut. Programi tekrar calistirmayi deneyiniz.\n");
		}
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
	 	printf("Gecersiz parametre. Dort parametre bulunmalidir.\n");
	}
  	return 0;
}