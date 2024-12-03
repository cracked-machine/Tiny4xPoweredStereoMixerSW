#include <gtest/gtest.h>
#include <dac7718.hpp>
#include <helpers.hpp>

TEST(Dac7718GPIOPacket, Defaults)
{
    DAC7718::GPIOPacket gpio_packet{ 
        true
    };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x82, 0xE0, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000101110000000000000};
    
    auto [packet_bytes, packet_bits] = gpio_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718GPIOPacket, GPIO2_low)
{
    DAC7718::GPIOPacket gpio_packet{ 
        true
    };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x82, 0x60, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000100110000000000000};
    gpio_packet.data().set(DAC7718::GPIO::Bit::GPIO2::LOW);

    auto [packet_bytes, packet_bits] = gpio_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718GPIOPacket, GPIO1_low)
{
    DAC7718::GPIOPacket gpio_packet{ 
        true
    };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x82, 0xA0, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000101010000000000000};
    gpio_packet.data().set(DAC7718::GPIO::Bit::GPIO1::LOW);

    auto [packet_bytes, packet_bits] = gpio_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718GPIOPacket, GPIO0_low)
{
    DAC7718::GPIOPacket gpio_packet{ 
        true
    };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x82, 0xC0, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000101100000000000000};
    gpio_packet.data().set(DAC7718::GPIO::Bit::GPIO0::LOW);

    auto [packet_bytes, packet_bits] = gpio_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718GPIOPacket, all_low)
{
    DAC7718::GPIOPacket gpio_packet{ 
        true
    };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x82, 0x00, 0x00};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000100000000000000000};
    gpio_packet.data().set(DAC7718::GPIO::Bit::GPIO2::LOW);
    gpio_packet.data().set(DAC7718::GPIO::Bit::GPIO1::LOW);
    gpio_packet.data().set(DAC7718::GPIO::Bit::GPIO0::LOW);

    auto [packet_bytes, packet_bits] = gpio_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}