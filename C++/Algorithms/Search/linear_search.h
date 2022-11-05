#include <iostream>

template <typename Iterator>
Iterator
linear_search(Iterator ItBegin, Iterator ItEnd, typename std::iterator_traits<Iterator>::value_type Elements)
{
    if (ItBegin == ItEnd)
        return ItEnd;
    for(Iterator it = ItBegin; it < ItEnd; ++it)
    {
        if( *(it) == Elements)
            return it;
    }
    return ItEnd;
}