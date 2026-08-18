#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

// DHT11 Configuration
#define DHTPIN 4          // DHT11 DATA connected to D4 (GPIO2)
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


// WiFi Details
const char* ssid = "vivo Y28 5G";
const char* password = "123456789";


// ThingSpeak Details
unsigned long channelID = 3429562;
const char* apiKey = "CWP8XJWCAF8I2G4I";


WiFiClient client;


void setup()
{
  Serial.begin(115200);

  dht.begin();

  Serial.println();
  Serial.print("Connecting to WiFi");


  WiFi.begin(ssid, password);


  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }


  Serial.println();
  Serial.println("WiFi Connected!");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());


  ThingSpeak.begin(client);
}



void loop()
{

  // Read DHT11 values
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();


  // Check sensor reading
  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("DHT11 Sensor Error");
    delay(2000);
    return;
  }


  // Calculate Heat Index
  float heatIndex = dht.computeHeatIndex(
    temperature,
    humidity,
    false
  );


  // Get WiFi signal strength
  int wifiStrength = WiFi.RSSI();



  // Display values on Serial Monitor

  Serial.println("--------------------");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");


  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");


  Serial.print("Heat Index: ");
  Serial.print(heatIndex);
  Serial.println(" °C");


  Serial.print("WiFi Signal: ");
  Serial.print(wifiStrength);
  Serial.println(" dBm");



  // Send data to ThingSpeak

  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, heatIndex);
  ThingSpeak.setField(4, wifiStrength);



  int status = ThingSpeak.writeFields(channelID, apiKey);



  if (status == 200)
  {
    Serial.println("Data uploaded successfully!");
  }
  else
  {
    Serial.print("Upload failed. Error code: ");
    Serial.println(status);
  }



  Serial.println("--------------------");


  // ThingSpeak requires minimum 15 seconds
  delay(20000);
}