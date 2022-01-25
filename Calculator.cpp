Calculator::Calculator (void)
{

}

Calculator::~Calculator (void)
{

}

void Calculator::infix_to_postfix (const std::string & infix,
                                   Expr_Command_Factory & factory,
                                   Queue<Expr_Command *> & postfix)
{
    std::istringstream input(infix);
    std::string token;
    Expr_Command * cmd = 0;
    Stack <Expr_Command *> temp;

    while(!input.eof())
    {
        input >> token;

        //check if token is an operator
        if(token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
        {
            //create command based on operator
            if(token == "+")
            {
                cmd = factory.create_add_command();
            }
            else if (token == "-")
            {
                cmd = factory.create_subtract_command();
            }
            else if (token == "*")
            {
                cmd = factory.create_multiply_command();
            }
            else if (token == "/")
            {
                cmd = factory.create_divide_command();
            }
            else if (token == "%")
            {
                cmd = factory.create_modulus_command();
            }

            //if the stack is empty simply push it to the stack
            if(temp.is_empty())
            {
                temp.push(cmd);
            }
            else
            {
                //place each operator of equal or higher precedence into the postfix queue
                while (!temp.is_empty() && temp.top()->get_precedence() >= cmd->get_precedence())
                {
                    postfix.enqueue(temp.top());
                    temp.pop();
                }
                //place the new operator on the stack
                temp.push(cmd);
            }
        }
        else if (token == "(")
        {
            //if the operator is a left parenthesis place it directly on the stack
            cmd = factory.create_left_parenthesis_command();
            temp.push(cmd);
        }
        else if (token == ")")
        {
            //place all operators that are not a left parenthesis in the postfix queue
            while(!temp.is_empty() && temp.top()->token() != "(")
            {
                postfix.enqueue(temp.top());
                temp.pop();
            }
            //once a left parenthesis is encountered discard it
            if(temp.top()->token() == "(")
            {
                temp.pop();
            }
        }
        //if the input is not a operator check if it is a number, if it is also not an number then it is an invalid input
        else if (!std::isalpha(token[0]))
        {
            //convert token to an integer
            int num = std::stoi(token);

            cmd = factory.create_num_command(num);

            //place number command directly in postfix queue
            postfix.enqueue(cmd);
        }
        else
        {
            //inform user of invalid input and exit the function
            std::cout << "Error: Invalid Expression" << std::endl;
            return;
        }
    }

    //place all remaining elements of the stack in the queue
    while (!temp.is_empty())
    {
        postfix.enqueue(temp.top());
        temp.pop();
    }
}

int Calculator::calculate(const std::string & infix)
{
    bool good_input = true;

    int postfix_size;

    Stack <int> result;

    Queue <Expr_Command*> postfix;

    Flyweight_Expr_Command_Factory factory(result);

    infix_to_postfix(infix, factory, postfix);

    postfix_size = postfix.size();

    for(int i = 0; i < postfix_size; ++i)
    {
        if (postfix.dequeue()->execute())
        {
            //continue
        }
        else
        {
            good_input = false;
            break;
        }
    }

    if (good_input)
    {
        return result.top();
    }
    else
    {
        throw "Error: Invalid Expression.";
    }

    result.clear();
    postfix.clear();
}