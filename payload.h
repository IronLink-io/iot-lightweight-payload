#ifndef IOT_LIGHTWEIGHT_PAYLOAD_PAYLOAD_H
#define IOT_LIGHTWEIGHT_PAYLOAD_PAYLOAD_H

#include <stdint.h>
#include <stdio.h>
#include "type.h"

#define IOT_LP_MAX_PAYLOAD_BUFFER 256

typedef struct {
    uint8_t    data[IOT_LP_MAX_PAYLOAD_BUFFER];
    uint8_t   position;
} iot_lp_payload;

void iot_lp_add_init(iot_lp_payload *payload);
void iot_lp_dump_hex(iot_lp_payload *payload, char *payload_hex);
void iot_lp_print_payload(iot_lp_payload *payload);
uint8_t iot_lp_get_data_size(iot_lp_data_type type);
void iot_lp_payload_add(iot_lp_payload *payload, iot_lp_data_type data_type, uint8_t port, uint8_t size, uint8_t *bytes);

void _iot_lp_add_8B(iot_lp_payload *payload, uint8_t port, iot_lp_data_type type, int16_t value);
void _iot_lp_add_16B(iot_lp_payload *payload, uint8_t port, iot_lp_data_type type, int16_t value);
void _iot_lp_add_32B(iot_lp_payload *payload, uint8_t port, iot_lp_data_type type, int32_t value);
void _iot_lp_add_64B(iot_lp_payload *payload, uint8_t port, iot_lp_data_type type, int64_t value);

// Signed integer functions
void iot_lp_add_int8(iot_lp_payload *payload, uint8_t port, int8_t value);
void iot_lp_add_int16(iot_lp_payload *payload, uint8_t port, int16_t value);
void iot_lp_add_int32(iot_lp_payload *payload, uint8_t port, int32_t value);
void iot_lp_add_int64(iot_lp_payload *payload, uint8_t port, int64_t value);

// Unsigned integer functions
void iot_lp_add_uint8(iot_lp_payload *payload, uint8_t port, uint8_t value);
void iot_lp_add_uint16(iot_lp_payload *payload, uint8_t port, uint16_t value);
void iot_lp_add_uint32(iot_lp_payload *payload, uint8_t port, uint32_t value);
void iot_lp_add_uint64(iot_lp_payload *payload, uint8_t port, uint64_t value);

// Floating point functions
void iot_lp_add_float(iot_lp_payload *payload, uint8_t port, float value);
void iot_lp_add_double(iot_lp_payload *payload, uint8_t port, double value);

// Digital functions
void iot_lp_add_digital(iot_lp_payload *payload, uint8_t port, uint8_t value);

// Temperature functions
void iot_lp_add_temperature_c(iot_lp_payload *payload, uint8_t port, float temperature);
void iot_lp_add_temperature_f(iot_lp_payload *payload, uint8_t port, float temperature);
void iot_lp_add_temperature_k(iot_lp_payload *payload, uint8_t port, float temperature);

// Barometric pressure functions
void iot_lp_add_barometric_pressure(iot_lp_payload *payload, uint8_t port, float pressure);

#endif //IOT_LIGHTWEIGHT_PAYLOAD_PAYLOAD_H