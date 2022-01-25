#ifndef _BINARY_OP_COMMAND_H_
#define _BINARY_OP_COMMAND_H_

#include "Expr_Command.h"

class Binary_Op_Command : public Expr_Command
{
public:
    Binary_Op_Command (Stack <int> & s);

    ~Binary_Op_Command (void);

    virtual bool execute (void);

    virtual std::string token (void) = 0;

    virtual int evaluate (int n1, int n2) const = 0;

    virtual int get_precedence (void) = 0;
};

#include "Binary_Op_Command.cpp"

#endif
