#include <gtest/gtest.h>
#include <dac7718.hpp>
#include <helpers.hpp>

TEST(Dac7718OffsetPacket, Increment)
{
    DAC7718::OffsetDacAPacket offdac_packet{ true };

    DAC7718::ShiftRegisterBytes expected_sr_bytes{0x83, 0xFF, 0xF0};
    DAC7718::ShiftRegisterBits expected_sr_bits{0b100000111111111111110000};
    for ( uint16_t expected_value = 0; expected_value < offdac_packet.data().MAX; offdac_packet.data()++)
    {
        ASSERT_EQ(offdac_packet.data().value(), expected_value);
        expected_value++;
        std::cerr << offdac_packet.data().value() << std::endl;
    }
    auto [packet_bytes, packet_bits] = offdac_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}
