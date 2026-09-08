#ifndef __COMMON_H
#define __COMMON_H

#include "stdint.h"

typedef struct {
	uint16_t year;
	uint8_t month;
	uint8_t day;
} DATE_t;

typedef struct {
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
} TIME_t;

typedef struct {
	uint16_t humidity;
	uint16_t pressure;
	float temp;
} WEATHER_DATA_t;

typedef struct {
	WEATHER_DATA_t weather_data;
	DATE_t date;
	TIME_t time;
} SENSORS_DATA_t;

#endif /* __COMMON_H */
