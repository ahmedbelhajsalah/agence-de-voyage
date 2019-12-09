#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "personne.h"




void
on_button_ajouter_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_principale, *window_ajouter;

window_principale=lookup_widget(objet,"window_principale");

gtk_widget_destroy(window_principale);
window_ajouter=create_window_ajouter();
gtk_widget_show(window_ajouter);
}


void
on_button_modifier_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_principale, *window_modifier1;

window_principale=lookup_widget(objet,"window_principale");

gtk_widget_destroy(window_principale);
window_modifier1=create_window_modifier1();
gtk_widget_show(window_modifier1);
}


void
on_button_supprimer_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_principale, *window_supprimer;

window_principale=lookup_widget(objet,"window_principale");

gtk_widget_destroy(window_principale);
window_supprimer=create_window_supprimer();
gtk_widget_show(window_supprimer);
}


void
on_button_retour_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ajouter1_enter               (GtkButton       *objet,
                                        gpointer         user_data)
{
personne p;
FILE *f;
FILE *f1;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7;
GtkWidget *window_ajouter, *dialog1, *erreur;
window_ajouter=lookup_widget(objet,"window_ajouter");
input1=lookup_widget(objet,"entry1");
input2=lookup_widget(objet,"entry2");
input3=lookup_widget(objet,"entry3");
input4=lookup_widget(objet,"entry4");
input5=lookup_widget(objet,"entry5");
input6=lookup_widget(objet,"entry6");
input7=lookup_widget(objet,"entry7");

strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.telephone,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.date,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(p.password,gtk_entry_get_text(GTK_ENTRY(input7)));

ajouter_personne(p);


dialog1 = create_dialog1 ();
  erreur=lookup_widget(dialog1,"label65");
  gtk_label_set_text (GTK_LABEL (erreur), _("ajout avec succés"));
  gtk_widget_show (dialog1);


}

void
on_button_afficher_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_afficher; 
GtkWidget *window_ajouter;
GtkWidget *treeview1;

window_ajouter=lookup_widget(objet,"window_ajouter");

gtk_widget_destroy(window_ajouter);
window_afficher=lookup_widget(objet,"window_afficher");
window_afficher=create_window_afficher();
gtk_widget_show(window_afficher);

treeview1=lookup_widget(window_afficher,"treeview1");
afficher_personne(treeview1);
}


void
on_okbutton1_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
  GtkWidget *dialog;
  dialog=lookup_widget(objet, "dialog1");
  gtk_widget_hide (dialog);
}


void
on_button_retoursup_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_principale, *window_supprimer;

window_supprimer=lookup_widget(objet,"window_supprimer");

gtk_widget_destroy(window_supprimer);
window_principale=create_window_principale();
gtk_widget_show(window_principale);
}


void
on_button_supprimer1_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{


GtkWidget *window_supprimer;
GtkWidget *input1;
  GtkWidget *dialog1;
  GtkWidget *erreur;
  char id[20],idd[20];
  personne p;
  FILE* f1;
  FILE* f2;
  FILE* f3;
 input1=lookup_widget(objet,"entry8");

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(input1)));
  
  f2=fopen("utilisateur.txt","r");
  f3=fopen("idtmp.txt","a");
  while(fscanf(f2,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.cin,p.telephone,p.date,p.id,p.password)!=EOF) {
  if (strcmp(p.id,idd)!=0) {
  fprintf(f3,"%s %s %s %s %s %s %s \n",p.nom,p.prenom,p.cin,p.telephone,p.date,p.id,p.password);
  }}
  fclose(f2);
  fclose(f3);
  remove("utilisateur.txt");
  rename("idtmp.txt","utilisateur.txt");
dialog1 = create_dialog1 ();
  erreur=lookup_widget(dialog1,"label65");
  gtk_label_set_text (GTK_LABEL (erreur), _("Suppression terminée avec succés"));
  gtk_widget_show (dialog1);
}

void
on_button_modifier1_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{



}


void
on_button_retourmd_enter               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_modifier2_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_modifier1,*dialog1,*erreur;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7;

  char id[20];
  personne a;
  personne p;
input1=lookup_widget(objet,"entry10");
input2=lookup_widget(objet,"entry11");
input3=lookup_widget(objet,"entry12");
input4=lookup_widget(objet,"entry13");
input5=lookup_widget(objet,"entry14");
input6=lookup_widget(objet,"entry15");
input7=lookup_widget(objet,"entry16");


  strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(a.telephone,gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(a.date,gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(input6)));
  strcpy(a.password,gtk_entry_get_text(GTK_ENTRY(input7)));

modifier(a);
  dialog1 = create_dialog1 ();
  erreur=lookup_widget(dialog1,"label65");
  gtk_label_set_text (GTK_LABEL (erreur), _("Modification terminée avec succés"));
  gtk_widget_show (dialog1);
}


void
on_button_retourmd2_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_principale, *window_modifier1;

window_modifier1=lookup_widget(objet,"window_modifier1");

gtk_widget_destroy(window_modifier1);
window_principale=create_window_principale();
gtk_widget_show(window_principale);
}


void
on_button_retouraff_clicked            (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter, *window_afficher;

window_afficher=lookup_widget(objet,"window_afficher");

gtk_widget_destroy(window_afficher);
window_ajouter=create_window_ajouter();
gtk_widget_show(window_ajouter);
}


void
on_button_modifiernv_clicked           (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_principale, *window_supprimer;

window_principale=lookup_widget(objet,"window_principale");

gtk_widget_destroy(window_principale);
window_supprimer=create_window_supprimer();
gtk_widget_show(window_supprimer);
}


void
on_button_retouraj_clicked             (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter, *window_principale;

window_ajouter=lookup_widget(objet,"window_ajouter");

gtk_widget_destroy(window_ajouter);
window_principale=create_window_principale();
gtk_widget_show(window_principale);
}

