#ifndef _ARRAY_BASE_H_
#define _ARRAY_BASE_H_

#include <cstring>          // for size_t definition
#include <iostream>

template<typename T>
class Array_Base
{
public:
    /// Type definition of the element type.
    typedef T type;

    /// Default Constructor
    Array_Base(void);

    // Init constructor
    Array_Base(size_t length);
    
    // FIll constructor
    Array_Base(size_t length, T fill);

    /// Destructor
    ~Array_Base(void);

    /**
     * Retrieve the current size of the data structure.
     *
     * @return          The current size
     */
    size_t size(void) const;

    /**
     * Retrieve the maximum size of the data structure.
     *
     * @return          The maximum size
     */
    size_t max_size(void) const;

    /**
     * Get the character at the specified index. If the index is not
     * within the range of the data structure, then std::out_of_range exception
     * is thrown.
     *
     * @param[in]       index               Zero-based location
     * @exception       std::out_of_range   Invalid \a index value
     */
    T & operator [] (size_t index);

    /**
     * @overload
     *
     * The returned character is not modifiable.
     */
    const T & operator [] (size_t index) const;   

    /**
     * Get the character at the specified index. If the \a index is not within
     * the range of the data structure, then std::out_of_range exception is thrown.
     *
     * @param[in]       index                 Zero-based location
     * @return          Character at \index
     * @exception       std::out_of_range     Invalid index value
     */  
    T get (size_t index) const;

    /** 
     * Set the character at the specified \a index. If the \a index is not
     * within range of the data structure, then std::out_of_range exception is 
     * thrown.
     *
     * @param[in]       index                 Zero-based location
     * @param[in]       value                 New value for character
     * @exception       std::out_of_range     Invalid \a index value
     */
    void set (size_t index, T value); 

    /**
     * Locate the specified character in the data structure. The index of the first
     * occurrence of the character is returned. If the character is not
     * found in the data structure, then -1 is returned.
     *
     * @param[in]        ch        Character to search for
     * @return           Index value of the character
     * @retval           -1        Character not found
     */
    int find (T element) const;

    /**
     * @overload
     *
     * This version allows you to specify the start index of the search. If
     * the start index is not within the range of the data structure, then the
     * std::out_of_range exception is thrown.
     *
     * @param[in]       ch                   Character to search for
     * @param[in]       start                Index to begin search
     * @return          Index value of first occurrence
     * @retval          -1                   Character not found
     * @exception       std::out_of_range    Invalid index
     */
    int find (T element, size_t start) const;

    /**
     * Test the data structure for equality.
     *
     * @param[in]       rhs                  Right hand side of equal to sign
     * @retval          true                 Left side is equal to right side
     * @retval          false                Left side is not equal to right side
     */
    bool operator == (const Array_Base & rhs) const;

    /**
     * Test the data structure for inequality.
     *
     * @param[in]       rhs                  Right-hand size of not equal to sign
     * @retval          true                 Left side is not equal to right side
     * @retval          false                Left size is equal to right side
     */
    bool operator != (const Array_Base & rhs) const;

    /**
     * Fill the contents of the data structure.
     *
     * @param[in]       ch                   Fill character
     */
    void fill (T element);


protected:
    T * data_;
    size_t cur_size_;
    size_t max_size_;
};

#include "Array_Base.inl"
#include "Array_Base.cpp"

#endif
