Add_Command::Add_Command(Stack <int> & s)
: Binary_Op_Command(s)
{

}

Add_Command::~Add_Command(void)
{
    
}

int Add_Command::evaluate(int n1, int n2) const
{
    return n1+n2;
}

std::string Add_Command::token(void)
{
    return "+";
}

int Add_Command::get_precedence(void)
{
    return ADDSUBPREC;
}