#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Op_Command.h"

class Add_Command : public Binary_Op_Command
{
public:
    Add_Command (Stack <int> & s);

    ~Add_Command (void);

    virtual std::string token (void);

    virtual int evaluate(int n1, int n2) const;

    virtual int get_precedence (void);
};

#include "Add_Command.cpp"

#endif