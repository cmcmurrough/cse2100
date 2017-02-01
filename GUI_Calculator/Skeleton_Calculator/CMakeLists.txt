#Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.6)

#Name of the project
project(Calculator)

# make cmake aware that we have all our header files in the 
# include subdirectory (the include path should contain that)
include_directories(include)

# find_package can include third party packages into cmake
# the pkgconfig tool is included which is used by some libraries
# to find out how they should be used whne compiling
# e.g.,  try on the command line: pkg-config --cflags glib-2.0
find_package(PkgConfig REQUIRED)

# now that we can use pkg-config, let's use it to find everything 
# about glib-2.0; everything that is found will be 
# prefixed by GLIB_PKG
pkg_check_modules(GTK_PKG gtk+-3.0)

# the _FOUND postfix will be set if the package has actually been found
if(${GTK_PKG_FOUND})
  #print message for user:
  #message(STATUS "Found:glib-2.0")
  #make sure "include directories" contains the glib header directories
  include_directories(${GTK_PKG_INCLUDE_DIRS})
  #make sure "link directories" contains the glib library directories
  link_directories(${GTK_PKG_LIBRARY_DIRS})
else()
  #print message for user:
  message(FATAL_ERROR "gtk+-3.0 not found. It is required. exiting.")
endif()

#Could manually add the sources using the set command as follows:
#set(SOURCES src/global.cpp src/worker_thread.cpp src/main.cpp)
# but we can just use the following to add all cpp files:
file(GLOB SOURCES "src/*.cpp") 

#This tells cmake to create the executable based on those sources
add_executable(Calculator ${SOURCES})

# tells cmake to use the required libraries (in this case glib)
target_link_libraries (Calculator ${GTK_PKG_LIBRARIES})

file(GLOB GLADE_FILES "src/*.glade")
file(COPY ${GLADE_FILES} DESTINATION ".")
