void help() {
  Serial.println("List of commands:\n"
  "v || version: returns the version of the firmware\n"
  "echo: Prints what comes after it into the terminal\n\n"
  ""
  "DIGITAL I/O\n"
  "pinMode <pin> <mode>: Used to set the pin mode of a pin on an Arduino. 0: INPUT, 1: OUTPUT, 2: INPUT_PULLUP\n"
  "digitalRead <pin>: Reads the state of a particular pin. LOW: 0, HIGH: 1\n"
  "digitalWrite <pin> <value>: Sets a pin to a digital value. LOW: 0, HIGH: 1\n\n"
  ""
  "Analog I/O\n"
  "analogRead <pin>: Returns the analog value of that pin in the same manener as the analogRead() function\n"
  "analogWrite <pin> <value>: Writes an analog value to the specified pin in the same manner as the analogWrite() function\n\n"
  ""
  "Time functions\n"
  "Note: Time functions will prevent any command from executing, however it will execute all commands sent after it once it has done the time\n"
  "sleep <seconds>: Freezes all operations for a certin number of seconds\n"
  "delay <ms>: Wrapper for the delay() function\n"
  "delayMicroseconds <us>: Wrapper for the delayMicroseconds() function\n"
  "micros: Wrapper for the micros() function\n"
  "millis: Wrapper for the millis() function\n"
  );
}
