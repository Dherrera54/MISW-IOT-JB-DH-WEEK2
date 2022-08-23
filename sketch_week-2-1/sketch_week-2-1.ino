#include <DHT.h>
#include <DHT_U.h>
#define DHTTYPE DHT11   // DHT 11

#define dht_dpin 4
DHT dht(dht_dpin, DHTTYPE);

#define LED D1 // LED
int ValueRead=2;
int myflag=0;
int light_raw = A0;

int light;

void setup()
{
 Serial.begin(9600);
 dht.begin();
 
 pinMode(LED, OUTPUT);
 digitalWrite(LED, LOW); //LED comienza apagado
 pinMode(light_raw, INPUT);

}

void loop()
{
 if (Serial.available()){
   ValueRead=Serial.parseInt();
 }
   if (((ValueRead==1 && myflag==0)|| myflag==1)&!(ValueRead==2 && myflag==1)){
     digitalWrite(LED, HIGH);  // Se prende el LED
     Serial.println("Prendido");
     myflag=1;
   }
   else{
     digitalWrite(LED, LOW);   // Se apaga el LED
     Serial.println("Apagado");
     myflag=0;
   }
 
  //valores variables 
 float h = dht.readHumidity();
 float t = dht.readTemperature();

 int lightSensorValue = analogRead(light_raw);

 light = map(lightSensorValue, 16 ,1024, 0, 100);


 
 Serial.print("Current humidity = ");
 Serial.print(h);
 Serial.print("%  ");
 Serial.print("temperature = ");
 Serial.print(t);
 Serial.println("C  ");
 Serial.print("Light sensor raw = ");
 Serial.print(lightSensorValue);
 Serial.print("  Light = ");
 Serial.print(light);
 Serial.println("%  ");
 delay(500);
}
