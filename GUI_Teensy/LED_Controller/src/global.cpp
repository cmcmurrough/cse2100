#include "global.h"

Gui_Window_AppWidgets *gui_app; //structure to keep all interesting widgets

int ser_dev=-1;

char c_voltage_value[40];

int kill_all_threads;

GMutex *mutex_to_protect_voltage_display;



  

