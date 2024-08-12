void cl() {
  digitalWrite(LATCH, LOW); //ready for writing
  shiftOut(SER, CLK, LSBFIRST, B00000000); //set all segments to LOW
  shiftOut(SER, CLK, LSBFIRST, B00000000); //set all segments to LOW
  digitalWrite(LATCH, HIGH); //done writting
}
