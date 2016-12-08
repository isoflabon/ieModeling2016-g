/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

/*これは、12番ポートと13番ポートに接続されたLEDを交互にチカチカさせるプログラム*/
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);//13番ポートを出力に設定
  pinMode(12, OUTPUT); //12番ポートを出力に設定
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   //13番ポートに繋がれたLEDを点灯
  digitalWrite(12, LOW);    //12番ポートに繋がれたLEDを消灯
  delay(100);              // 1/10秒待つ
  digitalWrite(12, HIGH);   //12番ポートに繋がれたLEDを点灯
  digitalWrite(13, LOW);    //13番ポートに繋がれたLEDを消灯
  delay(100);              
}
