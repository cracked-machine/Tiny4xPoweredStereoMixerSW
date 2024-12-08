#ifndef __DAC7718_TEST_HELPERS_HPP__
#define __DAC7718_TEST_HELPERS_HPP__

#include <dac7718.hpp>

// @brief Print out the provided bitset as bytes
// @param pattern The bitset to print

void print_bits(DAC7718::Types::ShiftRegisterBits &packet_bits);
void print_bytes(const DAC7718::Types::ShiftRegisterBytes &bytes);


#endif // __DAC7718_TEST_HELPERS_HPP__