#include <gtk/gtk.h>
#include <stdlib.h>
#include <iostream>
#define __STDC_FORMAT_MACROS


#ifndef _MY__GLOBAL__H
#define _MY__GLOBAL__H

using namespace std;

/**************************************************************
 * GUI window stuff
 **************************************************************/

typedef struct 
{
  GtkWidget *window1; //visualization window

  GtkWidget *entry_a;  // the entry field for a
  GtkWidget *entry_b;  // the entry field for b

  GtkWidget *label_c;  // the label for the output

  GtkWidget *button_add;  //the add button
  GtkWidget *button_exit;  //the exit button

} Gui_Window_AppWidgets;

extern Gui_Window_AppWidgets *gui_app;

#endif
