#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Binary_Op_Command.h"

class Divide_Command : public Binary_Op_Command
{
public:
    Divide_Command (Stack <int> & s);

    ~Divide_Command (void);

    virtual std::string token (void);

    virtual int evaluate (int n1, int n2) const;

    virtual int get_precedence (void);
};

#include "Divide_Command.cpp"

#endif