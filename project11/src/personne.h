#include <gtk/gtk.h>
typedef struct
{
char nom[20];
char prenom[20];
char mail[20];
char adresseid[20];
}Personne;
void ajouter_personne(Personne p);
void afficher_personne(GtkWidget *liste);
void supprimer(char adresseid1[]);
void modifier(char adresseid2[]);
void supprimer(char adresseid2[]);
