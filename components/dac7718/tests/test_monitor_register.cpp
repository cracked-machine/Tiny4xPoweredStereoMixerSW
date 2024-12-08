#include <gtest/gtest.h>
#include <dac7718.hpp>
#include <helpers.hpp>

TEST(Dac7718MonitorPacket, Defaults)
{
    DAC7718::MonitorPacket monitor_packet{ true };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x00, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010000000000000000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, REFB_Buffer)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::REFB_BUFFER }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x00, 0x10};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010000000000010000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, REFA_Buffer)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::REFA_BUFFER }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x00, 0x20};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010000000000100000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, OffsetDacB)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::OFFSET_DACB }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x00, 0x50};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010000000001010000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, OffsetDacA)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::OFFSET_DACA }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x00, 0x60};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010000000001100000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, Ain0)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::AIN0 }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x00, 0x40};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010000000001000000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, Ain1)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::AIN1 }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x00, 0x80};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010000000010000000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, DAC0)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::DAC0 }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x01, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010000000100000000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, DAC1)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::DAC1 }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x02, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010000001000000000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, DAC2)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::DAC2 }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x04, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010000010000000000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, DAC3)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::DAC3 }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x08, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010000100000000000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, DAC4)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::DAC4 }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x10, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010001000000000000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, DAC5)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::DAC5 }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x20, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010010000000000000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, DAC6)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::DAC6 }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x40, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000010100000000000000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}

TEST(Dac7718MonitorPacket, DAC7)
{
    DAC7718::MonitorPacket monitor_packet{ 
        true, 
        DAC7718::Register::Monitor{ DAC7718::Register::Monitor::Preset::DAC7 }
    };

    DAC7718::Types::ShiftRegisterBytes expected_sr_bytes{0x81, 0x80, 0x00};
    DAC7718::Types::ShiftRegisterBits expected_sr_bits{0b100000011000000000000000};
    
    auto [packet_bytes, packet_bits] = monitor_packet.serialize();
    print_bytes(packet_bytes);
    print_bits(packet_bits);

    ASSERT_EQ(packet_bits,expected_sr_bits);
    ASSERT_EQ(packet_bytes,expected_sr_bytes);
}