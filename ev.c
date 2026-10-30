#include <emscripten/emscripten.h>

/*
 * EV ChargeMate calculation engine.
 * Returns a pointer to 4 floats:
 * [0] battery energy (kWh)
 * [1] grid energy (kWh)
 * [2] estimated cost (₹)
 * [3] estimated time (hours)
 */
EMSCRIPTEN_KEEPALIVE
float *calculate(float capacity,
                 float start,
                 float target,
                 float tariff,
                 float power,
                 float efficiency) {
    static float result[4];

    result[0] = -1.0f; /* invalid input marker */

    if (capacity <= 0.0f ||
        start < 0.0f || start > 100.0f ||
        target < start || target > 100.0f ||
        tariff < 0.0f ||
        power <= 0.0f ||
        efficiency <= 0.0f || efficiency > 100.0f) {
        return result;
    }

    float eta = efficiency / 100.0f;

    result[0] = capacity * (target - start) / 100.0f;
    result[1] = result[0] / eta;
    result[2] = result[1] * tariff;
    result[3] = result[0] / (power * eta);

    return result;
}
