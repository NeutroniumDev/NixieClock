# NixieClock
A clock consisting of 6 nixie tubes, controlled by 3 high voltage shift registers. It differs from most other nixie clocks in that every segment of every nixie tube can be turned on, as opposed to one number per tube. This enables more complex animations. The 3 high voltage shift registers also, theoretically (not implemented) support controlling more than 6 nixie tubes because of leftover pins. The clock uses an ESP32-C3 to enable synchronizing the time with NTP, and it also acts as the microcontroller. Finally, the clock technically has an RTC chip, although in retrospect it's sorta unnecessary (and not implemented in code lmao). 
