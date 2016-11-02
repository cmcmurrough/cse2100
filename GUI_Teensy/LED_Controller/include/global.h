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

  GtkWidget *entry_sd; //the text field to contain the name of the serial device
  GtkWidget *label_voltage; // the label on which we display the voltage
  
} Gui_Window_AppWidgets;

extern Gui_Window_AppWidgets *gui_app;

//this is the serial devices handle
extern int ser_dev;

//this is to gracefully shut down threads
extern int kill_all_threads;

//this variable is for communicating the voltage value string
extern char c_voltage_value[40];

//this is the mutex for the above variable
extern GMutex *mutex_to_protect_voltage_display;

//prototype of function for serial read thread
gpointer Serial_Read_Thread();



#endif
