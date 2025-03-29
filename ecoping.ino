#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

// WiFi
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// ThingSpeak
unsigned long channelID = YOUR_CHANNEL_ID;
const char* writeAPIKey = "YOUR_API_KEY";

// DHT Sensor
#define DHTPIN 4        // GPIO 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// MQ-135
#define MQPIN 34        // Analog pin for air quality

// Sound Sensor
#define SOUND_PIN 35    // Analog pin for noise level

WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected.");
  ThingSpeak.begin(client);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int airQuality = analogRead(MQPIN);       // Raw value
  int noiseLevel = analogRead(SOUND_PIN);   // Raw value

  Serial.println("--- EcoPing Readings ---");
  Serial.printf("Temp: %.2f °C\n", temperature);
  Serial.printf("Humidity: %.2f %%\n", humidity);
  Serial.printf("Air Quality: %d\n", airQuality);
  Serial.printf("Noise Level: %d\n", noiseLevel);

  // Upload to ThingSpeak
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, airQuality);
  ThingSpeak.setField(4, noiseLevel);
  
  int status = ThingSpeak.writeFields(channelID, writeAPIKey);
  if (status == 200) {
    Serial.println("Data sent to ThingSpeak.");
  } else {
    Serial.printf("Error code %d\n", status);
  }

  delay(20000); // Wait 20 seconds between uploads
}
