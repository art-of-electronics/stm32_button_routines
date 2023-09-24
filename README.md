# stm32_button_routines
Routines for handling buttons done the right way :)

If you ever struggled with handling buttons in your MCU project - struggle no more. Here is a good example of button routines for STM32 microcontrollers coded with HAL in CubeMX IDE.

No interrupt nor lame 20ms delay "debounce". 

## The code includes `non-blocking` routines for following button events:
* pressing button
* pressing and releasing button

### Use as many buttons as you wish, as long as you have enough GPIO_Inputs in your MCU!
## Schematic for connecting button (and LED)
<p align="center"><img src="https://user-images.githubusercontent.com/121867860/227934679-b166bb86-f8ef-4715-ab95-7365bdc09d71.PNG" width=50% height=50%></p>

If you're short on space on PCB, you can use internall pull-up for button and ommit external resistors.

### To do:
- [ ] long / short press detection
- [ ] multiple pressing detection
