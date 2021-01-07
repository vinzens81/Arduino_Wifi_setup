#include <FS.h>
struct file_content {
  char* file;
  boolean success;
};

void setupSPI() {
  if (SPIFFS.begin()) {
    Serial.println("SPIFFS Initialize....ok");
    delay(500);
  }
  else {
    Serial.println("SPIFFS Initialization...failed");
    delay(500);
  }
}

struct file_content read_from_file(const char* file) {
  setupSPI();
  char content [512] = {'\0'};
  boolean success = false;
  if (SPIFFS.exists(file)) {
    File f = SPIFFS.open(file, "r");
    if (!f) {
      Serial.println("file open failed");
    } else {
      uint16_t i = 0;
      while (f.available()) {
        content [i] = f.read();
        i++;
      }
      content [i] = '\0';
      success = true;
      Serial.print("Read file: "); Serial.println(file);
      Serial.print("Read file content: "); Serial.println(content);
    }
    f.close();

  } else {
    Serial.println("File oes not exist: " + String(file));
  }
  SPIFFS.end();
  struct file_content fileInstance;
  fileInstance.success = success;
  fileInstance.file = content;
  return fileInstance;
}

boolean write_to_file(String content, const char* file) {
  boolean success = false;
  setupSPI();
  File f = SPIFFS.open(file, "w");
  if (!f) {
    Serial.println("file open failed");
  } else {
    f.print(content);
    f.close();
    success = true;
    Serial.println("Writing Content to file: " + content + " > " + String(file));
  }
  SPIFFS.end();
  return success;
}
