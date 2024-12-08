
#include <value_register_common.hpp>

/**
 * @brief Increment the test counter past the max limit,
 *        packet bits should not wrap back to 0x0 
 * 
 */
TEST(Dac7718OffsetPacket, IncrementTo0xFFFWrap)
{
    GenericIncrementTo0xFFFWrap(
        DAC7718::OffsetDacAPacket{ true }
    );
}

/**
 * @brief Decrement the test counter below 0,
 *        packet bits should not wrap back to 0xFFF 
 * 
 */
TEST(Dac7718OffsetPacket, DecrementToZeroWrap)
{
    GenericDecrementToZeroWrap(
        DAC7718::OffsetDacAPacket{ true, DAC7718::Register::OffsetDac{0xFFF} }
    );
}

/**
 * @brief Test increment3db function, check it doesn't wrap at 0x800 or 0xFFF
 * 
 */
TEST(Dac7718OffsetPacket, Increment3dbFrom0)
{
    GenericIncrement3dbFrom0(
        DAC7718::OffsetDacAPacket{ true }
    );
}

/**
 * @brief Test increment3db function, check it doesn't wrap at 0x800 or 0xFFF
 * 
 */
TEST(Dac7718OffsetPacket, Increment3dbFrom1)
{
    GenericIncrement3dbFrom1(
        DAC7718::OffsetDacAPacket{ true, DAC7718::Register::OffsetDac{0x001} }
    );
}

/**
 * @brief Test decrement3db function, check it doesn't wrap at 0x0
 * 
 */
TEST(Dac7718OffsetPacket, Decrement3dbFrom0x800)
{
    GenericDecrement3dbFrom0x800(
        DAC7718::OffsetDacAPacket{ true, DAC7718::Register::OffsetDac{0x800} }
    );
}

/**
 * @brief Test decrement3db function, check it doesn't wrap at 0x0
 * 
 */
TEST(Dac7718OffsetPacket, Decrement3dbFrom0xFFF)
{
    GenericDecrement3dbFrom0xFFF(
        DAC7718::OffsetDacAPacket{ true, DAC7718::Register::OffsetDac{0xFFF} }
    );
}