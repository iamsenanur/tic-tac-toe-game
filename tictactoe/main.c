#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>
#include<stdlib.h>
#define boyut 3 
void oyunagiris();
int kontrolet();
int a[boyut][boyut] = {0};
int i;
int j;


void oyunagiris()
{
	struct degisken{

   int i, j;
};
struct degisken degeri;

  
   printf("oyuncu1(X)-oyuncu2(O)\n\n");
   for (i = 0; i < boyut; i++) {
      for (j = 0; j < boyut; j++)
         if (a[i][j] == 0)
            printf(" . ");
         else if (a[i][j] == 1)
            printf(" X ");
         else
            printf(" O ");
      putchar('\n');
   }
   
}

struct oyuncubilgisi
{
    char isim[30];
}oyuncu1, oyuncu2;


int kontrolet(void)
{
  


   int i;
   int j;
   int k;
   int t;
   int count;
   
   
    

  
 
   for (k = 1; k < boyut; k++) {
      for (i = 0; i < boyut; i++) {        
         for (j = 0; j < boyut; j++)
            if (a[i][j] != k)
               break;
         if (j == boyut)
            return k;         
      }
      for (j = 0; j < boyut; j++) {         
         for (i = 0; i < boyut; i++)
            if (a[i][j] != k)
               break;
         if (i == boyut)
            return k;        
      }
      for (i = 0; i < boyut; i++)             
         if (a[i][i] != k)
            break;
      if (i == boyut)
         return k;                
 
      for (i = 0, j = 2; i < boyut; i++, j--)     
         if (a[i][j] != k)
            break;
      if (i == boyut)
         return k;                               
   }
   count = 0;
   for (i = 0; i < boyut; i++)
      for (j = 0; j < boyut; j++)
         if(a[i][j] != 0)
            count++;
   if (count == boyut * boyut)
      return -1;
   return 0;
}
int main()
{
	FILE *dosya;
	char cumle[10],cumle1[10],cumle2[10];
	if((dosya=fopen("tictactoe.txt","r"))!=NULL);
	{	fscanf(dosya,"%s", &cumle);
		fscanf(dosya,"%s", &cumle1);
		fscanf(dosya,"%s", &cumle2);
		printf("     *****%s %s %s*****\n", cumle,cumle1,cumle2);
		
	}
    printf("      *      *      *      *\n");
   printf("\n\tTic-Tac-Toe Oyunu \n\n");
   printf("      *      *      *      *\n");
	
   int oyuncu, secim, i, j;
   int sonuc;
   struct oyuncubilgisi oyuncu1,oyuncu2;
   
    printf("oyuncu1 'in ismini giriniz:");
    scanf("%s",&oyuncu1.isim);
    printf("oyuncu2' nin ismini giriniz:");
    scanf("%s",&oyuncu2.isim);
 
   oyuncu = 1;
   while ((sonuc = kontrolet()) == 0) {
      oyunagiris();
      printf("oyuncu: %d, secimini gir: [%d-%d]", oyuncu, 1, boyut * boyut);
      do {
         scanf("%d", &secim);
         while (getchar() != '\n')  
            ;
         j = secim % boyut - 1;
         i = (secim - j) / boyut;
         if (secim > boyut * boyut || secim <= 0 || a[i][j] != 0) {
            printf("gecersiz secim, oyuncu %d yeniden dene: ", oyuncu);
            continue;
         }
         else {
            a[i][j] = oyuncu;
            break;
         }
      } while(1);
        oyuncu = (oyuncu == 1) ? 2 : 1;
   }
   oyunagiris();
   if (sonuc == -1)
      printf("Oyun Bitti, Kazanan YOK.");
   else
   
     printf("Kazanan Oyuncu %d, %s",sonuc,&oyuncu1.isim,&oyuncu2.isim);
      
   return 0;
}
