const char MAIN_page[] PROGMEM = R"(
<!DOCTYPE html>
<html>
<body>
<h2>Circuits4you<h2>
<h3> HTML Form ESP8266</h3>
<form action="/action_page">
  Wifi SSID:<br>
  <input type="text" name="ssidInput" value="ssid">
  <br>
  Wifi Password:<br>
  <input type="text" name="passwordInput" value="password">
  <br><br>
  <input type="submit" value="Submit">
</form> 
</body>
</html>
)";
