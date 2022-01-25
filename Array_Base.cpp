#define DEFAULT_SIZE 512

#include <stdexcept>         // for std::out_of_bounds exception

//
// Array_Base
//

template<typename T>
Array_Base <T>::Array_Base(void)
: data_ (new T [DEFAULT_SIZE]),
  cur_size_ (DEFAULT_SIZE),
  max_size_ (DEFAULT_SIZE)
{

}

// Init constructor
template<typename T>
Array_Base <T>::Array_Base(size_t length)
: data_ (new T [DEFAULT_SIZE]),
  cur_size_ (length),
  max_size_ (DEFAULT_SIZE)
{

}

//Fill constructor
template<typename T>
Array_Base <T>::Array_Base(size_t length, T fill)
: data_ (new T [length]),
  cur_size_ (length),
  max_size_ (length)
{
    //fill
    for (int i = 0; i < length; ++i)
    {
        this->data_[i] = fill;
    }
}

//
// ~Array_Base
//
template<typename T>
Array_Base <T>::~Array_Base(void)
{
    delete [] this->data_;
}


//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
    //check to make sure index is in range
    if (index <= this->cur_size_)
    {
        return this->data_[index];
    }
    else
    {
        throw std::out_of_range("Error: Index out of range");
    }
}

//
// operator []
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
    //check to make sure index is in range
    if (index <= this->cur_size_)
    {
        return this->data_[index];
    }
    else
    {
        throw std::out_of_range("Error: Index out of range");
    }
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
    //check to make sure index is in range
    if (index <= this->cur_size_)
    {
        return this->data_[index];
    }
    else
    {
        throw std::out_of_range("Error: Index out of range");
    }
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
    //check to make sure index is in range
    if (index <= this->cur_size_)
    {
        this->data_[index] = value;
    }
    else
    {
        throw std::out_of_range("Error: Index out of range");
    }
}

//
// find (T)
//
template <typename T>
int Array_Base <T>::find (T value) const
{
    //search for value
    for (int i = 0; i < this->cur_size_; ++i)
    {
        if (this->data_[i] == value)
        {
            return i;
        }
    }

    return -1;
}

//
// find (T, size_t)
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
    //make sure start index is in range
    if (start > this->cur_size_)
    {
        throw std::out_of_range("Error: Start index out of range.");
    }
    else
    {
        //search for value
        for (int i = start; i < this->cur_size_; ++i)
        {
            if (this->data_[i] == val)
            {
                return i;
            }
        }
    }

    return -1;
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
    //check for self assignment
    if (this == &rhs)
    {
        return true;
    }

    //compare the sizes, if they are different return false
    //if sizes are the same compare individual elements, if any are not the same return false
    if (this->cur_size_ == rhs.size())
    {
        for (int i = 0; i < this->cur_size_; ++i)
        {
            if (this->data_[i] != rhs[i])
            {
                return false;
            }
        }

        return true;
    }
    else
    {
        return false;
    }
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
    //use the == operator above to define !=
    if (*this == rhs)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
    for (int i = 0; i < this->cur_size_; ++i)
    {
        this->data_[i] = value;
    }
}