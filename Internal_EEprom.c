/*
 * Internal_EEprom.c
 *
 * Created: 06/03/2022 03:38:04 م
 *  Author: ahmed essam
 */ 
#include "Internal_EEprom.h"

void eeprom_write(char addr , char data)
{
	while (EECR & (1<<EEPE));
	EEAR = addr;
	EEDR = data;
	EECR |= (1<<EEMPE);
	EECR |= (1<<EEPE);
}

char eeprom_read(char addr)
{
	while (EECR & (1<<EEPE));
	EEAR = addr;
	EECR |= (1<<EEMPE);
	EECR |= (1<<EERE);
	return EEDR;
}