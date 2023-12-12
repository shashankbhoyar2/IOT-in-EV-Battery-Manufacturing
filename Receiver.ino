/**
 * @file slave_receiver.ino
 * @brief Arduino code for the slave (receiver) ESP32 to receive distance data from a master ESP32.
 */

#include <WiFi.h>
#include <WiFiServer.h>

const char* ssid = "your_wifi_ssid"; /**< @brief WiFi SSID. */
const char* password = "your_wifi_password"; /**< @brief WiFi password. */
const int localPort = 80; /**< @brief Port number for the local server. */

WiFiServer server(localPort); /**< @brief WiFi server instance. */

/**
 * @brief Setup function to initialize the ESP32.
 */
void setup() {
    Serial.begin(9600);
    WiFi.begin(ssid, password);

    // Wait for WiFi connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }

    Serial.println("Connected to WiFi");
    server.begin();
}

/**
 * @brief Loop function to continuously listen for incoming data from the master ESP32.
 */
void loop() {
    WiFiClient client = server.available();
    if (client) {
        while (client.connected()) {
            if (client.available()) {
                String request = client.readStringUntil('\r');
                client.flush();
                
                // Check if the received data contains "distance="
                if (request.indexOf("distance=") != -1) {
                    String distanceStr = request.substring(request.indexOf('=') + 1);
                    int distance = distanceStr.toInt();
                    Serial.print("Received distance: ");
                    Serial.println(distance);
                    // Perform any processing with the received distance data
                }

                // Send a response to the master ESP32
                client.println("HTTP/1.1 200 OK");
                client.println("Content-Type: text/html");
                client.println();
                client.println("Data received successfully.");
                break;
            }
        }
        client.stop();
    }
}
