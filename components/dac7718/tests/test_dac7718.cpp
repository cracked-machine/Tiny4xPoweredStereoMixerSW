#include <gtest/gtest.h>
#include <dac7718.hpp>

// @brief Print out the provided bitset as bytes
// @param pattern The bitset to print

void print_bits(DAC7718::ShiftRegisterBits &packet_bits)
{
    std::cerr << "Printing " << packet_bits.size() << " bits:" << std::endl;
    std::cerr << "LSB ------------------ MSB " << std::endl;
    std::string packet_bits_str =  packet_bits.to_string();
    packet_bits_str.insert(8, " ");
    packet_bits_str.insert(16, " ");
    std::cerr << packet_bits_str;
    std::cerr << std::endl;
}

void print_bytes(const DAC7718::ShiftRegisterBytes &bytes)
{
    for(auto byte: bytes)
    {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << unsigned(byte);
    }
    std::cout << std::dec << std::endl;
}

TEST(Dac7718Suite, Dac7718Test)
{
    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x94, 0x9B, 0x90};
    DAC7718::ShiftRegisterBits expected_sr_bits{"100101001001101110010000"};
    
    DAC7718::Packet p {
       DAC7718::DataField{std::bitset<12>{"100110111001"}},
       DAC7718::AddressField{std::bitset<5>{"10100"}},
       true 
    };
    auto [packet_bytes, packet_bits] = p.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}