Binary_Op_Command::Binary_Op_Command(Stack <int> & s)
: Expr_Command(s)
{

}

Binary_Op_Command::~Binary_Op_Command(void)
{
    
}

bool Binary_Op_Command::execute(void)
{
    int n2 = this->s_.top(); this->s_.pop();
    int n1 = this->s_.top(); this->s_.pop();

    try
    {
        int result = this->evaluate(n1, n2);
        s_.push(result);
    }
    catch (const char * e_msg)
    {
        std::cout << e_msg << std::endl;
        return false;
    }

    return true;
}