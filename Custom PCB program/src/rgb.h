#ifndef RGB_H_
#define RGB_H_

void setPixel(RGB_t pixel, uint8_t row, RGB_t *array);
void setPixelColor(uint8_t r, uint8_t g, uint8_t b, uint8_t row, RGB_t *array);
void setColor(uint8_t r, uint8_t g, uint8_t b, RGB_t *array);
void RGB_init(void);
void setRandomColor(RGB_t *array);
void rotate(RGB_t *array);
void onePulse(void);
void zeroPulse(void);
void ws_send_byte(unsigned char K);
void c_WS2812_Write(unsigned char R, unsigned char G, unsigned char B);
void colorRing(unsigned char R, unsigned char G, unsigned char B);
void breathingEffect();
void Color_Effect();

#endif /* RGB_H_ */