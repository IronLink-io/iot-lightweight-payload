#include <stdio.h>

#include "payload.h"

int main() {

    char payload_str[256];
    iot_lp_payload payload;

    iot_lp_add_init(&payload);

    //iot_lp_add_uint8(&payload, 2, 16);
    //iot_lp_add_uint16(&payload, 2, 290);
    //iot_lp_add_uint32(&payload, 2, 290);
    //iot_lp_add_uint64(&payload, 2, 2255890);

    //iot_lp_add_int64(&payload, 2, 2255890);

    //iot_lp_add_float(&payload, 2, 2.255);
    //iot_lp_add_double(&payload, 2, 2.2556);

    //iot_lp_add_temperature_c(&payload, 2, -160.43);
    //iot_lp_add_temperature_f(&payload, 2, -160.43);
    //iot_lp_add_temperature_k(&payload, 2, 356.43);

    iot_lp_dump_hex(&payload, payload_str);

    printf("Payload: %s Position: %d\n", payload_str, payload.position);

    return 0;
}
