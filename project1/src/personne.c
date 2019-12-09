#include<stdio.h>
#include<string.h>
#include"personne.h"
#include<gtk/gtk.h>






enum
{
NOM,
PRENOM,
CIN,
TELEPHONE,
DATE,
ID,
PASSWORD,
COLUMNS
};


void ajouter_personne(personne p)
{

FILE *f;
char id[30];
f=fopen("utilisateur.txt","a+");
if(f!=NULL)
{

fprintf(f,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.cin,p.telephone,p.date,p.id,p.password);
fclose(f);
}
}


void afficher_personne(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[50];
char prenom[50];
char cin[50];
char telephone[50];
char date[50];
char id[50];
char password[50];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nom",renderer, "text",NOM, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(" prenom",renderer, "text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",CIN, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" telephone", renderer, "text",TELEPHONE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" date", renderer, "text",DATE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" id", renderer, "text",ID, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" password", renderer, "text",PASSWORD, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f= fopen("utilisateur.txt", "r");
if(f==NULL)
{
return;
}
else
{ f= fopen("utilisateur.txt", "a+");
       while(fscanf(f,"%s %s %s %s %s %s %s \n", nom,prenom,cin,telephone,date,id,password)!=EOF)
    {
gtk_list_store_append (store, &iter);

gtk_list_store_set (store, &iter, NOM, nom, PRENOM, prenom, CIN, cin, TELEPHONE, telephone, DATE, date, ID, id, PASSWORD, password -1);
     }
     fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}





void modifier(personne p)
{

personne a;
FILE *f;
FILE *f1;
f1=NULL;
f=fopen("utilisateur.txt","r");
f1=fopen("temp.txt","w");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s  %s %s %s %s \n",a.nom ,a.prenom ,a.cin,a.telephone,a.date,a.id,a.password)!=EOF)
{
    if(strcmp(a.id,p.id)!=0)
     {
       fprintf(f1,"%s %s %s  %s %s %s %s \n",a.nom ,a.prenom ,a.cin,a.telephone,a.date,a.id,a.password);
     }
     else if(strcmp(a.id,p.id)==0)
     {
        fprintf(f1,"%s %s %s  %s %s %s %s \n",p.nom ,p.prenom ,p.cin,p.telephone,p.date,p.id,p.password);
     }
}
fclose(f1);
fclose(f);
remove("utilisateur.txt");
rename("temp.txt","utilisateur.txt");


}
}
