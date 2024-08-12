# smartWatchWithMobileApp
In today's modern life, using normal watches isn't fashionable so we have created this smartwatch that can be controlled via Bluetooth with just one click from the application we have developed using Flutter, let's break it down. 

# Hardware used :
- Arduino nano
- Seven Segments
- 8-bit ShiftRegister
- Jumpers
- Resistors
- Buzzer
- Bluetooth module `hc-05`

# Connection :
![image](https://github.com/user-attachments/assets/13911ac9-1667-4140-84c5-5d206f43bae7)

# Main Features :
- Normal clock ----> print the actual time.
- Timer mode   ----> count down timer (choose time and it alarms you when it reaches zero).
- StopWatch mode --> count up watch

# Future added features :
we look forward to adding one more feature like an alarm clock which you can set a specific time and it will alert you when it comes.

# Main concept behind the project:
- the mobile app sends instructions via Bluetooth from your phone to the Bluetooth associated with Arduino `hc-05`, once they are successfully connected the application sends the current time to be displayed on the segments, some of the other instructions are like selected time for timer and timer1 and 0 for starting and pausing the timer besides controlling the stopwatch.
- we have used an 8-bit shift register to reduce the number of Arduino pins.
- A buzzer is used to notify the user that the timer has reached the selected time, once the future feature is added it will also be used for the alarm clock.
