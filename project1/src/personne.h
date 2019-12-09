#include<gtk/gtk.h>

typedef struct
{
char nom[50];
char prenom[50];
char cin[50] ;
char telephone[50];
char date[50];
char id[50];
char password[50];
}personne;
void ajouter_personne(personne p);
void afiicher_personne(GtkWidget *liste);
void modifier_agent(char identifiant[],personne n);
void modifier(personne p);
