#ifndef LED_H
#define LED_H

typedef enum {
 
    Red, Green, Blue
} Channel;

void setBrightness(char brightness, Channel channel);
void switchChannel(Channel channel, char state);

#endif
