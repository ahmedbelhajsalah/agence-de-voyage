#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "personne.h"

void
on_buttonajouterclient_clicked         (GtkButton       *objet,
                                        gpointer         user_data)
{GtkWidget *windowgererclient;
GtkWidget *windowajouterclient;
windowgererclient=lookup_widget(objet,"windowgererclient");
gtk_widget_destroy(windowgererclient);
windowajouterclient=lookup_widget(objet,"windowajouterclient");
windowajouterclient=create_windowajouterclient();
gtk_widget_show(windowajouterclient);

}


void
on_buttonajouter_clicked               (GtkButton       *objet,
                                        gpointer         user_data)
{
Personne p;
GtkWidget *input1,*input2,*input3,*input4;
GtkWidget *windowajouterclient;
windowajouterclient=lookup_widget(objet,"windowajouterclient");
input1=lookup_widget(objet,"entrynom");
input2=lookup_widget(objet,"entryprenom");
input3=lookup_widget(objet,"entrymail");
input4=lookup_widget(objet,"entryadresseid");
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.mail,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.adresseid,gtk_entry_get_text(GTK_ENTRY(input4)));
ajouter_personne(p);
}


void
on_buttonafficher_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowajouterclient;
GtkWidget *windowafficherclient;
GtkWidget *treeview1;
windowajouterclient=lookup_widget(objet,"windowajouterclient");
gtk_widget_destroy(windowajouterclient);
windowafficherclient=lookup_widget(objet,"windowafficherclient");
windowafficherclient=create_windowafficherclient();
gtk_widget_show(windowafficherclient);
treeview1=lookup_widget(windowafficherclient,"treeview1");
afficher_personne(treeview1);


}


void
on_buttonsupprimerclient_clicked       (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgererclient;
GtkWidget *windowsupprimerclient;
windowgererclient=lookup_widget(objet,"windowgererclient");
gtk_widget_destroy(windowgererclient);
windowsupprimerclient=lookup_widget(objet,"windowsupprimerclient");
windowsupprimerclient=create_windowsupprimerclient();
gtk_widget_show(windowsupprimerclient);

}


void
on_buttonsupprimer_clicked             (GtkButton       *objet,
                                        gpointer         user_data)

{
char adresseid1[30];
GtkWidget *input1;
GtkWidget *windowsupprimerclient;
windowsupprimerclient=lookup_widget(objet,"windowsupprimerclient");
input1=lookup_widget(objet,"entrysupprimer");
strcpy(adresseid1,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer(adresseid1);

}


void
on_buttonmodifierclient_clicked        (GtkButton       *objet,
                                        gpointer         user_data)

{
GtkWidget *windowgererclient;
GtkWidget *windowselectionclient;
windowgererclient=lookup_widget(objet,"windowgererclient");
gtk_widget_destroy(windowgererclient);
windowselectionclient=lookup_widget(objet,"windowselectionclient");
windowselectionclient=create_windowselectionclient();
gtk_widget_show(windowselectionclient);
}


void
on_buttonslection_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
char adresseid1[30];
GtkWidget *input1;
GtkWidget *windowselectionclient;
GtkWidget *windowmodifierclient;
windowselectionclient=lookup_widget(objet,"windowselectionclient");
input1=lookup_widget(objet,"entrymodifier");
strcpy(adresseid1,gtk_entry_get_text(GTK_ENTRY(input1)));
supprimer(adresseid1);
gtk_widget_hide(windowselectionclient);
windowmodifierclient=lookup_widget(objet,"windowmodifierclient");
windowmodifierclient=create_windowmodifierclient();
gtk_widget_show(windowmodifierclient);
}


void
on_buttonmodifier_clicked              (GtkButton       *objet,
                                        gpointer         user_data)

{
Personne pm;
GtkWidget *input2,*input3,*input4,*input5;
GtkWidget *windowselectionclient;
GtkWidget *windowmodifierclient;
windowselectionclient=lookup_widget(objet,windowselectionclient);
windowmodifierclient=lookup_widget(objet,windowmodifierclient);
input2=lookup_widget(objet,"entrynommodifier");
input3=lookup_widget(objet,"entryprenommodifier");
input4=lookup_widget(objet,"entrymailmodifier");
input5=lookup_widget(objet,"entryadresseidmodifier");
strcpy(pm.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(pm.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(pm.mail,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(pm.adresseid,gtk_entry_get_text(GTK_ENTRY(input5)));


ajouter_personne(pm);

}







void
on_buttonretourgererclient1_clicked    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgererclient;
GtkWidget *windowajouterclient;
windowajouterclient=lookup_widget(objet,"windowajouterclient");
gtk_widget_destroy(windowajouterclient);
windowgererclient=lookup_widget(objet,"windowgererclient");
windowgererclient=create_windowgererclient();
gtk_widget_show(windowgererclient);

}


void
on_buttonretourgererclient2_clicked    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgererclient;
GtkWidget *windowsupprimerclient;
windowsupprimerclient=lookup_widget(objet,"windowsupprimerclient");
gtk_widget_destroy(windowsupprimerclient);
windowgererclient=lookup_widget(objet,"windowgererclient");
windowgererclient=create_windowgererclient();
gtk_widget_show(windowgererclient);



}


void
on_buttonretourgererclient3_clicked    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowgererclient;
GtkWidget *windowselectionclient;
windowselectionclient=lookup_widget(objet,"windowselectionclient");
gtk_widget_destroy(windowselectionclient);
windowgererclient=lookup_widget(objet,"windowgererclient");
windowgererclient=create_windowgererclient();
gtk_widget_show(windowgererclient);

}


void
on_buttonretourajouterclient_clicked   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowafficherclient;
GtkWidget *windowajouterclient;
windowafficherclient=lookup_widget(objet,"windowafficherclient");
gtk_widget_destroy(windowafficherclient);
windowajouterclient=lookup_widget(objet,"windowajouterclient");
windowajouterclient=create_windowajouterclient();
gtk_widget_show(windowajouterclient);


}


void
on_buttonretourselectionclient_clicked (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowmodifierclient;
GtkWidget *windowselectionclient;
windowmodifierclient=lookup_widget(objet,"windowmodifierclient");
gtk_widget_destroy(windowmodifierclient);
windowselectionclient=lookup_widget(objet,"windowselectionclient");
windowselectionclient=create_windowselectionclient();
gtk_widget_show(windowselectionclient);


}

