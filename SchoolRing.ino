
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// Replace with your network credentials
const char *ssid     = "NOTAH@CKER";
const char *password = "notahacker";
int buzzer = 5;


// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

//Week Days
String weekDays[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//Month names
String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  pinMode(buzzer,OUTPUT);
  // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

// Initialize a NTPClient to get time
  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(14400);
}

void loop() {
  timeClient.update();

  time_t epochTime = timeClient.getEpochTime();
  Serial.print("Epoch Time: ");
  Serial.println(epochTime);
  
  String formattedTime = timeClient.getFormattedTime();
  Serial.print("Formatted Time: ");
  Serial.println(formattedTime);  

  int currentHour = timeClient.getHours();
  Serial.print("Hour: ");
  Serial.println(currentHour);  

  int currentMinute = timeClient.getMinutes();
  Serial.print("Minutes: ");
  Serial.println(currentMinute); 
  
  int currentSecond = timeClient.getSeconds();
  Serial.print("Seconds: ");
  Serial.println(currentSecond);  

  String weekDay = weekDays[timeClient.getDay()];
  Serial.print("Week Day: ");
  Serial.println(weekDay);    

  //Get a time structure
  struct tm *ptm = gmtime ((time_t *)&epochTime); 

  int monthDay = ptm->tm_mday;
  Serial.print("Month day: ");
  Serial.println(monthDay);

  int currentMonth = ptm->tm_mon+1;
  Serial.print("Month: ");
  Serial.println(currentMonth);

  String currentMonthName = months[currentMonth-1];
  Serial.print("Month name: ");
  Serial.println(currentMonthName);

  int currentYear = ptm->tm_year+1900;
  Serial.print("Year: ");
  Serial.println(currentYear);

  //Print complete date:
  String currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay);
  Serial.print("Current date: ");
  Serial.println(currentDate);

Serial.println("");
  String hour = String(currentHour); 
  String minute = String(currentMinute); 
  String seconde = String(currentSecond); 
  if(currentDate != "Sunday" && currentDate != "Saturday"){
    if(hour == "09" && minute == "00" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
    if(hour == "09" && minute == "45" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
    if(hour == "09" && minute == "50" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
    if(hour == "10" && minute == "35" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
    if(hour == "10" && minute == "40" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
    if(hour == "11" && minute == "25" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
    if(hour == "11" && minute == "35" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
    if(hour == "12" && minute == "20" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
    if(hour == "12" && minute == "25" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
    if(hour == "13" && minute == "10" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
    if(hour == "13" && minute == "15" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
    if(hour == "14" && minute == "00" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
    if(hour == "14" && minute == "05" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
    if(hour == "14" && minute == "50" && seconde == "00"){
        tone(buzzer,1040);
        delay(10000);
        tone(buzzer,1040);
    }
  }
  delay(2000);
}