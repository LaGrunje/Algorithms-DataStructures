#pragma once

#include <iostream>
#include <stdexcept>

template<typename Iterator>
Iterator
binary_search(Iterator ItBegin, Iterator ItEnd, typename std::iterator_traits<Iterator>::value_type Element,
                                                                std::random_access_iterator_tag)
{
    if (ItBegin == ItEnd)
        return ItEnd;
    Iterator left = ItBegin;
    Iterator right = ItEnd;
    while (left < right - 1)
    {
        Iterator middle = left + ((right - left) >> 1);
        if (*(middle) < Element)
            left = middle;
        else
            right = middle;
    }
    if (*(right) == Element)
        return right;
    return ItEnd; 
}

template<typename Iterator>
Iterator
binary_search(Iterator ItBegin, Iterator ItEnd, typename std::iterator_traits<Iterator>::value_type Element,
                                                                std::bidirectional_iterator_tag)
{
    throw std::invalid_argument("Binary search can work only with random access containers.");
}

template<typename Iterator>
Iterator
bin_search(Iterator ItBegin, Iterator ItEnd, typename std::iterator_traits<Iterator>::value_type Element)
{
    return binary_search(ItBegin, ItEnd, Element, typename std::iterator_traits<Iterator>::iterator_category());
}

