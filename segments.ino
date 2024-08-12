void Sev_Seg(int hours, int minutes) {
  int hour_tens = hours / 10;
  int hour_units = hours % 10;
  int minute_tens = minutes / 10;
  int minute_units = minutes % 10;

  // عرض الساعات

  shift(hour_tens, 0);
  delay(1);
  cl();


  shift(hour_units, 1);
  delay(1);
  cl();

  // عرض الدقائق


  shift(minute_tens, 2);
  delay(1);
  cl();



  shift(minute_units, 3);
  delay(1);
  cl();
}
