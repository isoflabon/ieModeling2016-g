   
   
   
int val=0;
   
void setup() {
  
  Serial.begin(9600);//シリアル通信を行うための準備
}

void loop() {
  val = analogRead(0);//アナログ入力を受ける関数
  Serial.println(val);//入力された値をモニターに出力
  delay(1000);//１秒待つ
}
