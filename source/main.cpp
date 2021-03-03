#include "SampleClass.h"
#include <iostream>

int main(int argc, char** argv)
{
    int n = 255;
    SampleClass sampleClass;

    std::cout << "Initial value: " << sampleClass.getParamN() << std::endl;
    sampleClass.setParamN(n);
    std::cout << "Current value: " << sampleClass.getParamN() << std::endl;

    return 0;
}
