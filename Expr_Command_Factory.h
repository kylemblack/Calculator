#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Num_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Divide_Command.h"
#include "Multiply_Command.h"
#include "Modulus_Command.h"
#include "Left_Parenthesis_Command.h"
#include "Right_Parenthesis_Command.h"
#include "Stack.h"

class Expr_Command_Factory
{
public:
    Expr_Command_Factory (void);

    virtual ~Expr_Command_Factory (void);

    virtual Num_Command * create_num_command (int num) = 0;

    virtual Add_Command * create_add_command (void) = 0;

    virtual Subtract_Command * create_subtract_command (void) = 0;

    virtual Divide_Command * create_divide_command (void) = 0;

    virtual Multiply_Command * create_multiply_command (void) = 0;

    virtual Modulus_Command * create_modulus_command (void) = 0;

    virtual Left_Parenthesis_Command * create_left_parenthesis_command (void) = 0;

    virtual Right_Parenthesis_Command * create_right_parenthesis_command (void) = 0;

};

#include "Expr_Command_Factory.cpp"

#endif