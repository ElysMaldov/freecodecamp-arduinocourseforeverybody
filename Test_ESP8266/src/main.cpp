// #include <ESP8266WiFi.h>

// // Replace with your network credentials
// const char *ssid = "";
// const char *password = "";

// void setup()
// {
//   // Initialize serial communication at 115200 baud
//   Serial.begin(115200);
//   delay(10);

//   Serial.println();
//   Serial.print("Connecting to ");
//   Serial.println(ssid);

//   // Explicitly set the ESP8266 to be a Wi-Fi station
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);

//   // Wait for connection
//   while (WiFi.status() != WL_CONNECTED)
//   {
//     delay(500);
//     Serial.print(".");
//   }

//   // Connection successful
//   Serial.println("");
//   Serial.println("Wi-Fi connected successfully!");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());
// }

// void loop()
// {
//   // Check connection status periodically in the loop
//   if (WiFi.status() == WL_CONNECTED)
//   {
//     Serial.println("Still connected...");
//   }
//   else
//   {
//     Serial.println("Connection lost!");
//   }
//   delay(5000); // Wait 5 seconds before checking again
// }

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

// Replace with your network credentials
const char *ssid = "";
const char *password = "";

// URL of the mock API (HTTP is used here for simplicity)
const char *mock_api_url = "http://jsonplaceholder.typicode.com/todos/1";

void setup()
{
  // Initialize serial communication at 115200 baud
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Set the ESP8266 to Station mode and begin connection
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Wait for the connection to establish
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Wi-Fi connected successfully!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  // Check if the ESP8266 is still connected to the Wi-Fi network
  if (WiFi.status() == WL_CONNECTED)
  {
    WiFiClient client;
    HTTPClient http;

    Serial.println("\nStarting API request...");

    // Initialize the HTTP connection with the mock API URL
    if (http.begin(client, mock_api_url))
    {

      // Send the actual GET request
      int httpCode = http.GET();

      // httpCode will be negative if the connection failed
      if (httpCode > 0)
      {
        Serial.print("HTTP Response code: ");
        Serial.println(httpCode);

        // If the server responded with 200 OK, fetch and print the payload
        if (httpCode == HTTP_CODE_OK)
        {
          String payload = http.getString();
          Serial.println("--- Response Payload From Mock API ---");
          Serial.println(payload);
          Serial.println("---------------------------------------");
        }
      }
      else
      {
        Serial.print("Error on HTTP request: ");
        Serial.println(http.errorToString(httpCode).c_str());
      }

      // Close the connection to free up resources
      http.end();
    }
    else
    {
      Serial.println("Unable to connect to the mock API server.");
    }
  }
  else
  {
    Serial.println("Wi-Fi Disconnected. Reconnecting...");
  }

  // Wait 10 seconds before making the next API call
  delay(10000);
}