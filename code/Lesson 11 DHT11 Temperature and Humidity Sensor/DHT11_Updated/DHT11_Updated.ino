//www.elegoo.com
//2018.10.25


#include <DHT.h>

DHT dht(2, DHT11);




/*
 * Initialize the serial port.
 */
void setup( )
{
  dht.begin();
  Serial.begin(9600);
}

void loop( )
{
  float temp = dht.readTemperature(true);
  float humidity = dht.readHumidity();
  Serial.println("------------");
  Serial.println("Temperature:");
  Serial.println(temp);
  Serial.println("Humidity:");
  Serial.println(humidity);
  delay(3000);
}
