#include <helpers.hpp>
#include <iostream>
#include <iomanip>

// @brief Print out the provided bitset as bytes
// @param pattern The bitset to print

void print_bits(DAC7718::Types::ShiftRegisterBits &packet_bits)
{
    std::cerr << "Printing " << packet_bits.size() << " bits:" << std::endl;
    std::cerr << "LSB ------------------ MSB " << std::endl;
    std::string packet_bits_str =  packet_bits.to_string();
    packet_bits_str.insert(8, " ");
    packet_bits_str.insert(16, " ");
    std::cerr << packet_bits_str;
    std::cerr << std::endl;
}

void print_bytes(const DAC7718::Types::ShiftRegisterBytes &bytes)
{
    for(auto byte: bytes)
    {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << unsigned(byte);
    }
    std::cout << std::dec << std::endl;
}