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


TEST(Dac7718Suite, Dac7718ConfigPacketDataDefaults)
{
    DAC7718::ConfigPacket cdp{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x00};
    std::string bits{"100000001000000000000000"};
    ASSERT_EQ(bits.size(), 24);
    DAC7718::ShiftRegisterBits expected_sr_bits{bits};
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);

}
TEST(Dac7718Suite, Dac7718ConfigPacketDataInputRegister)
{
    DAC7718::ConfigPacket cdp{ true };
 
    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x00, 0x00};
    std::string bits{"100000000000000000000000"};
    ASSERT_EQ(bits.size(), 24);
    DAC7718::ShiftRegisterBits expected_sr_bits{bits};

    cdp.data().set_input_register(DAC7718::ConfigData::InputRegister::INPUT_DATA_REGISTER);
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);

}

TEST(Dac7718Suite, Dac7718ConfigPacketDataLatchData)
{
    DAC7718::ConfigPacket cdp{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0xC0, 0x00};
    std::string bits{"100000001100000000000000"};
    ASSERT_EQ(bits.size(), 24);
    DAC7718::ShiftRegisterBits expected_sr_bits{bits};

    cdp.data().set_latch_data(DAC7718::ConfigData::LatchData::UPDATE);
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}