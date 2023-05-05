#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "array_helpers.h"


int min_temp (WeatherTable a);

void highest_temp_year (WeatherTable a, int output[YEARS]);

unsigned int monthly_rainfall (WeatherTable a, int year, month_t month);

void most_rain_year (WeatherTable a, month_t output[YEARS]);

#endif