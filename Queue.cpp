//
// Default Constructor
//
template <typename T>
Queue<T>::Queue(void)
: base_ (Array<T>(0))
{

}

//
// Copy Constructor
//
template <typename T>
Queue<T>::Queue(const Queue & q)
: base_ (Array<T>(q.size()))
{
    for (int i = 0; i < this->size(); ++i)
    {
        this->base_[i] = q.base_[i];
    }
}

//
// Destructor
//
template <typename T>
Queue<T>::~Queue(void)
{

}

//
// operator =
//
template <typename T>
const Queue<T> & Queue <T>::operator = (const Queue & rhs)
{
    if(this == &rhs)
    {
        return *this;
    }

    //resize to size of rhs queue
    this->base_.resize(rhs.size());

    //copy queue
    for (int i = 0; i < this->base_.size(); ++i)
    {
        this->base_[i] = rhs.base_[i];
    }

    return *this;
}

//
// enqueue
//
template <typename T>
void Queue<T>::enqueue(T element)
{
    //add the new element, resize the array
    this->base_[this->size()] = element;
    this->base_.resize(this->size() + 1);
}

//
// dequeue
//
template <typename T>
T Queue<T>::dequeue(void)
{
    
    //check to see if queue is empty
    if (this->is_empty())
    {
        throw empty_exception();
    }
    else
    {
        T temp = this->base_[0];

        //shift all elements down the queue
        for (int i = 0; i < this->size() - 1; ++i)
        {
            base_[i] = base_[i + 1];
        }

        //resize
        this->base_.resize(this->size() - 1);
        return temp;
    }
}

//
// clear
//
template <typename T>
void Queue<T>::clear(void)
{
    this->base_.resize(0);
}
