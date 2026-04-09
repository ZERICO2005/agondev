/*
 * Title:			basic floating point example
 * Author:			Paul Cawte
 * Created:			1978 by K&R
 * Last Updated:	08/06/2023
 *
 * Modinfo:
 *  Copied from Fahrenheit-Celsius floating point example from K&R
 *  Adapted to ANSI C
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits>

extern "C" {
uint8_t crt_bdivu(uint8_t num, uint8_t den);
int8_t crt_bdivs(int8_t num, int8_t den);
uint8_t crt_bremu(uint8_t num, uint8_t den);
int8_t crt_brems(int8_t num, int8_t den);
uint16_t crt_sdivu(uint16_t num, uint16_t den);
int16_t crt_sdivs(int16_t num, int16_t den);
uint16_t crt_sremu(uint16_t num, uint16_t den);
int16_t crt_srems(int16_t num, int16_t den);
uint24_t crt_idivu(uint24_t num, uint24_t den);
int24_t crt_idivs(int24_t num, int24_t den);
uint24_t crt_iremu(uint24_t num, uint24_t den);
int24_t crt_irems(int24_t num, int24_t den);
uint32_t crt_ldivu(uint32_t num, uint32_t den);
int32_t crt_ldivs(int32_t num, int32_t den);
uint32_t crt_lremu(uint32_t num, uint32_t den);
int32_t crt_lrems(int32_t num, int32_t den);
uint48_t crt_i48divu(uint48_t num, uint48_t den);
int48_t crt_i48divs(int48_t num, int48_t den);
uint48_t crt_i48remu(uint48_t num, uint48_t den);
int48_t crt_i48rems(int48_t num, int48_t den);
uint64_t crt_lldivu(uint64_t num, uint64_t den);
int64_t crt_lldivs(int64_t num, int64_t den);
uint64_t crt_llremu(uint64_t num, uint64_t den);
int64_t crt_llrems(int64_t num, int64_t den);
}

template<class T>
T crt_divu(T num, T den);
template<class T>
T crt_divs(T num, T den);
template<class T>
T crt_remu(T num, T den);
template<class T>
T crt_rems(T num, T den);

template<> inline uint8_t crt_divu<uint8_t>(uint8_t num, uint8_t den) {
    return crt_bdivu(num, den);
}
template<> inline int8_t crt_divs<int8_t>(int8_t num, int8_t den) {
    return crt_bdivs(num, den);
}
template<> inline uint8_t crt_remu<uint8_t>(uint8_t num, uint8_t den) {
    return crt_bremu(num, den);
}
template<> inline int8_t crt_rems<int8_t>(int8_t num, int8_t den) {
    return crt_brems(num, den);
}
template<> inline uint16_t crt_divu<uint16_t>(uint16_t num, uint16_t den) {
    return crt_sdivu(num, den);
}
template<> inline int16_t crt_divs<int16_t>(int16_t num, int16_t den) {
    return crt_sdivs(num, den);
}
template<> inline uint16_t crt_remu<uint16_t>(uint16_t num, uint16_t den) {
    return crt_sremu(num, den);
}
template<> inline int16_t crt_rems<int16_t>(int16_t num, int16_t den) {
    return crt_srems(num, den);
}
template<> inline uint24_t crt_divu<uint24_t>(uint24_t num, uint24_t den) {
    return crt_idivu(num, den);
}
template<> inline int24_t crt_divs<int24_t>(int24_t num, int24_t den) {
    return crt_idivs(num, den);
}
template<> inline uint24_t crt_remu<uint24_t>(uint24_t num, uint24_t den) {
    return crt_iremu(num, den);
}
template<> inline int24_t crt_rems<int24_t>(int24_t num, int24_t den) {
    return crt_irems(num, den);
}
template<> inline uint32_t crt_divu<uint32_t>(uint32_t num, uint32_t den) {
    return crt_ldivu(num, den);
}
template<> inline int32_t crt_divs<int32_t>(int32_t num, int32_t den) {
    return crt_ldivs(num, den);
}
template<> inline uint32_t crt_remu<uint32_t>(uint32_t num, uint32_t den) {
    return crt_lremu(num, den);
}
template<> inline int32_t crt_rems<int32_t>(int32_t num, int32_t den) {
    return crt_lrems(num, den);
}
template<> inline uint48_t crt_divu<uint48_t>(uint48_t num, uint48_t den) {
    return crt_i48divu(num, den);
}
template<> inline int48_t crt_divs<int48_t>(int48_t num, int48_t den) {
    return crt_i48divs(num, den);
}
template<> inline uint48_t crt_remu<uint48_t>(uint48_t num, uint48_t den) {
    return crt_i48remu(num, den);
}
template<> inline int48_t crt_rems<int48_t>(int48_t num, int48_t den) {
    return crt_i48rems(num, den);
}
template<> inline uint64_t crt_divu<uint64_t>(uint64_t num, uint64_t den) {
    return crt_lldivu(num, den);
}
template<> inline int64_t crt_divs<int64_t>(int64_t num, int64_t den) {
    return crt_lldivs(num, den);
}
template<> inline uint64_t crt_remu<uint64_t>(uint64_t num, uint64_t den) {
    return crt_llremu(num, den);
}
template<> inline int64_t crt_rems<int64_t>(int64_t num, int64_t den) {
    return crt_llrems(num, den);
}

#define C(func, num, op, den) if (!(func<T>(T(num), T(den)) == (T(num) op T(den)))) { return __LINE__; }

template<class T>
void test_divu(const char* name) {
    // test small values
    C(crt_divu, 0, /, 1);
    C(crt_divu, 1, /, 1);
    C(crt_divu, 2, /, 1);
    C(crt_divu, 0, /, 2);
    C(crt_divu, 1, /, 2);
    C(crt_divu, 2, /, 2);

    // test exact division
    C(crt_divu, 100, /, 25);
    C(crt_divu,  21, /,  3);
    // test inexact division
    C(crt_divu, 111, /,  7);
    C(crt_divu,  22, /,  7);
    // test zero quotient
    C(crt_divu,  80, /, 81);
    C(crt_divu,   5, /, 12);

    // test large values
    C(crt_divu, std::numeric_limits<T>::max() - 0, /, std::numeric_limits<T>::max() - 0);
    C(crt_divu, std::numeric_limits<T>::max() - 0, /, std::numeric_limits<T>::max() - 1);
    C(crt_divu, std::numeric_limits<T>::max() - 1, /, std::numeric_limits<T>::max() - 0);
    C(crt_divu, std::numeric_limits<T>::max() - 1, /, std::numeric_limits<T>::max() - 1);
    C(crt_divu, 0, /, std::numeric_limits<T>::max());
    C(crt_divu, 1, /, std::numeric_limits<T>::max());
    C(crt_divu, std::numeric_limits<T>::max(), /, 1);
    C(crt_divu, std::numeric_limits<T>::max(), /, 42);

    // test that division by zero does not crash
    crt_divu<T>(0, 0);
    crt_divu<T>(1, 0);
    crt_divu<T>(std::numeric_limits<T>::max(), 0);
}

template<class T>
void test_remu(const char* name) {
    // test small values
    C(crt_remu, 0, %, 1);
    C(crt_remu, 1, %, 1);
    C(crt_remu, 2, %, 1);
    C(crt_remu, 0, %, 2);
    C(crt_remu, 1, %, 2);
    C(crt_remu, 2, %, 2);

    // test exact remainder
    C(crt_remu, 100, %, 25);
    C(crt_remu,  21, %,  3);
    // test inexact remainder
    C(crt_remu, 111, %,  7);
    C(crt_remu,  22, %,  7);
    // test zero quotient
    C(crt_remu,  80, %, 81);
    C(crt_remu,   5, %, 12);

    // test large values
    C(crt_remu, std::numeric_limits<T>::max() - 0, %, std::numeric_limits<T>::max() - 0);
    C(crt_remu, std::numeric_limits<T>::max() - 0, %, std::numeric_limits<T>::max() - 1);
    C(crt_remu, std::numeric_limits<T>::max() - 1, %, std::numeric_limits<T>::max() - 0);
    C(crt_remu, std::numeric_limits<T>::max() - 1, %, std::numeric_limits<T>::max() - 1);
    C(crt_remu, 0, %, std::numeric_limits<T>::max());
    C(crt_remu, 1, %, std::numeric_limits<T>::max());
    C(crt_remu, std::numeric_limits<T>::max(), %, 1);
    C(crt_remu, std::numeric_limits<T>::max(), %, 42);

    // test that remainder by zero does not crash
    crt_remu<T>(0, 0);
    crt_remu<T>(1, 0);
    crt_remu<T>(std::numeric_limits<T>::max(), 0);
}

int run_tests(void) {
    test_divu<uint8_t>("bdivu");
    test_divs<int8_t>("bdivs");
    test_remu<uint8_t>("bremu");
    test_rems<int8_t>("brems");
    test_divu<uint16_t>("sdivu");
    test_divs<int16_t>("sdivs");
    test_remu<uint16_t>("sremu");
    test_rems<int16_t>("srems");
    test_divu<uint24_t>("idivu");
    test_divs<int24_t>("idivs");
    test_remu<uint24_t>("iremu");
    test_rems<int24_t>("irems");
    test_divu<uint32_t>("ldivu");
    test_divs<int32_t>("ldivs");
    test_remu<uint32_t>("lremu");
    test_rems<int32_t>("lrems");
    test_divu<uint48_t>("i48divu");
    test_divs<int48_t>("i48divs");
    test_remu<uint48_t>("i48remu");
    test_rems<int48_t>("i48rems");
    test_divu<uint64_t>("lldivu");
    test_divs<int64_t>("lldivs");
    test_remu<uint64_t>("llremu");
    test_rems<int64_t>("llrems");
    return 0;
}

extern "C" int main(void)
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celcius = (5.0/9.0) * (fahr-32);
        printf("%3.0f %6.1f\n\r", fahr, celcius);
        fahr = fahr + step;
    }
	return 0;
}
