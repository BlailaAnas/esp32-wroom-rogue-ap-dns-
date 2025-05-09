# 📡 ESP32 WROOM Rogue Access Point with DNS Redirection (Ethical Testing)

## 🔒 Disclaimer

> This project is intended for **educational and ethical testing purposes only**. Use only on networks you own or have permission to test.

---

## 🧠 What is This Project?

This is a demonstration of a **Rogue Access Point** using an ESP32 WROOM board. It creates a fake Wi-Fi hotspot and **redirects all DNS requests** to a custom page (like a fake login portal), showing how attackers can trick users in unsecured networks.

It’s a lightweight, low-cost educational tool to understand wireless attacks and improve security awareness.

---

## ⚙️ Requirements

- ✅ ESP32 WROOM development board
- ✅ Arduino IDE or PlatformIO
- ✅ Libraries:
  - `WiFi.h`
  - `DNSServer.h`
  - `ESPAsyncWebServer.h`

---

## 💡 Features

- Creates a **fake Wi-Fi access point**
- Redirects all DNS requests to a web page (like a login portal)
- Serves HTML files from ESP32
- Can simulate phishing pages for educational awareness
- Fully offline – no internet needed

---

## 📦 How to Set It Up

1. Open the `.ino` file in Arduino IDE
2. Install required libraries
3. Flash to ESP32 WROOM
4. Connect to the fake Wi-Fi network and observe redirection


## ✅ Use Cases (Ethical Only)

- Teaching Wi-Fi security
- Simulating Evil Twin attacks in labs
- Security awareness training
- Captive portal phishing tests


## 🧠 Learn More

- [ESP32 WiFi Library](https://github.com/espressif/arduino-esp32)
- [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)
- [DNS Spoofing](https://en.wikipedia.org/wiki/DNS_spoofing)

## 📦Bored manager library : https://dl.espressif.com/dl/package_esp32_index.json

## 🛡️ Warning

This is a security research tool. Always get consent before running it in shared environments.

---

## 📄 License

MIT License
