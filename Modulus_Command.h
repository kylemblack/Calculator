#ifndef _MODULUS_COMMAND_H_
#define _MODULUS_COMMAND_H_

#include "Binary_Op_Command.h"

class Modulus_Command : public Binary_Op_Command
{
public:
    Modulus_Command (Stack <int> & s);

    ~Modulus_Command (void);

    virtual std::string token (void);

    virtual int evaluate (int n1, int n2) const;

    virtual int get_precedence (void);
};

#include "Modulus_Command.cpp"

#endif