#include <iostream>

using namespace std;

int main()
{
    double f1L, f1H, f2L, f2H, frL, frH;
    double frequency, bandDouble;
    auto getFreqEdge = [&](double& fnL, double& fnH){
        fnL = frequency - 0.5 * (bandDouble);
        fnH = frequency + 0.5 * (bandDouble);
    };
    
    frequency = 1900;
    bandDouble = 1;
    getFreqEdge(f1L, f1H);
    std::cout << "f1L:" << f1L << ", f1H:" << f1H << std::endl;
    
    frequency = 1800;
    bandDouble = 2;
    getFreqEdge(f2L, f2H);
    std::cout << "f2L:" << f2L << ", f2H:" << f2H << std::endl;
    // f1L:1899.5, f1H:1900.5
    // f2L:1799, f2H:1801
    return 0;
}
