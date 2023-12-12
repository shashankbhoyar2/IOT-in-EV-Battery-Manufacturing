# IOT-in-EV-Battery-Manufacturing
As the production line is semi-automated some of the critical stations has to be monitored continuously to increase the efficiency of the line. This can be implemented using IoT in Industry 4.O application.
#About Project:
Create a user-friendly dashboard that measures the manufacturing time for a battery pack and displays the results in real-time. This project will enable users to monitor the duration of the process accurately and efficiently. As the production line is semi-automated some of the critical stations has to be monitored continuously to increase the efficiency of the line. This can be implemented using IoT in Industry 4.O application. The main intention of this project is to count the objects moving on a conveyer belt in industries and to monitor and count the number of objects moving from one end to the other end. 
![image](https://github.com/shashankbhoyar2/IOT-in-EV-Battery-Manufacturing/assets/140690552/0b8cc733-f466-4adb-895b-089a1fb301d5)

![image](https://github.com/shashankbhoyar2/IOT-in-EV-Battery-Manufacturing/assets/140690552/5f70824a-85bc-4fcd-b21e-fa581d741ded)

Steps to Execute:
1.	Upload the sender_code.ino to both Sender ESP32 boards.
2.	Upload the receiver_code.ino to the Receiver ESP32 board.
3.	Modify placeholders like your_wifi_ssid, your_wifi_password, receiver_esp32_ip, and paths according to your setup.
4.	Ensure that all ESP32 boards are connected to the same Wi-Fi network.
5.	Ensure that you have XAMPP installed and running on your computer to receive data. Configure the PHP script (data_receiver.php) to process the data as needed.
6.	Power up the ESP32 boards.
7.	The sender boards will send ultrasonic sensor data to the receiver board.
8.	The receiver board will process the received data and respond with a confirmation message.
Please adjust the code and configurations as needed for your specific requirements and network setup.
In this code:

•	The HTML file (index.html) includes placeholders for sensor data and a table to display database data. CSS styles are applied to format the content.
•	JavaScript functions are used to periodically fetch sensor data from the ESP8266 and database data from the PHP script.
•	The PHP script (fetch_database_data.php) connects to your MySQL database, retrieves data from a table, and sends it as JSON to the HTML page.
Please replace the placeholders with your actual server and database details. Additionally, customize the CSS to match your preferred design.
