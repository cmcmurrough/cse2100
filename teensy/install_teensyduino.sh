# install the Arduino IDE
apt-get install arduino

# download and install the udev rules
wget https://www.pjrc.com/teensy/49-teensy.rules
cp 49-teensy.rules /etc/udev/rules.d/

# download and run the installer
wget https://www.pjrc.com/teensy/td_130/TeensyduinoInstall.linuxarm
./TeensyduinoInstall.linuxarm
