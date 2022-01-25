#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Flyweight_Expr_Command_Factory.h"

class Calculator
{
public:
    Calculator (void);

    ~Calculator (void);
    
    void infix_to_postfix(const std::string & infix,
                          Expr_Command_Factory & factory,
                          Queue <Expr_Command *> & postfix);
    
    int calculate(const std::string & infix);
};

#include "Calculator.cpp"

#endif