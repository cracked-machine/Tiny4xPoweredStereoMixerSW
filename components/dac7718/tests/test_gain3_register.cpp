
#include <value_register_common.hpp>

/**
 * @brief Increment the test counter past the max limit,
 *        packet bits should not wrap back to 0x0 
 * 
 */
TEST(Dac7718_Gain3Packet, IncrementTo0xFFFWrap)
{
    GenericIncrementTo0xFFFWrap(
        DAC7718::GainData3Packet{ true },
        DAC7718::Types::ShiftRegisterBytes{ 0x9B, 0xFF, 0xF0 },
        DAC7718::Types::ShiftRegisterBits{ 0b100110111111111111110000 }
    );
}

/**
 * @brief Decrement the test counter below 0,
 *        packet bits should not wrap back to 0xFFF 
 * 
 */
TEST(Dac7718_Gain3Packet, DecrementToZeroWrap)
{
    GenericDecrementToZeroWrap(
        DAC7718::GainData3Packet{ true, DAC7718::Register::RawValue{0xFFF} },
        DAC7718::Types::ShiftRegisterBytes{ 0x9B, 0x00, 0x00 },
        DAC7718::Types::ShiftRegisterBits{ 0b100110110000000000000000 }
    );
}

/**
 * @brief Test increment3db function, check it doesn't wrap at 0x800 or 0xFFF
 * 
 */
TEST(Dac7718_Gain3Packet, Increment3dbFrom0)
{
    GenericIncrement3dbFrom0(
        DAC7718::GainData3Packet{ true },
        DAC7718::Types::ShiftRegisterBytes{ 0x9B, 0xFF, 0xF0 },
        DAC7718::Types::ShiftRegisterBits{ 0b100110111111111111110000 }
    );
}

/**
 * @brief Test increment3db function, check it doesn't wrap at 0x800 or 0xFFF
 * 
 */
TEST(Dac7718_Gain3Packet, Increment3dbFrom1)
{
    GenericIncrement3dbFrom1(
        DAC7718::GainData3Packet{ true, DAC7718::Register::RawValue{0x001} },
        DAC7718::Types::ShiftRegisterBytes{ 0x9B, 0xFF, 0xF0 },
        DAC7718::Types::ShiftRegisterBits{ 0b100110111111111111110000 }
    );
}

/**
 * @brief Test decrement3db function, check it doesn't wrap at 0x0
 * 
 */
TEST(Dac7718_Gain3Packet, Decrement3dbFrom0x800)
{
    GenericDecrement3dbFrom0x800(
        DAC7718::GainData3Packet{ true, DAC7718::Register::RawValue{0x800} },
        DAC7718::Types::ShiftRegisterBytes{ 0x9B, 0x00, 0x00 },
        DAC7718::Types::ShiftRegisterBits{ 0b100110110000000000000000 }
    );
}

/**
 * @brief Test decrement3db function, check it doesn't wrap at 0x0
 * 
 */
TEST(Dac7718_Gain3Packet, Decrement3dbFrom0xFFF)
{
    GenericDecrement3dbFrom0xFFF(
        DAC7718::GainData3Packet{ true, DAC7718::Register::RawValue{0xFFF} },
        DAC7718::Types::ShiftRegisterBytes{ 0x9B, 0x00, 0x00 },
        DAC7718::Types::ShiftRegisterBits{ 0b100110110000000000000000 }
    );
}