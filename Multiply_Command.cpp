Multiply_Command::Multiply_Command(Stack <int> & s)
: Binary_Op_Command(s)
{

}

Multiply_Command::~Multiply_Command(void)
{

}

int Multiply_Command::evaluate(int n1, int n2) const
{
    return n1*n2;
}

std::string Multiply_Command::token (void)
{
    return "*";
}

int Multiply_Command::get_precedence (void)
{
    return MULTDIVMODPREC;
}