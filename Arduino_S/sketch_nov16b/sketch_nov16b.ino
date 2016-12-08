void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  //シリアルポートを9600bpsで初期化
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  char inputchar = Serial.read();

  if(inputchar != -1){
    switch(inputchar){
      case 'h':
      Serial.print("13LED_ON\n");
      Serial.print("12LED_OFF\n");
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      break;

      case'l':
      Serial.print("13LED_OFF\n");
      Serial.print("12LED_OFF\n");
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
      break;
    }
  } else{
    //読み込むデータがない場合は何もしない。
  }
}
