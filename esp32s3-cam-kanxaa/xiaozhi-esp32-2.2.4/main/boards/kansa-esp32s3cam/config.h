#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>

#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// 如果使用 Duplex I2S 模式，请注释下面一行
#define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX

#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_1
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_2
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_42
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_39
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_40
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_41

#else

#define AUDIO_I2S_GPIO_WS GPIO_NUM_4
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_5
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_6
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_7

#endif

#define BOOT_BUTTON_GPIO        GPIO_NUM_0
#define TOUCH_BUTTON_GPIO       GPIO_NUM_NC
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_NC
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_NC

// Camera Config (OV2640 on the ESP32-S3-CAM module)
#define CAMERA_PIN_D0 GPIO_NUM_11
#define CAMERA_PIN_D1 GPIO_NUM_9
#define CAMERA_PIN_D2 GPIO_NUM_8
#define CAMERA_PIN_D3 GPIO_NUM_10
#define CAMERA_PIN_D4 GPIO_NUM_12
#define CAMERA_PIN_D5 GPIO_NUM_18
#define CAMERA_PIN_D6 GPIO_NUM_17
#define CAMERA_PIN_D7 GPIO_NUM_16
#define CAMERA_PIN_XCLK GPIO_NUM_15
#define CAMERA_PIN_PCLK GPIO_NUM_13
#define CAMERA_PIN_VSYNC GPIO_NUM_6
#define CAMERA_PIN_HREF GPIO_NUM_7
#define CAMERA_PIN_SIOC GPIO_NUM_5
#define CAMERA_PIN_SIOD GPIO_NUM_4
#define CAMERA_PIN_PWDN GPIO_NUM_NC
#define CAMERA_PIN_RESET GPIO_NUM_NC
#define XCLK_FREQ_HZ 20000000

// This board has no TFT. In its place: a small monochrome OLED status
// display (I2C) and a WS2812 RGB LED ring for state feedback.
//
// The base board (bread-compact-wifi-s3cam) wires a TFT on GPIO19/20/21/38/45/47.
// None of those pins are used here since there's no TFT populated -- OLED and
// LED ring use two of them instead (confirmed wiring, not a guess).

// OLED display (SSD1306, I2C)
#define DISPLAY_SDA_PIN GPIO_NUM_21
#define DISPLAY_SCL_PIN GPIO_NUM_47
#define DISPLAY_WIDTH   128

#if CONFIG_OLED_SSD1306_128X32
#define DISPLAY_HEIGHT  32
#elif CONFIG_OLED_SSD1306_128X64
#define DISPLAY_HEIGHT  64
#elif CONFIG_OLED_SH1106_128X64
#define DISPLAY_HEIGHT  64
#define SH1106
#else
#error "OLED display type is not selected"
#endif

#define DISPLAY_MIRROR_X false
#define DISPLAY_MIRROR_Y false

// WS2812 RGB LED ring (status indicator, replaces the single BUILTIN_LED_GPIO)
#define LED_STRIP_GPIO  GPIO_NUM_38
#define LED_STRIP_COUNT 12

#endif // _BOARD_CONFIG_H_
