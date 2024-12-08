#include <gtest/gtest.h>
#include <dac7718.hpp>
#include <helpers.hpp>

/**
 * @brief Test increment operator normal operation
 * 
 */
TEST(Dac7718OffsetPacket, IncrementFromZero)
{
    DAC7718::OffsetDacAPacket offdac_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_final_sr_bytes{0x83, 0xFF, 0xF0};
    DAC7718::Types::ShiftRegisterBits expected_final_sr_bits{0b100000111111111111110000};
    for ( uint16_t expected_value = 0; expected_value < offdac_packet.data().MAX; offdac_packet.data()++)
    {
        ASSERT_EQ(offdac_packet.data().value(), expected_value);
        expected_value++;
        std::cerr << offdac_packet.data().value() << std::endl;
    }
    auto [packet_bytes, packet_bits] = offdac_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_final_sr_bits);
    ASSERT_EQ(packet_bytes,expected_final_sr_bytes);
}

/**
 * @brief Increment the test counter past the max limit,
 *        packet bits should not wrap back to 0x0 
 * 
 */
TEST(Dac7718OffsetPacket, IncrementWrap)
{
    DAC7718::OffsetDacAPacket offdac_packet{ true };
    DAC7718::Types::ShiftRegisterBytes expected_final_sr_bytes{0x83, 0xFF, 0xF0};
    DAC7718::Types::ShiftRegisterBits expected_final_sr_bits{0b100000111111111111110000};

    uint16_t saturate = 10;

    for ( 
        uint16_t test_counter = 0; 
        test_counter < offdac_packet.data().MAX + saturate; 
        offdac_packet.data()++)
    {
        
        if (test_counter < offdac_packet.data().MAX)
            ASSERT_EQ(offdac_packet.data().value(), test_counter);
        else 
            ASSERT_EQ(offdac_packet.data().value(), offdac_packet.data().MAX - 1);
        
        test_counter++;
    }
    auto [packet_bytes, packet_bits] = offdac_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);
    ASSERT_EQ(packet_bits,expected_final_sr_bits);
    ASSERT_EQ(packet_bytes,expected_final_sr_bytes);
}

/**
 * @brief Test decrement operator normal operation
 * 
 */
TEST(Dac7718OffsetPacket, DecrementToZero)
{

    DAC7718::OffsetDacAPacket offdac_packet{ true, DAC7718::Register::OffsetDac{0xFFF} };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x83, 0x00, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000110000000000000000};
    for ( int16_t expected_value = 4095; expected_value > -1; offdac_packet.data()--)
    {

        ASSERT_EQ(offdac_packet.data().value(), expected_value);
        expected_value--;
        std::cerr << offdac_packet.data().value() << std::endl;
    }

    auto [packet_bytes, packet_bits] = offdac_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);
    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

/**
 * @brief Decrement the test counter below 0,
 *        packet bits should not wrap back to 0xFFF 
 * 
 */
TEST(Dac7718OffsetPacket, DecrementToZeroWrap)
{
    DAC7718::OffsetDacAPacket offdac_packet{ true, DAC7718::Register::OffsetDac{0xFFF} };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x83, 0x00, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000110000000000000000};

    int16_t saturate = -10;

    for ( int16_t test_counter = 4095; test_counter > saturate; offdac_packet.data()--)
    {
        if (test_counter > -1)
            ASSERT_EQ(offdac_packet.data().value(), test_counter);
        else
            ASSERT_EQ(offdac_packet.data().value(), 0);

        test_counter--;
        std::cerr << offdac_packet.data().value() << std::endl;
    }

    auto [packet_bytes, packet_bits] = offdac_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);
    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}