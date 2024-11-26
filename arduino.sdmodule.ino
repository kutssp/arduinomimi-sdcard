#include <SPI.h>
#include <SD.h>

const int chipSelect = 10; // CS pin for SD module

void setup() {
  Serial.begin(9600);

  // Инициализация SD-карты
  if (!SD.begin(chipSelect)) {
    Serial.println("Ошибка инициализации SD-карты!");
    return;
  }
  Serial.println("SD-карта успешно инициализирована.");

  // Создание и запись в файл
  writeFile("data.txt", "Hello, SD card!");
  
  // Чтение из файла
  readFile("data.txt");
}

void loop() {
  // Основной код, если требуется, можно добавить здесь
}

// Функция записи в файл
void writeFile(const char* filename, const char* data) {
  File file = SD.open(filename, FILE_WRITE);

  if (file) {
    file.println(data); // Записываем строку в файл
    Serial.println("Данные записаны: " + String(data));
    file.close(); // Закрываем файл
  } else {
    Serial.println("Ошибка записи в файл!");
  }
}

// Функция чтения из файла
void readFile(const char* filename) {
  File file = SD.open(filename);

  if (file) {
    Serial.println("Чтение данных из файла:");
    while (file.available()) {
      Serial.write(file.read()); // Чтение и вывод данных
    }
    Serial.println();
    file.close(); // Закрываем файл
  } else {
    Serial.println("Ошибка чтения файла!");
  }
}
