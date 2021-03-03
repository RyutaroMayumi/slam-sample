#include "SampleClass.h"


// Definitions of class variables
const int SampleClass::INITIAL_PARAM_N = 1;


// Private functions
void SampleClass::initParamN()
{
    mParamN = INITIAL_PARAM_N;
}


// Public functions
SampleClass::SampleClass()
: mParamN(0)
{
    initParamN();
}

SampleClass::~SampleClass()
{}

void SampleClass::setParamN(int n)
{
    mParamN = n;
}

int SampleClass::getParamN()
{
    return mParamN;
}
