#include <gtest/gtest.h>
#include <dac7718.hpp>
#include <helpers.hpp>

TEST(Dac7718GeneralPurposeIOPacket, Defaults)
{
    DAC7718::GeneralPurposeIOPacket gpio_packet{ 
        true
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x82, 0xE0, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000101110000000000000};
    
    auto [packet_bytes, packet_bits] = gpio_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718GeneralPurposeIOPacket, GPIO2_low)
{
    DAC7718::GeneralPurposeIOPacket gpio_packet{ 
        true
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x82, 0x60, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000100110000000000000};
    gpio_packet.data().set(DAC7718::Register::GeneralPurposeIO::Gpio2Bit::LOW);

    auto [packet_bytes, packet_bits] = gpio_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718GeneralPurposeIOPacket, GPIO1_low)
{
    DAC7718::GeneralPurposeIOPacket gpio_packet{ 
        true
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x82, 0xA0, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000101010000000000000};
    gpio_packet.data().set(DAC7718::Register::GeneralPurposeIO::Gpio1Bit::LOW);

    auto [packet_bytes, packet_bits] = gpio_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718GeneralPurposeIOPacket, GPIO0_low)
{
    DAC7718::GeneralPurposeIOPacket gpio_packet{ 
        true
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x82, 0xC0, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000101100000000000000};
    gpio_packet.data().set(DAC7718::Register::GeneralPurposeIO::Gpio0Bit::LOW);

    auto [packet_bytes, packet_bits] = gpio_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718GeneralPurposeIOPacket, all_low)
{
    DAC7718::GeneralPurposeIOPacket gpio_packet{ 
        true
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x82, 0x00, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000100000000000000000};
    gpio_packet.data().set(DAC7718::Register::GeneralPurposeIO::Gpio2Bit::LOW);
    gpio_packet.data().set(DAC7718::Register::GeneralPurposeIO::Gpio1Bit::LOW);
    gpio_packet.data().set(DAC7718::Register::GeneralPurposeIO::Gpio0Bit::LOW);

    auto [packet_bytes, packet_bits] = gpio_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}