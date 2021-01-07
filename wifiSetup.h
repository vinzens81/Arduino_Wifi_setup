
void setupWifi() {
  struct file_content file_ssid = read_from_file(WIFI_ssid_file);
  if (file_ssid.success) {
    Serial.println("SSID Found of filesystem.");
    WIFISSID = String(file_ssid.file);
    struct file_content file_pass = read_from_file(WIFI_password_file);
    if (file_pass.success) {
      Serial.println("Wifi Pass found try to connect");
      WIFIENABLED = true;
      WIFIPASS = String(file_pass.file);
      Serial.print("We got SSID and Pass ");Serial.print(WIFISSID);Serial.print(" ");Serial.print(WIFIPASS);
    } else {
      Serial.println("No Pass found for SSID " + WIFISSID + " Continuing without Wifi");
      WIFIENABLED = false;
    }
  } else {
    Serial.println("no SSID found ;-(");
    WIFIENABLED = false;
  }
  if (!WIFIENABLED) {
    setupApMode();
    server.on("/", handleRoot);
    server.begin();
  }
}
