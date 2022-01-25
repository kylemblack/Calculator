#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Op_Command.h"

class Subtract_Command : public Binary_Op_Command
{
public:
    Subtract_Command (Stack <int> & s);

    ~Subtract_Command (void);

    virtual std::string token (void);

    virtual int evaluate(int n1, int n2) const;

    virtual int get_precedence(void);
};

#include "Subtract_Command.cpp"

#endif