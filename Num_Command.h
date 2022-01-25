#ifndef _NUM_COMMAND_H_
#define _NUM_COMMAND_H_

#include "Expr_Command.h"

class Num_Command : public Expr_Command
{
public:
    Num_Command(Stack <int> & s, int num);

    ~Num_Command (void);

    virtual std::string token (void);

    virtual bool execute (void);

    virtual int get_precedence (void);

private:
    int num_;
};

#include "Num_Command.cpp"

#endif