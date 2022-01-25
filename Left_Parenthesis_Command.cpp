Left_Parenthesis_Command::Left_Parenthesis_Command (Stack <int> & s)
: Expr_Command (s)
{

}

Left_Parenthesis_Command::~Left_Parenthesis_Command (void)
{

}

bool Left_Parenthesis_Command::execute (void)
{
    return true;
}

std::string Left_Parenthesis_Command::token (void)
{
    return "(";
}

int Left_Parenthesis_Command::get_precedence(void)
{
    return 0;
}