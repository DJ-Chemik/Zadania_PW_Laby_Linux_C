#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/**
 * Program ten dopisuje do końca pliku nazwy podane w argumentach.
 * Ile argumentów się poda tyle doda do pliku.
 * Każdy wyraz od nowej linii*/
int main(int ilosc, char* argumenty[])
{
    int des3 = open("plikTekstowy.txt", O_WRONLY | O_APPEND, 0644);
    
    int rozmiar_argumentu;
    for (int i=1;i<ilosc;i++)
    {
        rozmiar_argumentu = strlen(argumenty[i])+1; //patrzy ile znaków podał użytownik jako argument
        write(des3,argumenty[i],rozmiar_argumentu); //dopisuje ten tekst do pliku
        write(des3,"\n",1);
    }
    close (des3);

    
    int des4 = open("plikTekstowy.txt", O_RDONLY,0644);
    //Wypisywanie pliku na ekran
    char buf[20];
    int ile_bajtow = read(des4,buf,20);
    while (ile_bajtow > 0)
    {
        write(1,buf,ile_bajtow);
        ile_bajtow = read(des4,buf,20);
    }
    close (des4);
    return 0;
}
