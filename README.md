# wifi-cw-keyboard-keyer   for Ham Radio CW operation####


#### Upload and  RUN "eeprom_clear.ino"  even before uploading the real "wifi-cw-keyer.ino" #####

# Provide 3.3V DC to ESP12 Module
Keep the two files ( index.h and wifi-keyboard-cw-keyer.ino ) in same folder before uploading to ESP12
After uploading the sketch, apply reset to ESP12, this will start AP Mode and create WiFi Hotspot named "14-dec-2022-5"
Join the wifi network using a laptop computer ( or Smart Phone)
Now open the Broswer (example : Chrome browser) and navigate to URL , http://192.168.4.1/
A web page opens where you can type in Messages in English >> This messages are are transilated as CW (Telegraphy messages)
and send out as digital pulses in Pin 5 (GPIO-5 Pin of ESP12 Module)
Make proper wiring to drive your Transceiver to work with CW

73's
de VU3AVE, Anish , Kerala , India
