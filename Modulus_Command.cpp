Modulus_Command::Modulus_Command (Stack <int> & s)
: Binary_Op_Command (s)
{
    
}

Modulus_Command::~Modulus_Command (void)
{

}

int Modulus_Command::evaluate (int n1, int n2) const
{
    return n1 % n2;
}

std::string Modulus_Command::token (void)
{
    return "%";
}

int Modulus_Command::get_precedence (void)
{
    return MULTDIVMODPREC;
}