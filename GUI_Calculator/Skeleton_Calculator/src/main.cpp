#include "global.h"
#include "string.h"

//********************************************************************
// to connect widgets with code
//********************************************************************
void ObtainGuiWidgets(GtkBuilder *p_builder)
{
  #define GuiappGET(xx) gui_app->xx=GTK_WIDGET(gtk_builder_get_object(p_builder,#xx))
  GuiappGET(window1);
  GuiappGET(label_result);
  GuiappGET(button_1);
  GuiappGET(button_2);
  GuiappGET(button_pl);
  GuiappGET(button_exit);
}


//********************************************************************
// GUI handlers
//********************************************************************

extern "C" void button_1_clicked(GtkWidget *p_wdgt, gpointer p_data ) 
{
  const char *a_cc_value;
  char c_cc_value[20];
  int a_d_value=0;
  if(!clear_f)
    {
       a_cc_value = gtk_label_get_text(GTK_LABEL(gui_app->label_result));
       a_d_value = atoi(a_cc_value);
       a_d_value*=10;
    }
  a_d_value+=1;
  clear_f=false;
  
  sprintf(c_cc_value,"%d",a_d_value);
  
  gtk_label_set_text(GTK_LABEL(gui_app->label_result),c_cc_value);
}

extern "C" void button_2_clicked(GtkWidget *p_wdgt, gpointer p_data ) 
{
  const char *a_cc_value;
  char c_cc_value[20];
  int a_d_value=0;
  if(!clear_f)
    {
       a_cc_value = gtk_label_get_text(GTK_LABEL(gui_app->label_result));
       a_d_value = atoi(a_cc_value);
       a_d_value*=10;
    }
  a_d_value+=2;
  clear_f=false;
  
  sprintf(c_cc_value,"%d",a_d_value);
  
  gtk_label_set_text(GTK_LABEL(gui_app->label_result),c_cc_value);
}

extern "C" void button_pl_clicked(GtkWidget *p_wdgt, gpointer p_data ) 
{
  const char *a_cc_value;
  char c_cc_value[20];
  double a_d_value;
  a_cc_value = gtk_label_get_text(GTK_LABEL(gui_app->label_result));
  a_d_value = atoi(a_cc_value);
  
  switch (last_function)
    {
       case 1:
	 operand-=a_d_value;
	 break;
       case 2:
	 operand*=a_d_value;
	 break;
       case 3:
	 operand/=a_d_value;
	 break;
       case 0:
	 operand+=a_d_value;
	 break;
       default:
	 break;
    }

  last_function=0;
  clear_f = true;

  sprintf(c_cc_value,"%d",operand);

  gtk_label_set_text(GTK_LABEL(gui_app->label_result),c_cc_value);
}


extern "C" void button_exit_clicked(GtkWidget *p_wdgt, gpointer p_data ) 
{
  gtk_main_quit();

}

//********************************************************************
//********************************************************************
// 
//   Main loop
//
//********************************************************************
//********************************************************************

int main(int argc, char **argv)
{

  GtkBuilder *builder;
  GError *err = NULL;

  // Now we initialize GTK+ 
  gtk_init(&argc, &argv);
  
  //create gtk_instance for visualization
  gui_app = g_slice_new(Gui_Window_AppWidgets);

  //builder
  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "calculator.glade", &err);
  
  //error handling
  if(err)
    {
      g_error(err->message);
      g_error_free(err);
      g_slice_free(Gui_Window_AppWidgets, gui_app);
      exit(-1);
    }

  // Obtain widgets that we need
  ObtainGuiWidgets(builder);

  // Connect signals
  gtk_builder_connect_signals(builder, gui_app);

  // Destroy builder now that we created the infrastructure
  g_object_unref(G_OBJECT(builder));

  //display the gui
  gtk_widget_show(GTK_WIDGET(gui_app->window1));

  //the main loop
  gtk_main();
 
  //destroy gui if it still exists
  if(gui_app)
    g_slice_free(Gui_Window_AppWidgets, gui_app);

  return 0;
}
