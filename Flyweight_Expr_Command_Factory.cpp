Flyweight_Expr_Command_Factory::Flyweight_Expr_Command_Factory (Stack <int> & s)
: s_ (s),
  add_ (new Add_Command(this->s_)),
  subtract_ (new Subtract_Command(this->s_)),
  divide_ (new Divide_Command(this->s_)),
  multiply_ (new Multiply_Command(this->s_)),
  modulus_ (new Modulus_Command(this->s_)),
  left_p_ (new Left_Parenthesis_Command(this->s_)),
  right_p_ (new Right_Parenthesis_Command(this->s_))
{

}

Flyweight_Expr_Command_Factory::~Flyweight_Expr_Command_Factory (void)
{
    delete this->add_;
    delete this->subtract_;
    delete this->divide_;
    delete this->multiply_;
    delete this->modulus_;
    delete this->left_p_;
    delete this->right_p_;
}

Num_Command * Flyweight_Expr_Command_Factory::create_num_command (int num)
{
    return new Num_Command (this->s_, num);
}

Add_Command * Flyweight_Expr_Command_Factory::create_add_command (void)
{
    return this->add_;
}

Subtract_Command * Flyweight_Expr_Command_Factory::create_subtract_command (void)
{
    return this->subtract_;
}

Divide_Command * Flyweight_Expr_Command_Factory::create_divide_command (void)
{
    return this->divide_;
}

Multiply_Command * Flyweight_Expr_Command_Factory::create_multiply_command (void)
{
    return this->multiply_;
}

Modulus_Command * Flyweight_Expr_Command_Factory::create_modulus_command (void)
{
    return this->modulus_;
}

Left_Parenthesis_Command * Flyweight_Expr_Command_Factory::create_left_parenthesis_command (void)
{
    return this->left_p_;
}

Right_Parenthesis_Command * Flyweight_Expr_Command_Factory::create_right_parenthesis_command (void)
{
    return this->right_p_;
}