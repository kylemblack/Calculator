#ifndef _LEFT_PARENTHESIS_COMMAND_H_
#define _LEFT_PARENTHESIS_COMMAND_H_

#include "Expr_Command.h"

class Left_Parenthesis_Command : public Expr_Command
{
public:
    Left_Parenthesis_Command (Stack <int> & s);

    ~Left_Parenthesis_Command (void);

    virtual std::string token (void);

    virtual int get_precedence (void);
    
private:
    virtual bool execute (void);
};

#include "Left_Parenthesis_Command.cpp"

#endif
