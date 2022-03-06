
/*----------------------------------------------------------------

* Programación avanzada: Manejo de archivos

* Fecha: 4-Mar-2022

* Autor:

* A01209455 Misael Guzmán Gutiérrez

*--------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX 512

typedef unsigned char unchar;

int main(int argc, char* argv[]){
    
    int fp1, fp2, i = 0;
    ssize_t Wbytes, Rbytes;
    char buffer[MAX];

    if (argc != 3) {
		printf("usage: %s source destination\n", argv[0]);
		return -1;
	}

    /* Abriendo el archivo fuente en modo lectura */
    fp1 = open (argv[1], O_RDONLY);

    if (fp1 < 0){
        perror("The source file couldn't be opened in read mode ");
        return -2;
    }

    /* Creando el archivo destino */
    fp2 = open (argv[2], O_RDONLY | O_CREAT | O_TRUNC, 0666);

    if (fp2 < 0){
        perror(argv[0]);
        return -3;
    }

    /*while((Rbytes = read(fp1, &buffer, MAX)) > 0){
        for(i;i<Rbytes;i++)
    {
          buffer[i]=buffer[i]^45;
          printf("%c", buffer[i]);
     }

   }*/

   	if (((i & (1 << fp1)) >> fp1) ^ ((i & (1 << fp2)) >> fp2))
	{
		i ^= (1 << fp1);
		i ^= (1 << fp2);
	}

    Wbytes = write (fp2, buffer[i], (ssize_t) Rbytes);


   close (fp1); 
   close (fp2); 
   free(buffer); 
   	
   return 0; 
} 



    






