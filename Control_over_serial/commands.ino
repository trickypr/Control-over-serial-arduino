void callCommand() {
  // Debug and constants
  if (command == "echo") {
    Serial.println(args);
  } else if (command == "help") {
    help();
  } else if (command == "verion" || command == "v") {
    Serial.println(version);
  } else if (command == "reset") {
    setup();
  }

  // Digital commands
  else if (command == "pinMode") {
    pinMode(gpio, value);
  } else if (command == "digitalRead") {
    Serial.println(value +' ' + digitalRead(gpio));
  } else if (command == "digitalWrite") {
    digitalWrite(gpio, value);
  }

  // Analog commands
  else if (command == "analogRead") {
    Serial.println(value + ' ' + analogRead(gpio));
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
    Serial.println(gpio + ' ' + micros());
  } else if (command == "millis") {
    Serial.println(gpio + ' ' + millis());
  }

  // Unknown commands
  else {
    Serial.println("Unrecognized command,\ntype \"help\" for command list");
  }
}
