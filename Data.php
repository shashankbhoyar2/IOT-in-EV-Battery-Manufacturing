<?php
/**
 * @file fetch_database_data.php
 * @brief PHP script to fetch data from a MySQL database and return it as JSON.
 */

// Database connection settings
$servername = "localhost"; /**< @brief Database server name. */
$username = "your_db_user"; /**< @brief Database username. */
$password = "your_db_password"; /**< @brief Database password. */
$dbname = "your_db_name"; /**< @brief Database name. */

// Create a connection to the database
$conn = new mysqli($servername, $username, $password, $dbname);

// Check the connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Query to retrieve data from your database table (replace with your table name)
$sql = "SELECT * FROM your_table_name";
$result = $conn->query($sql);

// Create an array to hold the data
$data = array();

// Fetch and store data in the array
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $data[] = $row;
    }
}

// Close the database connection
$conn->close();

// Send the data as JSON
header('Content-Type: application/json');
echo json_encode($data);
?>
