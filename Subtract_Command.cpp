Subtract_Command::Subtract_Command(Stack <int> & s)
: Binary_Op_Command(s)
{

}

Subtract_Command::~Subtract_Command(void)
{

}

int Subtract_Command::evaluate(int n1, int n2) const
{
    return n1-n2;
}

std::string Subtract_Command::token (void)
{
    return "-";
}

int Subtract_Command::get_precedence(void)
{
    return ADDSUBPREC;
}