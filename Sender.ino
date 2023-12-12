/**
 * @file master_sender.ino
 * @brief Arduino code for the master (sender) ESP32 to measure distance using an ultrasonic sensor
 *        and send the data to a receiver ESP32.
 */

#include <WiFi.h>

const char* ssid = "your_wifi_ssid"; /**< @brief WiFi SSID. */
const char* password = "your_wifi_password"; /**< @brief WiFi password. */
const char* receiverIP = "receiver_esp32_ip"; /**< @brief IP address of the receiver ESP32. */
const int receiverPort = 80; /**< @brief Port number on the receiver ESP32. */

#define trigPin 26 /**< @brief GPIO pin connected to the trig pin of the ultrasonic sensor. */
#define echoPin 27 /**< @brief GPIO pin connected to the echo pin of the ultrasonic sensor. */

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
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

/**
 * @brief Loop function to continuously measure distance and send data to the receiver ESP32.
 */
void loop() {
    long duration, distance;

    // Send a pulse to the ultrasonic sensor to trigger the measurement
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure the time taken for the sound wave to bounce back
    duration = pulseIn(echoPin, HIGH);

    // Calculate the distance in centimeters
    distance = duration / 58.2;

    // Send data to receiver ESP32
    if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client;
        if (client.connect(receiverIP, receiverPort)) {
            String postStr = String("distance=") + String(distance);
            client.println("POST /data_receiver.php HTTP/1.1");
            client.println("Host: " + String(receiverIP));
            client.println("Connection: close");
            client.println("Content-Type: application/x-www-form-urlencoded");
            client.println("Content-Length: " + String(postStr.length()));
            client.println();
            client.println(postStr);
            client.stop();
        }
    }

    // Add a delay before the next measurement and sending data
    delay(10000); // Send data every 10 seconds
}
