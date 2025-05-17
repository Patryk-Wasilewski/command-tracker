#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h> // sudo apt install libgtk-3-dev -y


const char *TRACKING_CONFIG =
    "\n\n#####################################################\n"
    "# CURRENT USED - Command_Tracker - CONFIGURATION\n"
    "#####################################################\n\n"
    "export PROMPT_COMMAND='history -a; echo \"$(whoami)@$(hostname):$(pwd) $ $(history 1 | sed \"s/^ *[0-9]* *//\")\" >> \"$(xdg-user-dir DESKTOP)/CT_command_history.txt\"'\n\n"
    "#####################################################\n";


int main(int argc, char *argv[]) {

    return 0;
}
