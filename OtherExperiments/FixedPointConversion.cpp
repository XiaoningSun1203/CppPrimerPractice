#include <cstdint>
#include <cstdio>

// 只取决于你用什么容器盛它
#include <iostream>
#include <math.h>

int main()
{
    int32_t v1 = -5;
    printf("%d : 0x%x\n", v1, v1);
    uint32_t v2 = v1;
    printf("%u : 0x%x\n", v2, v2);

    uint32_t value = 4215276080;

    double lowValue = 0.0;
    double highValue = 0.0;
    if (((value >> 31) & 0x1) == 1)  // if bit at 32 is 1, this is a negative number
    {
        int16_t store = value >> 16;
        highValue = - static_cast<int16_t>(~ (store - 1)) / std::pow(2, 15);
    }
    else
    {
        highValue = (value >> 16) / std::pow(2, 15);
    }

    if (((value >> 15) & 0x1) == 1)  // if bit at 16 is 1, this is a negative number
    {
        int16_t store = value & 0xFFFF;
        lowValue = - static_cast<int16_t>(~ (store - 1)) / pow(2, 15);
    }
    else
    {
        lowValue = (value & 0xFFFF) / pow(2, 15);
    }
    std::cout << lowValue << "," << highValue << std::endl;
    
    double highValue_2 = static_cast<int16_t>(value >> 16) / std::pow(2, 15);
    double lowValue_2= static_cast<int16_t>(value & 0xFFFF) / std::pow(2, 15);
    std::cout << lowValue_2 << "," << highValue_2 << std::endl;
    
    // 0.0170898,-0.0371094
    // 0.0170898,-0.0371094

    return 0;
}
