/*音階を出すプログラムなのでここから音を組み合わせて作曲しよう！！！*/

#define BEAT 300
void setup() {
  // put your setup code here, to run once:
   pinMode(12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(12,262,BEAT);//ド
  delay(BEAT);
  tone(12,294,BEAT);//レ
  delay(BEAT);
  tone(12,330,BEAT);//ミ
  delay(BEAT);
  tone(12,349,BEAT);//ファ
  delay(BEAT);
  tone(12,392,BEAT);//ソ
  delay(BEAT);
  tone(12,440,BEAT);//ラ
  delay(BEAT);
  tone(12,494,BEAT);//シ
  delay(BEAT);
  tone(12,523,BEAT);//ド
  delay(3000);//3秒ディレイ
}
