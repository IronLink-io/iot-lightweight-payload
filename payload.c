#include "payload.h"

void iot_lp_add_init(iot_lp_payload *payload) {
    // Set the starting position
    payload->position = 0;
}

void iot_lp_dump_hex(iot_lp_payload *payload, char *payload_hex) {

    char tmp_hex[5] = {'\0'};

    char *position = payload_hex;

    for(uint8_t i=0; i<=(payload->position-1); i++) {

        /*if (i) {
            pos += sprintf(position, " ");
        }*/

        position += sprintf(position, "%02x", payload->data[i]);
    }
}

void iot_lp_payload_add(iot_lp_payload *payload, iot_lp_data_type data_type, uint8_t port, uint8_t size, uint8_t *bytes) {

    // First byte of value is the port
    payload->data[payload->position] = port;
    payload->position++;

    // Second byte is the data format
    payload->data[payload->position] = data_type;
    payload->position++;

    // Add the payload
    for(uint8_t i=0; i<=(size-1); i++) {
        payload->data[payload->position] = bytes[i];
        payload->position++;
    }
}

void _iot_lp_add_16B(iot_lp_payload *payload, uint8_t port, iot_lp_data_type type, int16_t value) {

    uint8_t bytes[IOT_LP_DECIMAL_16B_SIZE];
    bytes[0] = (value >> 8) & 0xFF;
    bytes[1] = value        & 0xFF;

    iot_lp_payload_add(payload, type, port, IOT_LP_DECIMAL_16B_SIZE, bytes);
}

void iot_lp_add_int8(iot_lp_payload *payload, uint8_t port, int8_t value) {

    uint8_t bytes[IOT_LP_DECIMAL_8B_SIZE];
    bytes[0] = value;

    iot_lp_payload_add(payload, IOT_LP_INT_8B, port, IOT_LP_DECIMAL_8B_SIZE, bytes);
}

void iot_lp_add_int16(iot_lp_payload *payload, uint8_t port, int16_t value) {

    uint8_t bytes[IOT_LP_DECIMAL_16B_SIZE];
    bytes[0] = (value >> 8) & 0xFF;
    bytes[1] = value        & 0xFF;

    iot_lp_payload_add(payload, IOT_LP_INT_16B, port, IOT_LP_DECIMAL_16B_SIZE, bytes);
}

void iot_lp_add_int32(iot_lp_payload *payload, uint8_t port, int32_t value) {

    uint8_t bytes[IOT_LP_DECIMAL_32B_SIZE];
    bytes[0] = (value >> 24) & 0xFF;
    bytes[1] = (value >> 16) & 0xFF;
    bytes[2] = (value >> 8)  & 0xFF;
    bytes[3] = value         & 0xFF;

    iot_lp_payload_add(payload, IOT_LP_INT_32B, port, IOT_LP_DECIMAL_32B_SIZE, bytes);
}

void iot_lp_add_int64(iot_lp_payload *payload, uint8_t port, int64_t value) {

    uint8_t bytes[IOT_LP_DECIMAL_64B_SIZE];
    bytes[0] = (value >> 56) & 0xFF;
    bytes[1] = (value >> 48) & 0xFF;
    bytes[2] = (value >> 40) & 0xFF;
    bytes[3] = (value >> 32) & 0xFF;
    bytes[4] = (value >> 24) & 0xFF;
    bytes[5] = (value >> 16) & 0xFF;
    bytes[6] = (value >> 8)  & 0xFF;
    bytes[7] = value         & 0xFF;

    iot_lp_payload_add(payload, IOT_LP_INT_64B, port, IOT_LP_DECIMAL_64B_SIZE, bytes);
}

void iot_lp_add_uint8(iot_lp_payload *payload, uint8_t port, uint8_t value) {

    uint8_t bytes[IOT_LP_DECIMAL_8B_SIZE];
    bytes[0] = value;

    iot_lp_payload_add(payload, IOT_LP_UINT_8B, port, IOT_LP_DECIMAL_8B_SIZE, bytes);
}

void iot_lp_add_uint16(iot_lp_payload *payload, uint8_t port, uint16_t value) {

    uint8_t bytes[IOT_LP_DECIMAL_16B_SIZE];
    bytes[0] = (value >> 8) & 0xFF;
    bytes[1] = value        & 0xFF;

    iot_lp_payload_add(payload, IOT_LP_UINT_16B, port, IOT_LP_DECIMAL_16B_SIZE, bytes);
}

