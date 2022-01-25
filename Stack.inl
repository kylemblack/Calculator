//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return this->base_.size();
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    if (this->is_empty())
    {
        throw empty_exception();
    }
    else
    {
        return this->base_[this->size() - 1];
    }
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    if (this->size() < 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
