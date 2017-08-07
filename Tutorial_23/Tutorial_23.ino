/* Conexiones
 GND-->GND
 VCC-->VCC
 D0-->D7
*/
int sonido,i;
void setup() {
 Serial.begin(9600);
 pinMode(8,OUTPUT);
 pinMode(0,INPUT);

}

void loop() {
 sonido = analogRead(0);
 if(sonido>60){
  digitalWrite(8,HIGH);
  for(i=0;i<50;i++){
    Serial.print("Velocidad del reloj de Arduino: ");
    Serial.println(i);
  }
 }
  else{
    digitalWrite(8,LOW);
  }
 }

