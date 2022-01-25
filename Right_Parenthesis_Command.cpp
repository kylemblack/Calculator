Right_Parenthesis_Command::Right_Parenthesis_Command (Stack <int> & s)
: Expr_Command (s)
{

}

Right_Parenthesis_Command::~Right_Parenthesis_Command (void)
{

}

bool Right_Parenthesis_Command::execute (void)
{
    return true;
}

std::string Right_Parenthesis_Command::token (void)
{
    return ")";
}

int Right_Parenthesis_Command::get_precedence (void)
{
    return 0;
}