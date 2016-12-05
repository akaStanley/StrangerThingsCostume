# Flashing the ESP8266
_thimble.io  |  Spencer Kulbacki  |  August 2016_
This is an explanation on how to flash an ESP8266 with the new V2 espressif firmware.

## Wire Connections
The ESP is "not" 5v tolerant, but many people have been treating it as though it is and have been fine. This is my warning that using a 5v programmer can damage it so be careful! _(In reality though, you'll probably be fine.)_

* Before connecting your FTDI chip to your computer, wire it to the ESP like so:
	* FDTI -> ESP
	* 3.3v -> VCC
	* 3.3v -> CH_PD
	* GND -> GND
	* GND -> GPIO0 (through a resistor to limit current)
	* TX   -> RX
	* RX  -> TX
	* When the ESP is powered on while GPIO0 is tied to ground it will start in flash mode and allow you to program it.
## Program Settings

* Open **ESPFlashDownloadTool_v3.3.4.exe** from the /FLASH_DOWNLOAD_TOOLS_V3.3.4_Win/ folder
* Select the COM port of your FTDI chip; in this example COM5
* Set the baud rate to 115200 (this is only the baud rate of the programming, and can be different than your ESP's configured rate if you've previously set it lower)
* Make sure the *SpiAutoSet* this will allow the programmer to read your ESP for the correct flash, clock, and device id and set the programming settings accordingly.
* Leave all the ```Download Path Config``` boxes unchecked and empty.
* Click start in the bottom right and you should see the ```DETECTED INFO``` box populate with your ESP's information as well as the MAC address in the bottom window.
	* This information is also seen in the terminal window that opens with the program.

## Selecting The binary
* For an ESP matching the settings shown in the settings.png image in this folder I have already created a combined Binary (.bin) to be used.
* Click the ```...``` to the right of the first box at the top of the program and select the ```CombinedFiles.bin``` file from the same folder this readme is in.
* Enter the offset of ```0x00000``` (that is 0x with five zeros after it)
* click the checkbox on the left and you should see both boxes on that line turn green. If so that means you are all set.
	 * If not, then you may have not properly selected the .bin file or it has been moved to a different location since you selected it.
* With you ESP and FTDI chip still powered on and connected from the steps above, click the ```START``` button and you should see the progress shown in the terminal window.
* Once the progress reaches 100% your ESP is now programmed. 
* The last thing to do is test and set the baud rate of your ESP to work with an Arduino. To verify you can use the ESP_AT_Test.ino to test the AT commands with your ESP.
	* Run the sketch and with your serial monitor set to 115200 baud send this AT command: ``` AT+UART_DEF=9600,8,1,0,0```  

## Selecting Custom binaries or Updating to a Newer Version
* Included in the \bin folder is a set of binaries for various specifications of ESP8266s. This can be downloaded from the Espressif site by searching ```ESP8266 Firmware SDK``` online.
* To program the ESP with a different or newer set of firmware than what is pre-built here make sure you use the following files and offests:
	* ```\bin\boot_v.16.bin``` @ 0x00000
	* ```\bin\at\512+512\user1.1024.new.2.bin``` @ 0x01000
		* (the 512+512 or 1024+1024 folders correspond to your ESP's Flash sizes)
	* ```\bin\esp_init_data_default.bin``` @ 0x3fc000
	* ```\bin\blank.bin``` @ 0x7e000
	* ```\bin\blank.bin``` @ 0x3fe000
* With these files selected as in the settings.png image, clicking the ```START``` button will program your ESP.
	* You can also use the ```CombineBin``` button to generate a single bin file using the files and offsets above. That is how I made the ```CombinedFiles.bin```from earlier.

##Troubleshooting
* Make sure your TX/RX lines are correct, some FTDI programmers label them as the device sees is and therefor should be connected TX->TX and RX->RX
* If the programmer is not recognizing your ESP make sure that GPIO0 is connected to ground *BEFORE* you power it on. 
	* Most times (if it's wired correctly) unplugging the whole setup from your computer's USB port and plugging it back in is enough to reset the ESP back into Flashing mode.
* the deafult baudrate for an ESP is 115200, which can cause issues for Arduino ESP libraries:
	* Run this AT command to set your ESP's baud rate to 9600 ``` AT+UART_DEF=9600,8,1,0,0```  