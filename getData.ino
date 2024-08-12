void mode_selection()
{
  if (Serial.available()) {
    String mode = Serial.readStringUntil("\n");
    mode.trim(); // Remove leading/trailing spaces
    Serial.println(mode);
    if (mode.length() > 10) //get selected time for timer
    {
      mode = mode.substring(mode.indexOf(':') + 1);//substring time
      Serial.println(mode);
      //will be used in condition of 1th run and restart
      selected_hours = (mode.substring(0, 2)).toInt();//select houres
      selected_minutes = (mode.substring(3)).toInt();//select minutes
      //      Serial.print("Hours: ");
      //      Serial.print(selected_hours);
      //      Serial.print(", Minutes: ");
      //      Serial.println(selected_minutes);
    }
    else if (mode == "Timer1" && !timer_pause) //timer start
    {
      //Serial.println("1th start");
      timer_start = true;//timer on
      timer_pause = false;//no pause
      previousMillisTimer = millis();//start tracking time
      selected_hours_temp = selected_hours;//temp for houres that will be changed
      selected_minutes_temp = selected_minutes;//temp for minutes that will be changed
    }
    else if (mode == "Timer1" && timer_pause) //timer restart
    {
      //Serial.println("start after pause");
      timer_start = true;//2nd start

    }
    else if (mode == "Timer3") //timer restart
    {
      //Serial.println("restart");
      timer_pause = false;
      selected_hours_temp = selected_hours;
      selected_minutes_temp = selected_minutes;
    }
    else if (mode == "Timer0") //timer pause
    {
      //Serial.println("pause");
      timer_start = false;
      timer_pause = true;//pause wait for another start
      previousMillisTimer = millis();
    }
    
    else if (mode == "StopWatch1" && !stopWatch_pause)//stop watch 1th start
    {
      //Serial.println("1th start");
      stopWatch_start = true;
      stopWatch_pause = false;
      previousMillisStopWatch = millis();
    }
    else if (mode == "StopWatch1" && stopWatch_pause)//stop watch 2nd start
    {
      //Serial.println("start after pause");
      stopWatch_start = true;
    }
    else if (mode == "StopWatch0") //timer pause
    {
      //Serial.println("pause");
      stopWatch_pause = true;//pause wait for another start
      stopWatch_start = false;
      previousMillisStopWatch = millis();
    }
    else if (mode == "StopWatch3") //timer reset
    {
      stopWatch_pause = false;
      stopWatch_start = false;
      StopWatch_seconds = 0;
      StopWatch_minutes = 0; 
    }
  }
  if (timer_finised)// timer has finished successfully
  {
    if (millis() - previousMillisbuzzer < buzzer_interval)
      digitalWrite(buzzer, LOW); //turn on buzzer
    else
    {
      digitalWrite(buzzer, HIGH); //turn off buzzer
      timer_finised = false;
    }
  }
}
