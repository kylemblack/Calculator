#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MAX_SIZE 255

#include <exception>
#include "Array_Base.h"

template <typename T>
class Queue
{
public:
    typedef T type;

    /**
     * @class empty_exception
     *
     * Exception thrown to indicate the queue is empty.
     */
    class empty_exception : public std::exception
    {
    public:
        /// Default constructor.
    empty_exception (void)
      : std::exception () { std::cout << "Error: Empty queue." << std::endl; }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
      : std::exception (msg) {}
    };

    /// Default Constructor
    Queue (void);

    /// Copy Constructor
    Queue (const Queue & q);

    /// Destructor
    ~Queue (void);

    /**
     * Assignment operator
     *
     * @param[in]      rhs           Right-hand side of operator
     * @return         Reference to self
     */
    const Queue & operator = (const Queue & rhs);

    /**
     * Place a new \a element into the queue. The element is inserted
     * after all other elements in the list.
     * 
     * @param[in]      element       Element to be added to the list
     */
    void enqueue (T element);

    /**
     * Remove the first element from the queue.
     *
     * @exception      empty_exception    The queue is empty.
     */
    T dequeue (void);

    /**
     * Test if the queue is empty
     *
     * @retval         true          The queue is empty
     * @retval         false         The queue is not empty
     */
    bool is_empty (void) const;

    /**
     * Number of elements in the queue.
     *
     * @return         Size of the queue.
     */
    size_t size (void) const;

    /// Remove all elements from the queue.
    void clear (void);

private:
  Array <T> base_;
};

#include "Queue.inl"
#include "Queue.cpp"

#endif
