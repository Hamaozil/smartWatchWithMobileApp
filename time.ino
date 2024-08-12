void main_clock()
{
  if (millis() - previousMillis >= interval) {//normal clock
    previousMillis = millis();

    //normal clock increase minutes with 1 every second
    minutes++;
    if (minutes >= 60)
    {
      minutes = 0;
      hours++;
      if (hours == 24)
      {
        hours = 0;
      }
    }
  }
  //stopwatch on
  if (stopWatch_start)
  {
    if (millis() - previousMillisStopWatch >= 1000) {//normal clock
      previousMillisStopWatch = millis();
      
      StopWatch_seconds++;
      if(StopWatch_seconds>=60)
        StopWatch_minutes++;
    }
  }
  //timer start is on
  if (timer_start)
  {
    if (millis() - previousMillisTimer >= interval)
    {
      previousMillisTimer = millis();
      if (selected_minutes_temp == 0 && selected_hours_temp != 0) //there are houres left but minutes reaches 0 decrese houres and initiate minutes =60
      {
        selected_minutes_temp = 60;
        selected_hours_temp--;
      }
      else
        selected_minutes_temp--; //normal case decrease minutes

      if (selected_minutes_temp == 0 && selected_hours_temp == 0)//if both are 0 means its finshed
      {
        timer_finised = true;
        timer_start = false;// to make sure it wont enter this body again
        Serial.println("time is over");
        previousMillisbuzzer = millis();
      }
      Serial.print("selected Hours: ");
      Serial.print(selected_hours_temp);
      Serial.print(", selected Minutes: ");
      Serial.println(selected_minutes_temp);
    }
  }
}
