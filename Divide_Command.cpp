Divide_Command::Divide_Command (Stack <int> & s)
: Binary_Op_Command(s)
{

}

Divide_Command::~Divide_Command (void)
{

}

int Divide_Command::evaluate (int n1, int n2) const
{
    if (n2 == 0)
    {
        throw "Error: Divide by 0";
    }
    else
    {
        return n1/n2;
    }
}

std::string Divide_Command::token (void)
{
    return "/";
}

int Divide_Command::get_precedence(void)
{
    return MULTDIVMODPREC;
}