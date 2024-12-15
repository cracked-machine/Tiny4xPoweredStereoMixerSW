
#include <value_register_common.hpp>

/**
 * @brief Increment the test counter past the max limit,
 *        packet bits should not wrap back to 0x0 
 * 
 */
TEST(Dac7718Zero7Packet, IncrementTo0xFFFWrap)
{
    GenericIncrementTo0xFFFWrap(
        DAC7718::ZeroData7Packet{ true },
        DAC7718::Types::ShiftRegisterBytes{ 0x97, 0xFF, 0xF0 },
        DAC7718::Types::ShiftRegisterBits{ 0b100101111111111111110000 }
    );
}

/**
 * @brief Decrement the test counter below 0,
 *        packet bits should not wrap back to 0xFFF 
 * 
 */
TEST(Dac7718Zero7Packet, DecrementToZeroWrap)
{
    GenericDecrementToZeroWrap(
        DAC7718::ZeroData7Packet{ true, DAC7718::Register::RawValue{0xFFF} },
        DAC7718::Types::ShiftRegisterBytes{ 0x97, 0x00, 0x00 },
        DAC7718::Types::ShiftRegisterBits{ 0b100101110000000000000000 }
    );
}

/**
 * @brief Test increment3db function, check it doesn't wrap at 0x800 or 0xFFF
 * 
 */
TEST(Dac7718Zero7Packet, Increment3dbFrom0)
{
    GenericIncrement3dbFrom0(
        DAC7718::ZeroData7Packet{ true },
        DAC7718::Types::ShiftRegisterBytes{ 0x97, 0xFF, 0xF0 },
        DAC7718::Types::ShiftRegisterBits{ 0b100101111111111111110000 }
    );
}

/**
 * @brief Test increment3db function, check it doesn't wrap at 0x800 or 0xFFF
 * 
 */
TEST(Dac7718Zero7Packet, Increment3dbFrom1)
{
    GenericIncrement3dbFrom1(
        DAC7718::ZeroData7Packet{ true, DAC7718::Register::RawValue{0x001} },
        DAC7718::Types::ShiftRegisterBytes{ 0x97, 0xFF, 0xF0 },
        DAC7718::Types::ShiftRegisterBits{ 0b100101111111111111110000 }
    );
}

/**
 * @brief Test decrement3db function, check it doesn't wrap at 0x0
 * 
 */
TEST(Dac7718Zero7Packet, Decrement3dbFrom0x800)
{
    GenericDecrement3dbFrom0x800(
        DAC7718::ZeroData7Packet{ true, DAC7718::Register::RawValue{0x800} },
        DAC7718::Types::ShiftRegisterBytes{ 0x97, 0x00, 0x00 },
        DAC7718::Types::ShiftRegisterBits{ 0b100101110000000000000000 }
    );
}

/**
 * @brief Test decrement3db function, check it doesn't wrap at 0x0
 * 
 */
TEST(Dac7718Zero7Packet, Decrement3dbFrom0xFFF)
{
    GenericDecrement3dbFrom0xFFF(
        DAC7718::ZeroData7Packet{ true, DAC7718::Register::RawValue{0xFFF} },
        DAC7718::Types::ShiftRegisterBytes{ 0x97, 0x00, 0x00 },
        DAC7718::Types::ShiftRegisterBits{ 0b100101110000000000000000 }
    );
}