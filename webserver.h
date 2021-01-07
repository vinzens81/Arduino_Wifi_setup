ESP8266WebServer server(80);

void setupApMode() {
  const char *ssid = "MyESP8266AP";
  const char *password = "testpassword";
  WiFi.softAP(ssid, password);             // Start the access point
  Serial.println("Access Point \"" + String(ssid) + "\" stared");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
}

void handleRoot() {
  server.send(200, "text/html", MAIN_page, sizeof(MAIN_page));
}

void handleForm() {
  String ssidWeb = server.arg("ssidInput");
  String passwordWeb = server.arg("passwordInput");

  Serial.println("ssid: " + ssidWeb);
  Serial.println("password: " + passwordWeb);
  if (!write_to_file(ssidWeb, WIFI_ssid_file)) {
    Serial.println("Something went wrong while writing SSID to file");
  }
  delay(1000);
  if (!write_to_file(passwordWeb, WIFI_password_file)) {
    Serial.println("Something went wrong while writing Passwordto file");
  }
  String s = "<a href='/'> Go Back </a>";
  server.send(200, "text/html", s); //Send web page
}
