bool serialOn = false;

String command = "";
String args = "";
int gpio = -1;
int value = 0;

char inData[100]; // Allocate some space for the string
char inChar = -1; // Where to store the character read
byte index = 0; // Index into array; where to store the character
bool clearToRead = true;

void setup()
{
  if (!serialOn) {
    Serial.begin(9600);
    serialOn = true;
  }
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++)
  {
    if (data.charAt(i) == separator || i == maxIndex)
    {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

String getAfter(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++)
  {
    if (data.charAt(i) == separator || i == maxIndex)
    {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0]) : "";
}

void loop()
{
  while (Serial.available() > 0 && clearToRead)
  {
    if (index < 99)
    {
      inChar = Serial.read(); // Read a character
      if (inChar == '\n' || inChar == ';') // end of string by separator
      {
        inData[index] = '\0'; // Null terminate the string
        clearToRead = false;  // do not allow reading again
        index = 0;
      }
      else
      {
        inData[index] = inChar; // Store it
        index++; // Increment where to write next
      }
    }
    else  // string is long, overflow the array
    {
      inData[index] = '\0';
      clearToRead = true;  // do not allow reading again, if we set that to 1 overflow string gonna be ignored
      index = 0;
      //Serial.flush();
      Serial.println("String oversized!");
    }
  }

  if (!clearToRead)
  {
    clearToRead = true;
    command = getValue(inData, ' ', 0);
    args = getAfter(inData, ' ', 1);
    gpio = getValue(inData, ' ', 1).toInt();
    value = getValue(inData, ' ', 2).toInt();

    callCommand();
  }
}
