
# Arduino SD Card Logger

This project demonstrates how to use an **Arduino** with a **micro SD card module** to write data to and read data from an SD card. It is ideal for projects involving data logging or file storage.

## Components Required

1. **Arduino Board** (e.g., Arduino Uno, Nano, Mini, etc.).
2. **micro SD card module**.
3. **micro SD card** (formatted as FAT32).
4. **Jumper Wires**.

## Circuit Diagram

Below is the connection between the Arduino and the SD card module:

| SD Module Pin | Arduino Pin |
|---------------|-------------|
| GND           | GND         |
| VCC           | 5V          |
| MISO          | D12         |
| MOSI          | D11         |
| SCK           | D13         |
| CS            | D10         |

### Notes:
- Ensure the SD card is formatted as FAT16 or FAT32.
- Use a Class 10 or higher SD card for better performance.
- The CS (Chip Select) pin is configured to pin `10` in this example.

## Code

The code initializes the SD card, writes a string to a file, and reads it back. Copy the following code into your Arduino IDE:

```cpp
#include <SPI.h>
#include <SD.h>

const int chipSelect = 10; // CS pin for SD module

void setup() {
  Serial.begin(9600);

  // Initialize the SD card
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    return;
  }
  Serial.println("SD card initialized successfully.");

  // Create and write to a file
  writeFile("data.txt", "Hello, SD card!");
  
  // Read data from the file
  readFile("data.txt");
}

void loop() {
  // Main code, if needed, can be added here
}

// Function to write data to a file
void writeFile(const char* filename, const char* data) {
  File file = SD.open(filename, FILE_WRITE);

  if (file) {
    file.println(data); // Write string to file
    Serial.println("Data written: " + String(data));
    file.close(); // Close the file
  } else {
    Serial.println("Failed to write to file!");
  }
}

// Function to read data from a file
void readFile(const char* filename) {
  File file = SD.open(filename);

  if (file) {
    Serial.println("Reading data from file:");
    while (file.available()) {
      Serial.write(file.read()); // Read and print data
    }
    Serial.println();
    file.close(); // Close the file
  } else {
    Serial.println("Failed to read the file!");
  }
}
```

## How It Works

1. **Initialization**:
   - The SD card is initialized using the `SD.begin()` function. If the initialization fails, an error message is displayed.

2. **Writing Data**:
   - The `writeFile()` function opens (or creates) a file `data.txt` and writes a string to it.
   - The file is then closed to save the data.

3. **Reading Data**:
   - The `readFile()` function opens the file `data.txt` and reads its contents.
   - The data is displayed in the serial monitor.

## Applications

- Data logging (e.g., temperature, sensor readings).
- File storage for projects requiring persistent data.
- Simple data transfer between Arduino and a computer.

## License

This project is open-source and available under the MIT License.
