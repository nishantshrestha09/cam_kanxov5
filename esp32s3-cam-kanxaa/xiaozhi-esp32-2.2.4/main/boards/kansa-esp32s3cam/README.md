# Kansa ESP32-S3 Cam (OLED + WS2812 ring)

Based on `bread-compact-wifi-s3cam`, but with the TFT swapped out for a
monochrome OLED status display and a WS2812 LED ring, since this build has
no color screen.

## Wiring

Audio, camera and boot button are unchanged from `bread-compact-wifi-s3cam` --
see that board's `config.h` / this board's `config.h` for the pin list.

| Peripheral | Pins |
|---|---|
| OLED (SSD1306, I2C) | SDA -> GPIO21, SCL -> GPIO47, addr auto-probed (0x3C or 0x3D) |
| WS2812 LED ring (12 LEDs) | DIN -> GPIO38 |

GPIO21/38/47 are pins the base board wires to the TFT (RST/BL/DC); they're
free to reuse here since this build has no TFT populated.

## Build

```bash
idf.py set-target esp32s3
idf.py menuconfig
```

- `Xiaozhi Assistant -> Board Type -> Kansa ESP32S3 Cam (OLED + WS2812)`
- `Xiaozhi Assistant -> OLED Type -> SSD1306 128x64` (this board defaults to
  128x64, but confirm it matches your panel)

```bash
idf.py build
idf.py -p COM5 flash
```

## LED ring state colors

See `kansa_esp32s3cam.cc` (`KansaLed`) and `main/led/circular_strip.cc` for the
full mapping: idle = soft blue breathe, listening = green pulse, thinking =
amber chase, speaking = cyan pulse, camera capture = white flash, capture
success = green flash, error = red blink (x3).
