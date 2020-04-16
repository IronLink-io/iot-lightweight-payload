#ifndef IOT_LIGHTWEIGHT_PAYLOAD_TYPE_H
#define IOT_LIGHTWEIGHT_PAYLOAD_TYPE_H

// Format sizes in bytes
#define IOT_LP_DECIMAL_8B_SIZE  1
#define IOT_LP_DECIMAL_16B_SIZE 2
#define IOT_LP_DECIMAL_32B_SIZE 4
#define IOT_LP_DECIMAL_64B_SIZE 8

#define IOT_LP_FLOAT_SIZE       4
#define IOT_LP_DOUBLE_SIZE      8

typedef enum {

    IOT_LP_INT_8B           = 0U, // 8-bit Signed Decimal Value,  Size: 1 Byte
    IOT_LP_INT_16B          = 1U, // 16-bit Signed Decimal Value, Size: 2 Bytes
    IOT_LP_INT_32B          = 2U, // 32-bit Signed Decimal Value, Size: 4 Bytes
    IOT_LP_INT_64B          = 3U, // 64-bit Signed Decimal Value, Size: 8 Bytes

    IOT_LP_UINT_8B           = 4U, // 8-bit Unsigned Decimal Value,  Size: 1 Byte
    IOT_LP_UINT_16B          = 5U, // 16-bit Unsigned Decimal Value, Size: 2 Bytes
    IOT_LP_UINT_32B          = 6U, // 32-bit Unsigned Decimal Value, Size: 4 Bytes
    IOT_LP_UINT_64B          = 7U, // 64-bit Unsigned Decimal Value, Size: 8 Bytes

    IOT_LP_FLOAT                = 8U, // Floating Point,           Size: 4 Bytes
    IOT_LP_DOUBLE               = 9U, // Precision Floating Point, Size 8 Bytes

    IOT_LP_DIGITAL              = 10U, // Digital Value, Size 1 Byte

    IOT_LP_TEMPERATURE_C        = 11U, // Temperature Celsius, Size: 2 Bytes
    IOT_LP_TEMPERATURE_F        = 12U, // Temperature Fahrenheit, Size: 2 Bytes
    IOT_LP_TEMPERATURE_K        = 13U, // Temperature Kelvin, Size: 2 Bytes

    IOT_LP_BAROMETRIC_PRESSURE  = 14U, // Pressure hPa, Size: 4 Bytes

    IOT_LP_RELATIVE_HUMIDITY    = 15U, // Relative Humidity Percentage, 2 Bytes
    IOT_LP_ABSOLUTE_HUMIDITY    = 16U, // Absolute Humidity g/M^3, 2 Bytes

    IOT_LP_GAS_PPB              = 12U, // Parts per Billion of Gas, 2 Bytes
    IOT_LP_GAS_PPM              = 13U, // Parts per Million of Gas, 2 Bytes

    IOT_LP_GAS_PPB_CO2          = 14U, // Parts per Billion of Carbon Dioxide,   Size: 2 Bytes
    IOT_LP_GAS_PPB_CO           = 15U, // Parts per Billion of Carbon Monoxide,  Size: 2 Bytes
    IOT_LP_GAS_PPB_NO2          = 16U, // Parts per Billion of Nitrogen Dioxide, Size: 2 Bytes
    IOT_LP_GAS_PPB_NO           = 17U, // Parts per Billion of Nitric oxide,     Size: 2 Bytes
    IOT_LP_GAS_PPB_NH3          = 18U, // Parts per Billion of Ammonia,          Size: 2 Bytes
    IOT_LP_GAS_PPB_O2           = 19U, // Parts per Billion of Oxygen,           Size: 2 Bytes
    IOT_LP_GAS_PPB_O3           = 20U, // Parts per Billion of Ozone,            Size: 2 Bytes
    IOT_LP_GAS_PPB_SO2          = 21U, // Parts per Billion of Sulfur Dioxide,   Size: 2 Bytes
    IOT_LP_GAS_PPB_H2S          = 22U, // Parts per Billion of Hydrogen Sulfide, Size: 2 Bytes

} iot_lp_data_type ;

#endif //IOT_LIGHTWEIGHT_PAYLOAD_TYPE_H
