#ifndef _RIGHT_PARENTHESIS_COMMAND_H_
#define _RIGHT_PARENTHESIS_COMMAND_H_

#include "Expr_Command.h"

class Right_Parenthesis_Command : public Expr_Command
{
public:
    Right_Parenthesis_Command (Stack <int> & s);

    ~Right_Parenthesis_Command (void);

    virtual std::string token (void);

    virtual int get_precedence (void);
    
private:
    virtual bool execute (void);
};

#include "Right_Parenthesis_Command.cpp"

#endif
