#include <glib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "global.h"

#define READ_THREAD_SLEEP_DURATION_US 100000
#define BETWEEN_CHARACTERS_TIMEOUT_US 1000
#define MAX_VOLTAGE 3.3
#define MAX_ADC_VALUE 1024.0
#define POT_COMMAND 'P'

// define packet parameters
#define PACKET_START_BYTE  0xAA
#define PACKET_OVERHEAD_BYTES  3
#define PACKET_MIN_BYTES  PACKET_OVERHEAD_BYTES + 1
#define PACKET_MAX_BYTES  255


gpointer Serial_Read_Thread()
{
  ssize_t r_res;
  char ob[50];
  unsigned int count=0;
  static unsigned char buffer[PACKET_MAX_BYTES];
  unsigned int packetSize = PACKET_MIN_BYTES;
  double voltage_disp;

  while(!kill_all_threads)
    {
      if(ser_dev!=-1)
	{
	  r_res = read(ser_dev,ob,1);
	  //	  cout<<(int)ob[0]<<endl;
	  if(r_res==0)
	    {
	      usleep(BETWEEN_CHARACTERS_TIMEOUT_US);
	    }
	  else if(r_res<0)
	    {
	      cerr<<"Read error:"<<(int)errno<<" ("<<strerror(errno)<<")"<<endl;
	    }
	  else
	    {
	      //this means we have received a byte;
	      //the byte is in ob[0]

	      //TODO: receive an entire packet and validate it.

	      
	      //TODO: Once validated, check if the third byte is a 'P'
	      //decode the payload into a single int between 0 and MAX_ADC_VALUE
	      //convert it into a voltage 0->0V  MAX_ADC_VALUE->MAX_VOLTAGE
	      //load that converted value into voltage_disp
	      //the next three lines need to be there for the value to be
	      //displayed (once you loaded voltage_value with the received
	      //voltage value

	      //once you have voltage_disp calculated us the following three
	      //lines of code to change the global variable c_voltage_value
	      //this is the variable that the main thread periodically displays
	      //in the GUI
	      //g_mutex_lock(mutex_to_protect_voltage_display);
	      //sprintf(c_voltage_value,"%1.3f",voltage_disp);
	      //g_mutex_unlock(mutex_to_protect_voltage_display);
	
	    }
	}
      else
	usleep(READ_THREAD_SLEEP_DURATION_US);
    }

  return NULL;
}
