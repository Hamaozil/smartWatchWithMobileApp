//                                                            SmartWatch with Mobile Application

/*

  Features :
    -Normal clock ---->print the actual time .
    -Timer mode   ---->count down timer (choose time and it alarm you when it reaches zero).
    -StopWatch mode -->count up watch
  All can be controlled via mobile app with the help **hc-05** bluetooth module
*/

//define pins number
#define SER 3
#define LATCH 4
#define CLK 5
#define buzzer 9
#define interval  60000 // فاصل الزمن بالميلي ثانية (1 ثانية)
#define buzzer_interval 5000
//define number representations
byte cathode_numbers[] =
{ //abcdefg0
  B11111100,//0
  B01100000,//1
  B11011010,//2
  B11110010,//3
  B01100110,//4
  B10110110,//5
  B10111110,//6
  B11100000,//7
  B11111110,//8
  B11110110,//9
};
byte anode_numbers[] =
{ //abcdefg0
  B00000011,//0
  B10011111,//1
  B00100101,//2
  B00001101,//3
  B10011001,//4
  B01001001,//5
  B01000001,//6
  B00011111,//7
  B00000001,//8
  B00001001,//9
};

//define variables
unsigned long previousMillis = 0;//store previousMillis for normal clock
unsigned long previousMillisTimer = 0;//store previousMillis for timer clock
unsigned long previousMillisStopWatch = 0;//store previousMillis for stop watch
unsigned long previousMillisbuzzer = 0;//store previousMillis for buzeer
int hours = 0; //actual houres
int minutes = 0; // actual minutes
int StopWatch_seconds = 0;//stopwatch houres tracking
int StopWatch_minutes = 0;// stopwatch minutes tracking
int selected_hours = 0;//to store selected houres from timer
int selected_minutes = 0;//to store selected mintues from timer
int selected_hours_temp = 0;//will be used to decrese selected houres
int selected_minutes_temp = 0;//will be used to decrese selected minutes

//define modes states
bool stopWatch_start = false ;//determine if you start the stopwatch or not (StopWatch1 -->on /StopWatch0 -->off )
bool stopWatch_pause = false ;//determine if you start the stopwatch or not (StopWatch1 -->on /StopWatch0 -->off )
bool timer_start = false ;//determine if you start the timer or not (Timer1 -->on /Timer0 -->off )
bool timer_finised = false;
bool timer_pause = false;
void setup() {
  //pinMode states
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  digitalWrite(buzzer, HIGH); //turn off buzzer
  // keep waiting for bluetooth to be connecting
  while (!(Serial.available()))
  {
    Serial.println("watting for connection........");
  }
  String Time = Serial.readStringUntil("\n");//time recieved
  Time.trim(); // Remove leading/trailing spaces
  //  Serial.println(Time);
  /*
      Time recieved format HH:MM
      split HH from MM and convert them to int
  */
  hours = (Time.substring(0, 2)).toInt();
  minutes = (Time.substring(3)).toInt();
  //  Serial.print("Hours: ");
  //  Serial.print(hours);
  //  Serial.print(", Minutes: ");
  //  Serial.println(minutes);
  previousMillis = millis();
}

void loop() {
  //determine which mode appeare on the 7 segments (stopwatch mode / main clock mode)
  main_clock();//increase time
  if (stopWatch_start || stopWatch_pause)
    Sev_Seg(StopWatch_minutes, StopWatch_seconds);//show houres and minutes
  else
     Sev_Seg(hours, minutes);//show houres and minutes
  mode_selection();//listening to bluetooth
}
