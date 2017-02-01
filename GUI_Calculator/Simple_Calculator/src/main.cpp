#include "global.h"


//********************************************************************
// to connect widgets with code
//********************************************************************
void ObtainGuiWidgets(GtkBuilder *p_builder)
{
  #define GuiappGET(xx) gui_app->xx=GTK_WIDGET(gtk_builder_get_object(p_builder,#xx))
  GuiappGET(window1);
  GuiappGET(entry_a);
  GuiappGET(entry_b);
  GuiappGET(button_add);
  GuiappGET(button_exit);
  GuiappGET(label_c); 
}


//********************************************************************
// GUI handlers
//********************************************************************

extern "C" void button_add_clicked(GtkWidget *p_wdgt, gpointer p_data ) 
{
  const char *a_cc_value, *b_cc_value;
  char c_cc_value[20];
  double a_d_value, b_d_value, c_d_value;
   a_cc_value = gtk_entry_get_text(GTK_ENTRY(gui_app->entry_a));
  a_d_value = atof(a_cc_value);
  b_cc_value = gtk_entry_get_text(GTK_ENTRY(gui_app->entry_b));
  b_d_value = atof(b_cc_value);

  c_d_value = a_d_value+b_d_value;
  sprintf(c_cc_value,"%g",c_d_value);

  gtk_label_set_text(GTK_LABEL(gui_app->label_c),c_cc_value);
    
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
