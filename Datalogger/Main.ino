#include <Time.h>  
#include <Wire.h>  
#include <DS3232RTC.h>  // a basic DS1307 library that returns time as a time_t


void setup() {
  Serial.begin(9600);
  while (!Serial) ; // Needed for Leonardo only
  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if (timeStatus() != timeSet) 
     Serial.println("Unable to sync with the RTC");
  else
     Serial.println("RTC has set the system time");     

  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  SD.remove("datalog.txt");
  //createDirectory();
}

void loop(){
  printTime();
  //logData();
}

