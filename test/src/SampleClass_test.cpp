#include <gtest/gtest.h>
#include "SampleClass.h"


// Defition of functions for accessing to private members
class SampleClassTest : public ::testing::Test {
protected:
    int get_initialParamN(SampleClass* sampleClass) {
        return sampleClass->INITIAL_PARAM_N;
    }

    void call_initParamN(SampleClass* sampleClass) {
        return sampleClass->initParamN();
    }

};


namespace {

    TEST_F(SampleClassTest, Initialize_mParamN) {
        // Preparation
        int n = 256;
        SampleClass sampleClass;
        sampleClass.setParamN(n);
        // Execution
        call_initParamN(&sampleClass);
        auto mParamN = sampleClass.getParamN();
        // Velification
        ASSERT_EQ(get_initialParamN(&sampleClass), mParamN);    // Pass
        // ASSERT_EQ(n, mParamN);                                  // Fail
    }

}
