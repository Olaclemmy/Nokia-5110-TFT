# Nokia-5110-TFT
Connect your Arduino to the ubiquitous Nokia 5110 TFT - see video #89 at https://www.youtube.com/RalphBacon

I guess *everyone* has a 5110 TFT display in their components box so now's your chance to actually connect it up!

Wassat? You DON'T have one? Are you crazy? At this price why haven't you got one (or two)? They might only be black and white but they are so easy to use and can display so much info, including graphics (that I'll have to cover separately in another video) although I do have a go at creating a custom graphic character.

The only "downside" is that they are a 3.3-volt device so some *simple* voltage level shifting is required but that is so easy Benny (my cat) could solder it all together in 5 minutes. (He says 4 minutes, but who's counting?) In fact there are TWO easy ways to level shift the 5 volts from your Arduino down to 3.3 volts and I cover them both.

Of course, if you use an Arduino that is already 3.3 volts then no voltage level shifting is required (eg Sparkfun Pro Micro, Arduino Due, Arduino Pro [3.3v]) and you can connect your Arduino directly to the TFT.

TINA TI (Texas Instruments) free version
http://www.ti.com/tool/tina-ti

TINA v11 from DesignSoft (Academic & Professional versions available)
https://www.tina.com/

Nokia TFT Library PCD8544
https://github.com/carlosefr/pcd8544

Philips PCD8544 Chip Data Sheet
https://cdn-shop.adafruit.com/datasheets/pcd8544.pdf

Pin connections for Nokia 5110 Red Module as used in my demo ONLY

Nokia			     Arduino
Pin				     Pin (__via voltage shifter__)

1 RST--------- 6 - reset 
2 CE---------- 7 - chip selection 
3 DC---------- 5 - data/commands choice 
4 DIN--------- 4 - serial data line 
5 CLK--------- 3 - serial Clock  
6 3.3V-------- VCC 3.3V ONLY
7 LIGHT------- 8 - backlight LED, connect to GND to light up
8 GND--------- Ground
