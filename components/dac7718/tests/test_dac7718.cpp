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


TEST(Dac7718Suite, ConfigPacketDefaults)
{
    DAC7718::ConfigPacket cdp{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000000000000000};
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);

}
TEST(Dac7718Suite,ConfigPacketInputRegister)
{
    DAC7718::ConfigPacket cdp{ true };
 
    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x00, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000000000000000000000};

    cdp.data().set(DAC7718::ConfigData::InputRegister::INPUT_DATA_REGISTER);
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);

}

TEST(Dac7718Suite, ConfigPacketLatchData)
{
    DAC7718::ConfigPacket cdp{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0xC0, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001100000000000000};

    cdp.data().set(DAC7718::ConfigData::LatchData::UPDATE);
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718Suite, ConfigPacketReset)
{
    DAC7718::ConfigPacket cdp{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0xA0, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001010000000000000};

    cdp.data().set(DAC7718::ConfigData::Reset::POR);
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718Suite, ConfigPacketPwrDwnA)
{
    DAC7718::ConfigPacket cdp{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x90, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001001000000000000};

    cdp.data().set(DAC7718::ConfigData::PowerDownGroupA::PWROFF);
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718Suite, ConfigPacketPwrDwnB)
{
    DAC7718::ConfigPacket cdp{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x88, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000100000000000};

    cdp.data().set(DAC7718::ConfigData::PowerDownGroupB::PWROFF);
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718Suite, ConfigPacketSCE)
{
    DAC7718::ConfigPacket cdp{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x84, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000010000000000};

    cdp.data().set(DAC7718::ConfigData::SystemCallibration::ENABLED);
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718Suite, ConfigPacketGainA)
{
    DAC7718::ConfigPacket cdp{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x81, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000000100000000};

    cdp.data().set(DAC7718::ConfigData::GainGroupA::x4);
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718Suite, ConfigPacketGainB)
{
    DAC7718::ConfigPacket cdp{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x80};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000000010000000};

    cdp.data().set(DAC7718::ConfigData::GainGroupB::x4);
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718Suite, ConfigPacketSDO)
{
    DAC7718::ConfigPacket cdp{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x40};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000000001000000};

    cdp.data().set(DAC7718::ConfigData::SDO::DISABLED);
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718Suite, ConfigPacketNOOPWrite)
{
    DAC7718::ConfigPacket cdp{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x20};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000000000100000};

    cdp.data().set(DAC7718::ConfigData::NoOpWrite::ENABLED);
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718Suite, ConfigPacketAuxWakeup)
{
    DAC7718::ConfigPacket cdp{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x10};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000000000010000};

    cdp.data().set(DAC7718::ConfigData::AuxWakeupPin::CSPIN);
    
    auto [packet_bytes, packet_bits] = cdp.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}