#ifndef __VALUE_REGISTER_COMMON_HPP__
#define __VALUE_REGISTER_COMMON_HPP__

#include <gtest/gtest.h>
#include <dac7718.hpp>
#include <value_register_common.hpp>
#include <helpers.hpp>

/**
 * @brief Increment the test counter past the max limit,
 *        packet bits should not wrap back to 0x0 
 * 
 * @tparam VALUEPACKETONLY 
 * @param sut 
 */
template<class VALUEPACKETONLY>
void GenericIncrementTo0xFFFWrap(
    VALUEPACKETONLY sut, 
    const DAC7718::Types::ShiftRegisterBytes &expected_final_sr_bytes, 
    const DAC7718::Types::ShiftRegisterBits &expected_final_sr_bits)
{
    uint16_t saturate = 10;

    for ( 
        uint16_t test_counter = 0; 
        test_counter < sut.data().MAX + saturate; 
        sut.data()++)
    {
        
        if (test_counter < sut.data().MAX)
            ASSERT_EQ(sut.data().value(), test_counter);
        else 
            ASSERT_EQ(sut.data().value(), sut.data().MAX - 1);
        
        test_counter++;
    }
    auto [packet_bytes, packet_bits] = sut.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);
    ASSERT_EQ(packet_bits, expected_final_sr_bits);
    ASSERT_EQ(packet_bytes, expected_final_sr_bytes);
}

/**
 * @brief Decrement the test counter below 0,
 *        packet bits should not wrap back to 0xFFF 
 * 
 * @tparam VALUEPACKETONLY 
 * @param sut 
 */
template<class VALUEPACKETONLY>
void GenericDecrementToZeroWrap(
    VALUEPACKETONLY sut, 
    const DAC7718::Types::ShiftRegisterBytes &expected_final_sr_bytes, 
    const DAC7718::Types::ShiftRegisterBits &expected_final_sr_bits)
{

    int16_t saturate = -10;

    for ( int16_t test_counter = 4095; test_counter > saturate; sut.data()--)
    {
        if (test_counter > -1)
            ASSERT_EQ(sut.data().value(), test_counter);
        else
            ASSERT_EQ(sut.data().value(), 0);

        test_counter--;
        std::cerr << sut.data().value() << std::endl;
    }

    auto [packet_bytes, packet_bits] = sut.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);
    ASSERT_EQ(packet_bits, expected_final_sr_bits);
    ASSERT_EQ(packet_bytes, expected_final_sr_bytes);
}

/**
 * @brief Test increment3db function, check it doesn't wrap at 0x800 or 0xFFF
 * 
 * @tparam VALUEPACKETONLY 
 * @param sut 
 */
template<class VALUEPACKETONLY>
void GenericIncrement3dbFrom0(
    VALUEPACKETONLY sut, 
    const DAC7718::Types::ShiftRegisterBytes &expected_final_sr_bytes, 
    const DAC7718::Types::ShiftRegisterBits &expected_final_sr_bits)
{
    size_t saturate = 10;
    for(size_t i = 0; i < DAC7718::Register::Config::WIDTH + saturate; i++)
    {
        sut.data().increase_3db();
        auto [packet_bytes2, packet_bits2] = sut.serialize();
        print_bytes(packet_bytes2);
        print_bits(packet_bits2);    
    }
    auto [packet_bytes, packet_bits] = sut.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);
    ASSERT_EQ(packet_bits, expected_final_sr_bits);
    ASSERT_EQ(packet_bytes, expected_final_sr_bytes);
}

/**
 * @brief Test increment3db function, check it doesn't wrap at 0x800 or 0xFFF
 * 
 * @tparam VALUEPACKETONLY 
 * @param sut 
 */
template<class VALUEPACKETONLY>
void GenericIncrement3dbFrom1(
    VALUEPACKETONLY sut, 
    const DAC7718::Types::ShiftRegisterBytes &expected_final_sr_bytes, 
    const DAC7718::Types::ShiftRegisterBits &expected_final_sr_bits)
{
    size_t saturate = 10;
    for(size_t i = 0; i < DAC7718::Register::Config::WIDTH + saturate; i++)
    {
        sut.data().increase_3db();
        auto [packet_bytes2, packet_bits2] = sut.serialize();
        print_bytes(packet_bytes2);
        print_bits(packet_bits2);    
    }
    auto [packet_bytes, packet_bits] = sut.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);
    ASSERT_EQ(packet_bits, expected_final_sr_bits);
    ASSERT_EQ(packet_bytes, expected_final_sr_bytes);
}

/**
 * @brief Test decrement3db function, check it doesn't wrap at 0x0
 * 
 * @tparam VALUEPACKETONLY 
 * @param sut 
 */
template<class VALUEPACKETONLY>
void GenericDecrement3dbFrom0x800(
    VALUEPACKETONLY sut, 
    const DAC7718::Types::ShiftRegisterBytes &expected_final_sr_bytes, 
    const DAC7718::Types::ShiftRegisterBits &expected_final_sr_bits)
{
    int saturate = -10;
    for(int i = DAC7718::Register::Config::WIDTH - 1; i > saturate; i--)
    {
        sut.data().decrease_3db();
        auto [packet_bytes2, packet_bits2] = sut.serialize();
        print_bytes(packet_bytes2);
        print_bits(packet_bits2);    
    }
    auto [packet_bytes, packet_bits] = sut.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);
    ASSERT_EQ(packet_bits, expected_final_sr_bits);
    ASSERT_EQ(packet_bytes, expected_final_sr_bytes);
}

/**
 * @brief Test decrement3db function, check it doesn't wrap at 0x0
 * 
 * @tparam VALUEPACKETONLY 
 * @param sut 
 */
template<class VALUEPACKETONLY>
void GenericDecrement3dbFrom0xFFF(
    VALUEPACKETONLY sut, 
    const DAC7718::Types::ShiftRegisterBytes &expected_final_sr_bytes, 
    const DAC7718::Types::ShiftRegisterBits &expected_final_sr_bits)
{
    int saturate = -10;
    for(int i = DAC7718::Register::Config::WIDTH - 1; i > saturate; i--)
    {
        sut.data().decrease_3db();
        auto [packet_bytes2, packet_bits2] = sut.serialize();
        print_bytes(packet_bytes2);
        print_bits(packet_bits2);    
    }
    auto [packet_bytes, packet_bits] = sut.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);
    ASSERT_EQ(packet_bits, expected_final_sr_bits);
    ASSERT_EQ(packet_bytes, expected_final_sr_bytes);
}

#endif // __VALUE_REGISTER_COMMON_HPP__