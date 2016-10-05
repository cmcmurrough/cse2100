# install the Arduino IDE
#wget https://www.arduino.cc/download_handler.php?f=/arduino-1.6.11-linuxarm.tar.xz
#tar xf ~/Downloads/arduino-1.6.11-linuxarm.tar.xz -C ~/
# cd ~/arduino-1.6.11/install.sh

# download and install the udev rules
wget https://www.pjrc.com/teensy/49-teensy.rules
cp 49-teensy.rules /etc/udev/rules.d/

# download and run the installer
wget https://www.pjrc.com/teensy/td_130/TeensyduinoInstall.linuxarm
chmod +x TeensyduinoInstall.linuxarm
./TeensyduinoInstall.linuxarm
