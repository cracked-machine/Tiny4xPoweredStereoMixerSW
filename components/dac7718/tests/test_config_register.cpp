#include <gtest/gtest.h>
#include <dac7718.hpp>
#include <helpers.hpp>

TEST(Dac7718__ConfigPacket, Defaults)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000001000000000000000};
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);

}

TEST(Dac7718__ConfigPacket, InputRegister)
{
    DAC7718::ConfigPacket config_packet{ true };
 
    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x80, 0x00, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000000000000000000000};

    config_packet.data().set(DAC7718::Register::Config::InputRegisterBit::INPUT_DATA_REGISTER);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);

}

TEST(Dac7718__ConfigPacket, LatchData)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x80, 0xC0, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000001100000000000000};

    config_packet.data().set(DAC7718::Register::Config::LatchDataBit::UPDATE);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718__ConfigPacket, Reset)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x80, 0xA0, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000001010000000000000};

    config_packet.data().set(DAC7718::Register::Config::ResetBit::POR);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718__ConfigPacket, PwrDwnA)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x80, 0x90, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000001001000000000000};

    config_packet.data().set(DAC7718::Register::Config::PowerDownGroupABit::PWROFF);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718__ConfigPacket, PwrDwnB)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x80, 0x88, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000001000100000000000};

    config_packet.data().set(DAC7718::Register::Config::PowerDownGroupBBit::PWROFF);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718__ConfigPacket, SCE)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x80, 0x84, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000001000010000000000};

    config_packet.data().set(DAC7718::Register::Config::SystemCallibrationBit::ENABLED);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718__ConfigPacket, GainA)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x80, 0x81, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000001000000100000000};

    config_packet.data().set(DAC7718::Register::Config::GainGroupABit::x4);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718__ConfigPacket, GainB)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x80};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000001000000010000000};

    config_packet.data().set(DAC7718::Register::Config::GainGroupBBit::x4);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718__ConfigPacket, SDO)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x40};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000001000000001000000};

    config_packet.data().set(DAC7718::Register::Config::SDOBit::DISABLED);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718__ConfigPacket, NOOPWrite)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x20};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000001000000000100000};

    config_packet.data().set(DAC7718::Register::Config::NoOpWriteBit::ENABLED);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}

TEST(Dac7718__ConfigPacket, AuxWakeup)
{
    DAC7718::ConfigPacket config_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x80, 0x80, 0x10};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000001000000000010000};

    config_packet.data().set(DAC7718::Register::Config::AuxWakeupPinBit::CSPIN);
    
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
    
}