# 🌱 EcoPing - Environmental Monitoring Station

EcoPing is an IoT-powered environmental monitoring device that measures **temperature**, **humidity**, **air quality**, and **noise levels**, and uploads data to the cloud in real-time. The data is visualized through a simple and clean dashboard using ThingSpeak.

![EcoPing Logo](https://github.com/sosyalrobot/EcoPing/logo.png)

---

## 🔧 Features

- 🌡️ Temperature & Humidity via DHT22  
- 🌬️ Air Quality via MQ-135 Sensor  
- 🔊 Noise Level via Analog Sound Sensor  
- 📡 WiFi-enabled ESP32 for data transfer  
- ☁️ Cloud integration with ThingSpeak  
- 📊 Real-time dashboard visualization  

---

## 📦 Components

| Component        | Description                      |
|------------------|----------------------------------|
| ESP32            | Main microcontroller              |
| DHT22            | Temp & humidity sensor            |
| MQ-135           | Air quality sensor                |
| Analog Sound Sensor | Noise level input           |
| Breadboard + Wires | For wiring the setup         |

---

## 🚀 Getting Started

### 1. Clone the Repo

```bash
git clone https://github.com/sosyalrobot/EcoPing.git
cd EcoPing
```

### 2. Setup Arduino IDE

- Install ESP32 board support
- Install required libraries:
  - `DHT sensor library`
  - `Adafruit Unified Sensor`
  - `WiFi.h`
  - `ThingSpeak.h`

### 3. Configure `secrets.h`

Create a `secrets.h` file:

```cpp
#define SECRET_SSID "YOUR_WIFI_SSID"
#define SECRET_PASS "YOUR_WIFI_PASSWORD"
#define SECRET_CH_ID YOUR_THINGSPEAK_CHANNEL_ID
#define SECRET_WRITE_APIKEY "YOUR_API_KEY"
```

### 4. Upload Code

Use Arduino IDE to flash the `ecoping.ino` file onto your ESP32.

---

## 📊 Dashboard

View your live data on [ThingSpeak](https://thingspeak.com/) by linking your channel ID.

| Field | Sensor         | Description         |
|-------|----------------|---------------------|
| 1     | DHT22          | Temperature (°C)    |
| 2     | DHT22          | Humidity (%)        |
| 3     | MQ-135         | Air Quality (raw)   |
| 4     | Sound Sensor   | Noise Level (raw)   |

---

## 📁 Folder Structure

```
EcoPing/
├── ecoping.ino
├── secrets.h           # Your private WiFi and API keys
├── logo.png
├── README.md
```

---

## 🧪 Future Ideas

- Add CO₂ or PM2.5 sensors
- Solar-powered outdoor version
- Native web dashboard (Node.js / React)
- Mobile app integration

---

## 🤝 License

MIT License. Use it, remix it, and share it! 🌍  
Created with 💚 by [Sosyal Robot](https://github.com/sosyalrobot)
