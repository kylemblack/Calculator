#ifndef _FLYWEIGHT_EXPR_COMMAND_FACTORY_H_
#define _FLYWEIGHT_EXPR_COMMAND_FACTORY_H_

#include "Expr_Command_Factory.h"

class Flyweight_Expr_Command_Factory : public Expr_Command_Factory
{
public:
    Flyweight_Expr_Command_Factory (Stack <int> & s);

    ~Flyweight_Expr_Command_Factory (void);

    virtual Num_Command * create_num_command (int num);

    virtual Add_Command * create_add_command (void);

    virtual Subtract_Command * create_subtract_command (void);

    virtual Divide_Command * create_divide_command (void);

    virtual Multiply_Command * create_multiply_command (void);

    virtual Modulus_Command * create_modulus_command (void);

    virtual Left_Parenthesis_Command * create_left_parenthesis_command (void);

    virtual Right_Parenthesis_Command * create_right_parenthesis_command (void);
    
private:
    Stack <int> & s_;
    Add_Command * add_;
    Subtract_Command * subtract_;
    Divide_Command * divide_;
    Multiply_Command * multiply_;
    Modulus_Command * modulus_;
    Left_Parenthesis_Command * left_p_;
    Right_Parenthesis_Command * right_p_;
};

#include "Flyweight_Expr_Command_Factory.cpp"

#endif