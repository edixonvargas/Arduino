// /***************************************************
//   This is a library example for the MLX90614 Temp Sensor

//   Designed specifically to work with the MLX90614 sensors in the
//   adafruit shop
//   ----> https://www.adafruit.com/products/1747 3V version
//   ----> https://www.adafruit.com/products/1748 5V version

//   These sensors use I2C to communicate, 2 pins are required to
//   interface
//   Adafruit invests time and resources providing this open source code,
//   please support Adafruit and open-source hardware by purchasing
//   products from Adafruit!

//   Written by Limor Fried/Ladyada for Adafruit Industries.
//   BSD license, all text above must be included in any redistribution
//  ****************************************************/

// #include <Adafruit_MLX90614.h>

// Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// void setup() {
//   Serial.begin(9600);
//   while (!Serial);

//   Serial.println("Adafruit MLX90614 test");
// mlx.begin();
//   if (!mlx.begin()) {
//     Serial.println("Error connecting to MLX sensor. Check wiring.");
//     // while (1);
//   };

//   Serial.print("Emissivity = "); Serial.println(mlx.readEmissivity());
//   Serial.println("================================================");
// }

// void loop() {
//   Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
//   Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
//   Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
//   Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

//   Serial.println();
//   delay(500);
// }





#include <Wire.h>
#include <Adafruit_MLX90614.h>


Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  
    // pinMode(D2, INPUT_PULLUP);
    // pinMode(D1, OUTPUT);
  
  pinMode(MISO, INPUT_PULLUP);
  pinMode(SCK, INPUT_PULLUP);

    // Wire.begin(D2, D1);
  Wire.begin(MISO, SCK);
  // Wire.setClock(10000L);
  // pinMode(A4, OUTPUT);   // set pin to input mode
  // pinMode(A5, OUTPUT);   // set pin to input mode

  // pinMode(PIN_SPI_SCK, OUTPUT);   // set pin to input mode
  // pinMode(PIN_SPI_MOSI, OUTPUT);   // set pin to input mode
  
  // pinMode(A4, INPUT_PULLUP);   // set pin to input mode
  // pinMode(A5, INPUT_PULLUP);   // set pin to input mode

  Serial.begin(115200);
  Serial.println("MLX90614 begin");
  if(!mlx.begin(0)) {
    Serial.println("Error connecting MLX90614");
    while(1);
  }
  Serial.println("Connected successfully MLX90614");
}

void loop() {
  Serial.println("Temperature from MLX90614:");
  Serial.print("Emisivity:    ");
  Serial.print(mlx.readEmissivity());
  Serial.println();
  Serial.print("Ambient:      ");
  Serial.print(mlx.readAmbientTempC());
  Serial.println(" C");
  Serial.print("Contactless: ");
  Serial.print(mlx.readObjectTempC());
  Serial.println(" C");
  Serial.println();
  delay(1000);
}