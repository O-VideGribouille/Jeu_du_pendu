#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NBvie 5
#define TAILLE 8 //solution temporaire pour tester le code

/*FEATURE :
- Generer une chaine de caracteres
- Remplacer un caractere pas un autre
- Entrer un mot
- Avoir un nombre de vie
- Creer une interface modifiable en fonction des réponses
*/

//PROTOTYPES
void remplaceCara(char n_car,char n_mot[TAILLE], char n_motver[TAILLE]);
void affiche(int vie);

    //VARIABLES
    char n_mot[TAILLE]={'b','o','n','j','o','u','r'}; //mote a trouver
    char n_motver[TAILLE]={'*','*','*','*','*','*','*'}; //sert a l'affichage du mot secret par les caracteres '_'
   // char n_mottemp[TAILLE]; //
    int lettretrouvee[TAILLE]={0};//tableau de booleen, chaque case correspond au lettre du mot a trouver
    int vie=NBvie; // represente le nombre d'essai possible avant de perdre
    char n_car; //stock la lettre proposee par le joueur
   int result;
   int cdtVic=0;

int main()
{
    //while((vie>0)||(result!=0)){
    while((cdtVic==0)){
    //Phase 1 : affichage
    //Generer des caracteres '_' a la place des lettres
    printf("%s\n",n_motver);

    //Phase 2 : entrer une lettre
        printf("\nproposer une lettre : ");
        n_car=getchar(); //entrer d'une lettre du clavier
        printf("\n");

       remplaceCara(n_car, n_mot, n_motver);
       // printf("\n%s",n_motver);

    printf("%d\n",vie);

    result= strcmp(n_mot,n_motver);
    //vérification de la condition de fin de boucle
    //les bouclse while n'aime pas avoir plusieurs arguments
    if((result==0)||(vie==0)){
        cdtVic=1;
    }

    affiche(vie);

      fflush(stdin);
    }


    //if((vie==0)&&(result>0)){
    if((vie==0)){
        printf("\nPERDU");
      }
      else {
           // if(result==0){

        printf("\nVICTOIRE");
       // }

      }


        //printf("%d",vie);




    return 0;
}



void remplaceCara(char n_car,char n_mot[TAILLE], char n_motver[TAILLE]){
    int i;
    int nb=0;
    for(i=0;i<strlen(n_mot);i++){
        if(n_mot[i]== n_car){
            n_motver[i]=n_car;
            nb++;
        }

    }

    if(nb==0){//condition de perte vie
                vie--;
    }
}



void affiche(int vie){

    switch(vie)
    {
    case 4:
        printf("-----\n");
       printf("|/  |\n");
       printf("|    \n");
       printf("|    \n");
       printf("|    \n");
       printf("|    \n");
        printf("---  \n\n");

        break;

    case 3:
        printf("-----\n");
       printf("|/  |\n");
       printf("|   o\n");
       printf("|    \n");
       printf("|    \n");
       printf("|    \n");
        printf("---  \n\n");

        break;

    case 2:
        printf("-----\n");
       printf("|/  |\n");
       printf("|   o\n");
       printf("|  /| \n");
       printf("|    \n");
       printf("|    \n");
        printf("---  \n\n");

        break;

    case 1:
        printf("-----\n");
       printf("|/  |\n");
       printf("|   o\n");
       printf("|  /| \n");
       printf("|   |\n");
       printf("|    \n");
        printf("---  \n\n");

        break;

    case 0:
        printf("-----\n");
       printf("|/  |\n");
       printf("|   o\n");
       printf("|  /| \n");
       printf("|   |\n");
       printf("|   // \n");
        printf("---  \n\n");

        break;

    default:
        printf("-----\n");
       printf("|/   \n");
       printf("|    \n");
       printf("|    \n");
       printf("|    \n");
       printf("|    \n");
        printf("---  \n\n");

        break;

    }
}

