#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h> // sudo apt install libgtk-3-dev -y


const char *TRACKING_CONFIG =
    "\n\n#####################################################\n"
    "# CURRENT USED - Command_Tracker - CONFIGURATION\n"
    "#####################################################\n\n"
    "export PROMPT_COMMAND='history -a; echo \"$(whoami)@$(hostname):$(pwd) $ $(history 1 | sed \"s/^ *[0-9]* *//\")\" >> \"$(xdg-user-dir DESKTOP)/CT_command_history.txt\"'\n\n"
    "#####################################################\n";


GtkWidget *start_button;
GtkWidget *stop_button;
GtkWidget *warning_label;


void start_tracking(GtkWidget *widget, gpointer data) {
    ;
}

void stop_tracking(GtkWidget *widget, gpointer data) {
    ;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "Command Tracker");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 200);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    start_button = gtk_button_new_with_label("Start Tracking");
    stop_button = gtk_button_new_with_label("End Tracking");
    warning_label = gtk_label_new("Clicking on any button closes all open terminal sessions!");

    gtk_box_pack_start(GTK_BOX(box), start_button, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(box), stop_button, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(box), warning_label, FALSE, FALSE, 10);

    g_signal_connect(start_button, "clicked", G_CALLBACK(start_tracking), NULL);
    g_signal_connect(stop_button, "clicked", G_CALLBACK(stop_tracking), NULL);

    gtk_widget_set_sensitive(stop_button, FALSE);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
