#include <gtest/gtest.h>
#include <dac7718.hpp>
#include <helpers.hpp>

TEST(Dac7718SpiModePacket, Defaults)
{
    DAC7718::SpiModePacket spimode_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x86, 0x00, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100001100000000000000000};
    
    auto [packet_bytes, packet_bits] = spimode_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);

}

TEST(Dac7718SpiModePacket, SleepEnabled)
{
    DAC7718::SpiModePacket spimode_packet{ true, DAC7718::Register::SpiMode::Preset::SLEEP };
    
    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x86, 0x80, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100001101000000000000000};
    
    auto [packet_bytes, packet_bits] = spimode_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);

}