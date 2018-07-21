CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRDUDE = avrdude
REMOVE = rm -f

MCU =atmega32

TARGET = blink_timer
SRC = $(TARGET).c

AVRDUDE_PROGRAMMER = dapa
AVRDUDE_PORT = /dev/parport0 
AVRDUDE_WRITE_FLASH = -U flash:w:$(TARGET).hex

elf:
	$(CC) -mmcu=$(MCU) -Os -o $(TARGET).elf $(SRC)
hex:
	$(OBJCOPY) -j .text -j .data -O ihex  $(TARGET).elf $(TARGET).hex
flash8:
	$(AVRDUDE) -p m8 -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER) $(AVRDUDE_WRITE_FLASH)
clean:
	$(REMOVE) $(TARGET).hex $(TARGET).elf $(TARGET).c~

flash:
	avrdude -B10 -c usbasp -patmega32 -U flash:w:$(TARGET).hex
