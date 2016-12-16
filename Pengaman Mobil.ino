//Sketch by Kabib.net
//inisial sensor dan relay
int i_depan,i_belakang;
int val_depan,val_belakang;
//Pin-pin
int sensor_depan=1; //A1
int sensor_belakang=0;//A0
int buzzer=7;
int lampudepan_kiri=A3;
int lampudepan_kanan=A4;
int lampubelkg_kanan=A2;
int lampubelkg_kiri=A5;
int relay=13;
int kontrol_roda =15; //A15 (Analog 15);

void setup() {
    pinMode(relay,OUTPUT);
    pinMode(sensor_depan,OUTPUT);
    pinMode(sensor_belakang,OUTPUT);
    pinMode(buzzer,OUTPUT);
    pinMode(lampudepan_kiri,OUTPUT);
    pinMode(lampudepan_kanan,OUTPUT);
    pinMode(lampubelkg_kiri,OUTPUT);
    pinMode(lampubelkg_kanan,OUTPUT);
    Serial.begin(9600);
}
void loop() {
    
    i_depan=analogRead(sensor_depan);//baca nilai sensor depan
    i_belakang=analogRead(sensor_belakang); //baca nilai sensor belakang
    val_depan=(6762/(i_depan-9))-4; //conversi nilai sensor ke cm
    val_belakang=(6762/(i_belakang))-4; //conversi nilai sensor ke cm     
    //jika jarak depan lebih kecil 9 maka motor berhenti dan bunyi
    
    
    int nilai=analogRead(kontrol_roda);//Baca nilai kontrol_roda
    float voltase=nilai*(4.8/1023.0);  //koneversi nilai analog ke voltase dengan maksimal voltase 4.8 sesuai dengan voltase baterai
//    Serial.print("nilai voltase =");Serial.print(voltase);Serial.print("Sensor Depan =");Serial.print(val_depan);Serial.print("Sensor Belakang =");Serial.println(val_belakang);
   
    if(voltase<2 && val_belakang<19){
          berhenti_belakang();
          
     }else if(voltase>2 && val_depan<19){
          berhenti_depan();
          
     }else{jalan();} 
}

void berhenti_belakang()
{
      digitalWrite(buzzer,0);
      digitalWrite(lampubelkg_kiri,HIGH);
      digitalWrite(lampubelkg_kanan,HIGH);
      digitalWrite(relay,LOW);    
}

void berhenti_depan()
{
      digitalWrite(buzzer,0);
      digitalWrite(lampudepan_kiri,HIGH);
      digitalWrite(lampudepan_kanan,HIGH);
      digitalWrite(relay,LOW);    
}

void jalan(){
      digitalWrite(buzzer,1);
      digitalWrite(lampubelkg_kiri,LOW);
      digitalWrite(lampubelkg_kanan,LOW);
      digitalWrite(lampudepan_kiri,LOW);
      digitalWrite(lampudepan_kanan,LOW);
      digitalWrite(relay,HIGH);

}
