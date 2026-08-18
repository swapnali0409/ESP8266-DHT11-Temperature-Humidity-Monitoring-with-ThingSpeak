# ESP8266-DHT11-Temperature-Humidity-Monitoring-with-ThingSpeak
An IoT-based environmental monitoring project using ESP8266 and DHT11 to measure temperature and humidity. The sensor readings are displayed on the Serial Monitor and uploaded to ThingSpeak over Wi-Fi for real-time visualization using graphs and gauges.

## 📌 Project Overview

This project is a simple IoT-based environmental monitoring system using an **ESP8266 (NodeMCU)** and a **DHT11 temperature and humidity sensor**.

The ESP8266 reads the temperature and humidity values from the DHT11 sensor and sends the data to **ThingSpeak** over Wi-Fi. The sensor data can then be monitored remotely through graphs and gauges on the ThingSpeak dashboard.

This project helped me understand the basic working of **IoT communication, sensor interfacing, Wi-Fi connectivity, HTTP-based cloud communication, and real-time data visualization**.

---

## 🎯 Objective

The main objectives of this project are:

- Interface the DHT11 sensor with ESP8266.
- Read temperature and humidity values.
- Connect ESP8266 to a Wi-Fi network.
- Send sensor data to ThingSpeak.
- Monitor the data remotely using ThingSpeak.
- Visualize temperature and humidity using graphs and gauges.

---

## 🧰 Hardware Required

| Component | Quantity |
|---|---:|
| ESP8266 NodeMCU | 1 |
| DHT11 Temperature & Humidity Sensor | 1 |
| Jumper Wires | As required |
| Breadboard | 1 |
| USB Cable | 1 |

---

## 💻 Software / Tools Used

- Arduino IDE
- ESP8266 Board Package
- DHT Sensor Library
- ThingSpeak
- Serial Monitor
- Wi-Fi Network

---

## 🔌 Circuit Connections

### DHT11 → ESP8266

| DHT11 Pin | ESP8266 |
|---|---|
| VCC | 3.3V |
| DATA | GPIO pin used in the program |
| GND | GND |

> **Note:** The DATA pin can be connected to another suitable GPIO, but the pin number in the program must match the actual connection.

---

## 🧩 Block Diagram

```text
             ┌──────────────────┐
             │      DHT11       │
             │                  │
             │ Temperature      │
             │ Humidity         │
             └────────┬─────────┘
                      │
                      │ Sensor Data
                      ▼
             ┌──────────────────┐
             │     ESP8266      │
             │     NodeMCU      │
             │                  │
             │ Read Sensor Data │
             │ Process Data     │
             └────────┬─────────┘
                      │
                      │ Wi-Fi
                      ▼
             ┌──────────────────┐
             │     Internet     │
             └────────┬─────────┘
                      │
                      ▼
             ┌──────────────────┐
             │    ThingSpeak    │
             │      Cloud       │
             │                  │
             │ Temperature      │
             │ Humidity         │
             └────────┬─────────┘
                      │
                      ▼
             ┌──────────────────┐
             │  Graphs / Gauges │
             │ Remote Monitoring│
             └──────────────────┘

```

## ⚙️ Working Principle

1. The DHT11 sensor measures the surrounding temperature and humidity.

2. The ESP8266 reads the sensor values through its GPIO pin.

3. ESP8266 connects to the configured Wi-Fi network.

4. The measured temperature and humidity are processed by the program.

5. ESP8266 sends the values to the ThingSpeak cloud platform.

6. ThingSpeak stores the received data.

7. The data is displayed using graphs and gauges.

8. The user can monitor the environmental conditions remotely.

## 🔄 Program Flow
```

        Start
          │
          ▼
   Initialize Serial
          │
          ▼
   Initialize DHT11
          │
          ▼
   Connect to Wi-Fi
          │
          ▼
   Read Temperature
   and Humidity
          │
          ▼
   Reading Successful?
       /       \
     No         Yes
     │           │
     │           ▼
     │     Display Values
     │           │
     │           ▼
     │     Send Data to
     │       ThingSpeak
     │           │
     │           ▼
     │      Wait for delay
     │           │
     └───────────┘
          │
          ▼
       Repeat
```

## 🌐 ThingSpeak Configuration

For cloud monitoring, a ThingSpeak channel was created with two fields:

Field 1 → Temperature
Field 2 → Humidity

The ESP8266 sends the sensor values periodically to these fields.

The ThingSpeak dashboard can then be configured with:

Temperature graph

Humidity graph

Temperature gauge

Humidity gauge

## 📊 Example Output
Serial Monitor
Temperature: 29.60 °C    Humidity: 61.00 %

Temperature: 29.60 °C    Humidity: 61.00 %

Temperature: 29.70 °C    Humidity: 62.00 %

Temperature: 29.70 °C    Humidity: 63.00 %

Temperature: 29.80 °C    Humidity: 64.00 %

## 🧠 Concepts Learned

Through this project, I worked with:

ESP8266 NodeMCU

DHT11 sensor interfacing

GPIO communication

Temperature and humidity measurement

Wi-Fi connectivity

IoT cloud communication

ThingSpeak

Sensor data transmission

Real-time data visualization

Serial debugging

Basic IoT architecture

## 🛠️ Important Programming Concepts

The project uses:

setup() for initialization

loop() for continuous sensor monitoring

DHT sensor library for reading sensor values

Wi-Fi library for network connectivity

ThingSpeak library/API for cloud communication

Serial.print() for debugging and monitoring

## ⚠️ Important Considerations

Make sure the DHT11 DATA pin matches the GPIO configured in the code.

Use the correct Wi-Fi SSID and password.

Use the correct ThingSpeak Channel ID.

Use the correct ThingSpeak Write API Key.'

Do not expose the Wi-Fi password or API key in a public GitHub repository.

DHT11 has relatively slow sampling compared with many other sensors, so readings should not be requested too frequently.

The ESP8266 should have a stable 3.3V supply.

## 📁 Project Structure
```
ESP8266-DHT11-ThingSpeak/
│
├── ESP8266_DHT11.ino
├── README.md
└── images/
    ├── circuit.jpg
    └── thingspeak_dashboard.jpg

```
## 📷 Project Result

The ESP8266 successfully reads temperature and humidity from the DHT11 sensor and uploads the readings to ThingSpeak through Wi-Fi.

The ThingSpeak dashboard displays the collected data using graphs and gauges, demonstrating a basic IoT remote monitoring system.

## 💡 Real-World Applications

This type of system can be used for:

Smart Home Monitoring

Weather Monitoring

Server Room Monitoring

Greenhouse Monitoring

Industrial Environment Monitoring

IoT-based Environmental Monitoring

## 👩‍💻 Author

Swapnali Rathod

Electronics & Telecommunication Engineering
Pune Institute of Computer Technology (PICT), Pune

Skills Practiced

Embedded C • ESP8266 • IoT • Sensors • Wi-Fi • ThingSpeak • Arduino IDE

## ⭐ Conclusion

This project provided practical experience in connecting a physical sensor to an ESP8266 and transferring the collected data to a cloud platform.

It was a useful introduction to the complete IoT data flow:

Sensor → Microcontroller → Wi-Fi → Cloud → Data Visualization

The project also gave me hands-on experience with sensor interfacing, wireless communication, cloud-based monitoring, and debugging using the Serial Monitor.


       
