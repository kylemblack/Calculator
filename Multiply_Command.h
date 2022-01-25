#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Op_Command.h"

class Multiply_Command : public Binary_Op_Command
{
public:
    Multiply_Command (Stack <int> & s);

    ~Multiply_Command (void);

    virtual std::string token (void);

    virtual int evaluate (int n1, int n2) const;

    virtual int get_precedence(void);
};

#include "Multiply_Command.cpp"

#endif
