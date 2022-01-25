Num_Command::Num_Command (Stack <int> & s, int num)
: Expr_Command(s),
  num_ (num)
{

}

Num_Command::~Num_Command (void)
{

}

bool Num_Command::execute(void)
{
    this->s_.push(this->num_);
    return true;
}

std::string Num_Command::token (void)
{
    return std::to_string(this->num_);
}

int Num_Command::get_precedence(void)
{
    return 0;
}