/**
 * @file SampleClass.h
 * @brief Definition of Class SampleClass
 * @author Ryutaro Mayumi
 * @date 2021.01.13
 */

#ifndef SAMPLECLASS_H_
#define SAMPLECLASS_H_


/**
 * @class SampleClass
 * @brief SampleClass for TDD-sample project
 */
class SampleClass {
    friend class SampleClassTest;   // Declaration for test of private functions
private:
    // Class variables
    static const int INITIAL_PARAM_N; //!< Initial value of N

    // Member variables
    int mParamN;    //!< Integer parameter N

    // Member functions
    /**
     * @fn initParamN
     * @brief Initialize mParamN to the value of INITIAL_PARAM_N
     */
    void initParamN();

public:
    // Member functions
    /**
     * @fn SampleClass
     * @brief Constructor
     */
    SampleClass();
    /**
     * @fn ~SampleClass
     * @brief Destructor
     */
    ~SampleClass();
    /**
     * @fn setParamN
     * @brief Setter method for mParamN
     * @param n Interger value to be set
     */
    void setParamN(int n);
    /**
     * @fn getParamN
     * @brief Getter method for mParamN
     * @return Integer value of mParamN
     */
    int getParamN();
};


#endif //SAMPLECLASS_H_
