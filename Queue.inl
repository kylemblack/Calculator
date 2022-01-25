//
// size
//
template <typename T>
inline
size_t Queue <T>::size(void) const
{
    return this->base_.size();
}

//
// is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty(void) const
{
    if (this->base_.size() < 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}