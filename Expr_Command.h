#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

#define ADDSUBPREC 1
#define MULTDIVMODPREC 2

#include <string>
#include "Stack.h"

class Expr_Command
{
public:
    Expr_Command (Stack <int> & s);

    ~Expr_Command (void);

    virtual bool execute (void) = 0;

    virtual std::string token (void) = 0;

    virtual int get_precedence (void) = 0;

protected:
    Stack <int> & s_;
};

#include "Expr_Command.cpp"

#endif