void iot_lp_add_uint32(iot_lp_payload *payload, uint8_t port, uint32_t value) {

    uint8_t bytes[IOT_LP_DECIMAL_32B_SIZE];
    bytes[0] = (value >> 24) & 0xFF;
    bytes[1] = (value >> 16) & 0xFF;
    bytes[2] = (value >> 8)  & 0xFF;
    bytes[3] = value         & 0xFF;

    iot_lp_payload_add(payload, IOT_LP_UINT_32B, port, IOT_LP_DECIMAL_32B_SIZE, bytes);
}

void iot_lp_add_uint64(iot_lp_payload *payload, uint8_t port, uint64_t value) {

    uint8_t bytes[IOT_LP_DECIMAL_64B_SIZE];
    bytes[0] = (value >> 56) & 0xFF;
    bytes[1] = (value >> 48) & 0xFF;
    bytes[2] = (value >> 40) & 0xFF;
    bytes[3] = (value >> 32) & 0xFF;
    bytes[4] = (value >> 24) & 0xFF;
    bytes[5] = (value >> 16) & 0xFF;
    bytes[6] = (value >> 8)  & 0xFF;
    bytes[7] = value         & 0xFF;

    iot_lp_payload_add(payload, IOT_LP_UINT_64B, port, IOT_LP_DECIMAL_64B_SIZE, bytes);
}

void iot_lp_add_float(iot_lp_payload *payload, uint8_t port, float value) {

    uint8_t bytes[IOT_LP_FLOAT_SIZE];

    uint8_t *b = (uint8_t*)&value;
    bytes[0] = b[0];
    bytes[1] = b[1];
    bytes[2] = b[2];
    bytes[3] = b[3];

    /*float sample = 0.0;
    *((uint8_t*)(&sample) + 0) = b[0];
    *((uint8_t*)(&sample) + 1) = b[1];
    *((uint8_t*)(&sample) + 2) = b[2];
    *((uint8_t*)(&sample) + 3) = b[3];

    printf("Float: %f\n", value);
    printf("Float: %f\n", sample);*/

    iot_lp_payload_add(payload, IOT_LP_FLOAT, port, IOT_LP_FLOAT_SIZE, bytes);
}

void iot_lp_add_double(iot_lp_payload *payload, uint8_t port, double value) {

    uint8_t bytes[IOT_LP_DOUBLE_SIZE];

    uint8_t *b = (uint8_t*)&value;
    bytes[0] = b[0];
    bytes[1] = b[1];
    bytes[2] = b[2];
    bytes[3] = b[3];
    bytes[4] = b[4];
    bytes[5] = b[5];
    bytes[6] = b[6];
    bytes[7] = b[7];

    /*double sample = 0.0;
    *((uint8_t*)(&sample) + 0) = b[0];
    *((uint8_t*)(&sample) + 1) = b[1];
    *((uint8_t*)(&sample) + 2) = b[2];
    *((uint8_t*)(&sample) + 3) = b[3];
    *((uint8_t*)(&sample) + 4) = b[4];
    *((uint8_t*)(&sample) + 5) = b[5];
    *((uint8_t*)(&sample) + 6) = b[6];
    *((uint8_t*)(&sample) + 7) = b[7];

    printf("Float: %lf\n", value);
    printf("Float: %lf\n", sample);*/

    iot_lp_payload_add(payload, IOT_LP_DOUBLE, port, IOT_LP_DOUBLE_SIZE, bytes);
}

void iot_lp_add_digital(iot_lp_payload *payload, uint8_t port, uint8_t value) {

    uint8_t bytes[IOT_LP_DECIMAL_8B_SIZE];
    bytes[0] = value;

    iot_lp_payload_add(payload, IOT_LP_DIGITAL, port, IOT_LP_DECIMAL_8B_SIZE, bytes);
}

void iot_lp_add_temperature_c(iot_lp_payload *payload, uint8_t port, float temperature) {

    // Temp C will be stored in int format, save 2 decimal places
    temperature *= 100;
    _iot_lp_add_16B(payload, port, IOT_LP_TEMPERATURE_C, temperature);
}

void iot_lp_add_temperature_f(iot_lp_payload *payload, uint8_t port, float temperature) {

    // Temp F will be stored in int format, save 2 decimal places
    temperature *= 100;
    _iot_lp_add_16B(payload, port, IOT_LP_TEMPERATURE_F, temperature);
}

void iot_lp_add_temperature_k(iot_lp_payload *payload, uint8_t port, float temperature) {

    // Temp K will be stored in int format, save 2 decimal places
    temperature *= 100;
    _iot_lp_add_16B(payload, port, IOT_LP_TEMPERATURE_K, temperature);
}