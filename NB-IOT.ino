#include <DHT.h>;
#include "Magellan.h"
#define DHTTYPE DHT22
#define DHTPIN 7 // ต่อเข้าขา 7
Magellan magel;
//Token Key you can get from magellan platform
char auth[]="718b3b6e-a5d4-4fd2-9045-1cb1d116918f"; // น ารหัสมาใส่บริเวณนี้
String payload;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(9600);
//init Magellan LIB
magel.begin(auth);
// init dht
dht.begin();
}
void loop() {
delay(2000);
// get dht22 data
float h = dht.readHumidity();
float t = dht.readTemperature();
// convert to string
String Temperature=String(t);
String Humidity=String(h);
payload="{\"Temperature\":"+Temperature+",\"Humidity\":"+Humidity+"}";
magel.post(payload);
}
