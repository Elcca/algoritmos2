#include <limits.h>

#include "weather_utils.h"


int min_temp (WeatherTable a) {
    int res=INT_MAX;

    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (res > a[year][month][day]._min_temp)
                {
                    res = a[year][month][day]._min_temp;
                }
                
            }
        }
    }
    return res;
}

void highest_temp_year (WeatherTable a, int output[YEARS]) {
    
    for (unsigned int year = 0u; year < YEARS; ++year) {
        output[year]=INT_MIN;
    }

    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (output[year] < a[year][month][day]._max_temp)
                {
                    output[year] = a[year][month][day]._max_temp;
                }
                 
            }
        }
    }
}



unsigned int monthly_rainfall (WeatherTable a, int year, month_t month) {
    unsigned int rainfall = 0u;
    
    for (unsigned int day = 0u; day < DAYS; ++day) {
                rainfall = rainfall + a[year][month][day]._rainfall;
    }
    
    return rainfall;
}

void most_rain_year (WeatherTable a, month_t output[YEARS]) {
    int rainfall;
    int aux=0u;

    for (unsigned int year = 0u; year < YEARS; ++year) {
        rainfall = 0u;
        for (month_t month = january; month <= december; ++month) {
            aux = monthly_rainfall(a, year, month);
            if(rainfall < aux){
                rainfall = aux;
                output[year]=month+1;
            }
        }
    }
}