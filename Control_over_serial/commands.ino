#define version "1.0.0"
#define updateURL "https://raw.githubusercontent.com/trickypr/Control-over-serial-arduino/master/versions.json"
#define helpURL "https://github.com/trickypr/Control-over-serial-arduino/wiki"

void callCommand() {
  // Debug and constants
  if (command == "echo") {
    Serial.println(args);
  } else if (command == "help") {
    const String helpString = "Help is available at: ";
    helpString += helpURL;
    
    Serial.println(helpString);
  } else if (command == "version" || command == "v") {
    const String versionString = version;
    versionString += "\nOriginally by trickypr and the community under GNU AGPLv3";
    versionString += "\nUpdate URL: ";
    versionString += updateURL;
    
    Serial.println(versionString);
  } else if (command == "reset") {
    setup();
  }

  // Digital commands
  else if (command == "pinMode") {
    pinMode(gpio, value);
  } else if (command == "digitalRead") {
    Serial.println(digitalRead(gpio));
  } else if (command == "digitalWrite") {
    digitalWrite(gpio, value);
  }

  // Analog commands
  else if (command == "analogRead") {
    Serial.println(analogRead(gpio));
  } else if (command == "analogWrite") {
    analogWrite(gpio, value);
  }

  // Time functions
  else if (command == "delay") {
    delay(gpio);
  } else if (command == "sleep") {
    delay(gpio * 1000);
  } else if (command == "delayMicroseconds") {
    delayMicroseconds(gpio);
  } else if (command == "micros") {
    Serial.println(micros());
  } else if (command == "millis") {
    Serial.println(millis());
  }

  // Unknown commands
  else {
    Serial.println("Unrecognized command, type \"help\" for command list");
  }

  Serial.print('d');
}
