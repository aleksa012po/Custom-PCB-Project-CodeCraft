#ifndef PWM_H_
#define PWM_H_

void pwmSetup();
void pwmLEDControl(int increment);
void pwmOff(void);

extern volatile int dutyCycle;

#endif /* PWM_H_ */