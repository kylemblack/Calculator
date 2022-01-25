#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array(size_t length)
: Array_Base<T>(length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
: Array_Base<T>(length, fill)
{

}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
: Array_Base<T>(array.size())
{
    for (int i = 0; i < array.size(); ++i)
    {
        this->data_[i] = array[i];
    }
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{

}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    //check for self assignment
    if (this == &rhs)
    {
        return *this;
    }

    //check for size of rhs array, resize if necessary
    if (rhs.size() == this->cur_size_)
    {
        //copy array contents
        for (int i = 0; i < rhs.size(); ++i)
        {
            this->data_[i] = rhs[i];
        }

        return *this;
    }
    else
    {
        this->resize(rhs.size());
        //copy array contents
        for (int i = 0; i < rhs.size(); ++i)
        {
            this->data_[i] = rhs[i];
        }

        return *this;
    }
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    //if new size equals current size no action is necessary, return
    //if new size is smaller than max_size we need only shrink current size
    //otherwise we need to increase size
    if (new_size == this->cur_size_)
    {
        return;
    }
    else if (new_size <= this->max_size_)
    {
        this->cur_size_ = new_size;
    }
    else
    {
        //create a temp array to store data
        T * temp = new T[new_size];
        //copy data over
        for (int i = 0; i < new_size; ++i)
        {
            temp[i] = this->data_[i];
        }

        //change the sizes
        this->max_size_ = new_size;
        this->cur_size_ = new_size; 
        
        //swap before deletion
        std::swap(this->data_, temp);
        delete [] temp;
    }
}