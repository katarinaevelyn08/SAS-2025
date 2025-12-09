#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 21, 22);

// Pin tombol
#define TOMBOL_TAMBAH 4 // tombol hijau
#define TOMBOL_KURANG 2 // tombol merah

int hitung = 0;

void setup() {
lcd.init();
lcd.backlight();

// Tombol dengan internal pull-up
pinMode(TOMBOL_TAMBAH, INPUT_PULLUP);
pinMode(TOMBOL_KURANG, INPUT_PULLUP);

// Tampilkan awal
lcd.setCursor(0, 0);
lcd.print("SMAK Stanislaus");

lcd.setCursor(0, 1);
lcd.print("Hitung : 0");
}

void loop() {
if (digitalRead(TOMBOL_TAMBAH) == LOW) {
hitung++;
updateLCD();
delay(250); // debounce
}

if (digitalRead(TOMBOL_KURANG) == LOW) {
hitung--;
updateLCD();
delay(250); // debounce
}
}

void updateLCD() {
lcd.setCursor(0, 1);
lcd.print("Hitung : ");
lcd.print(hitung);
lcd.print(" "); // bersihkan sisa angka
}