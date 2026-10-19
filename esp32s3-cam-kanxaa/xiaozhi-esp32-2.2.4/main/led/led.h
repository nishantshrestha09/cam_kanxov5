#ifndef _LED_H_
#define _LED_H_

class Led {
public:
    virtual ~Led() = default;
    // Set the led state based on the device state
    virtual void OnStateChanged() = 0;

    // Optional one-shot cues. Default to no-ops so existing Led
    // implementations don't need to know about them.
    virtual void FlashCapture() {}
    virtual void FlashSuccess() {}
    virtual void FlashError() {}
};


class NoLed : public Led {
public:
    virtual void OnStateChanged() override {}
};

#endif // _LED_H_
