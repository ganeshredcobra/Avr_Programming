CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRDUDE = avrdude
REMOVE = rm -f

MCU =atmega32

TARGET = main
SRC = $(TARGET).c

AVRDUDE_PROGRAMMER = usbasp
AVRDUDE_PORT = /dev/parport0 
AVRDUDE_WRITE_FLASH = -U flash:w:$(TARGET).hex


elf:
	$(CC) -mmcu=$(MCU) -Os -o $(TARGET).elf $(SRC)
hex:
	$(OBJCOPY) -j .text -j .data -O ihex  $(TARGET).elf $(TARGET).hex
flash:
	$(AVRDUDE) -p m32 -c $(AVRDUDE_PROGRAMMER) $(AVRDUDE_WRITE_FLASH)
clean:
	$(REMOVE) $(TARGET).hex $(TARGET).elf $(TARGET).c~


