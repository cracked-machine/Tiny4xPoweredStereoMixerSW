#include <gtest/gtest.h>
#include <dac7718.hpp>
#include <helpers.hpp>



TEST(Dac7718ConfigPacket, Defaults)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000000000000000};
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);

}

TEST(Dac7718ConfigPacket, InputRegister)
{
    DAC7718::ConfigPacket config_packet{ true };
 
    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x00, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000000000000000000000};

    config_packet.data().set(DAC7718::Config::Bit::InputRegister::INPUT_DATA_REGISTER);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);

}

TEST(Dac7718ConfigPacket, LatchData)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0xC0, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001100000000000000};

    config_packet.data().set(DAC7718::Config::Bit::LatchData::UPDATE);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718ConfigPacket, Reset)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0xA0, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001010000000000000};

    config_packet.data().set(DAC7718::Config::Bit::Reset::POR);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718ConfigPacket, PwrDwnA)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x90, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001001000000000000};

    config_packet.data().set(DAC7718::Config::Bit::PowerDownGroupA::PWROFF);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718ConfigPacket, PwrDwnB)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x88, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000100000000000};

    config_packet.data().set(DAC7718::Config::Bit::PowerDownGroupB::PWROFF);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718ConfigPacket, SCE)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x84, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000010000000000};

    config_packet.data().set(DAC7718::Config::Bit::SystemCallibration::ENABLED);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718ConfigPacket, GainA)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x81, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000000100000000};

    config_packet.data().set(DAC7718::Config::Bit::GainGroupA::x4);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718ConfigPacket, GainB)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x80};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000000010000000};

    config_packet.data().set(DAC7718::Config::Bit::GainGroupB::x4);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718ConfigPacket, SDO)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x40};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000000001000000};

    config_packet.data().set(DAC7718::Config::Bit::SDO::DISABLED);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718ConfigPacket, NOOPWrite)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x20};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000000000100000};

    config_packet.data().set(DAC7718::Config::Bit::NoOpWrite::ENABLED);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718ConfigPacket, AuxWakeup)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x10};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000001000000000010000};

    config_packet.data().set(DAC7718::Config::Bit::AuxWakeupPin::CSPIN);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}