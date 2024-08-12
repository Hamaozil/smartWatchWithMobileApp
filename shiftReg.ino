void shift(byte number, byte num_com) {

  digitalWrite(LATCH, LOW); //ready for writing
  if (num_com == 0)
  {
    shiftOut(SER, CLK, LSBFIRST, B00111111); //D0
    shiftOut(SER, CLK, LSBFIRST, cathode_numbers[number]); //set number
  }
  else if (num_com == 1)
  {
    shiftOut(SER, CLK, LSBFIRST, B11111111); //D1
    shiftOut(SER, CLK, LSBFIRST, anode_numbers[number]); //set number
  }
  else if (num_com == 2)
  {
    shiftOut(SER, CLK, LSBFIRST, B10011111); //D2
    shiftOut(SER, CLK, LSBFIRST, cathode_numbers[number]); //set number
  }
  else if (num_com == 3)
  {
    shiftOut(SER, CLK, LSBFIRST, B10101111); //d3
    shiftOut(SER, CLK, LSBFIRST, cathode_numbers[number]); //set number
  }

  digitalWrite(LATCH, HIGH); //done writting

}
