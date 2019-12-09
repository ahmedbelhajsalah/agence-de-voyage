#include <stdio.h>
#include <string.h>
#include "personne.h"
#include <gtk/gtk.h>
enum
{NOM,
PRENOM,
MAIL,
ADRESSEID,
COLUMNS
};
void ajouter_personne(Personne p)
{
FILE *f;
f=fopen("utilisateur.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s \n",p.nom,p.prenom,p.mail,p.adresseid);
fclose(f);
}
}
void afficher_personne(GtkWidget *liste)
{GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char nom[30];
char prenom[30];
char mail[30];
char adresseid[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("entrynom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("entryprenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("entrymail",renderer,"text",MAIL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("entryadresseid",renderer,"text",ADRESSEID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("utilisateur.txt","r");
if(f==NULL)
{
	return;
}
else
{f=fopen("utilisateur.txt","a+");
while(fscanf(f,"%s %s %s %s \n",nom,prenom,mail,adresseid)!=EOF)
{gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,MAIL,mail,ADRESSEID,adresseid,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);


}
}
}
void supprimer(char adresseid1[])
{
FILE *f;
FILE *f1;
char nom[30];
char prenom[30];
char mail[30];
char adresseid[30];
f=fopen("utilisateur.txt","r");
f1=fopen("temp.txt","w+");
while(fscanf(f,"%s %s %s %s",nom,prenom,mail,adresseid)!=EOF)
{if(strcmp(adresseid,adresseid1)!=0)
fprintf(f1,"%s %s %s %s\n",nom,prenom,mail,adresseid);}

fclose(f);
fclose(f1);
remove("utilisateur.txt");
rename("temp.txt","utilisateur.txt");}
void modifier(char adresseid2[])
{
FILE *f;
FILE *f1;
char nom[30];
char prenom[30];
char mail[30];
char adresseid[30];
f=fopen("utilisateur.txt","r");
f1=fopen("temp.txt","w+");
while(fscanf(f,"%s %s %s %s",nom,prenom,mail,adresseid)!=EOF)
{if(strcmp(adresseid,adresseid2)!=0)
fprintf(f1,"%s %s %s %s\n",nom,prenom,mail,adresseid);}

fclose(f);

fclose(f1);

remove("utilisateur.txt");
rename("temp.txt","utilisateur.txt");}


