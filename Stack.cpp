//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
: base_ (Array<T>(0))
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
: base_ (Array<T>(stack.size()))
{
    for (int i = 0; i < stack.size(); ++i)
    {
        this->base_[i] = stack.base_[i];
    }
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{

}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{ 
    //push the element and increase the size of the stack  
    this->base_[this->size()] = element;
    this->base_.resize(this->size() + 1);
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{   
    //check if empty, if not resize
    if (this->is_empty())
    {
        throw empty_exception();
    }
    else
    {
        this->base_.resize(this->size() - 1);
    }
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    //resize to size of copied stack
    this->base_.resize(rhs.size());

    //copy elements of the stack
    for (int i = 0; i < rhs.size(); ++i)
    {
        this->base_[i] = rhs.base_[i];
    }

    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    this->base_.resize(0);
}
