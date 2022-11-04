#pragma once

#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename Iterator, typename Comparator>
void bubble_sort(Iterator ItBegin, Iterator ItEnd, Comparator Comp,
                 std::forward_iterator_tag) {
  throw std::invalid_argument(
      "This function cannot work with this type of iterator;");
}

template <typename Iterator, typename Comparator>
void bubble_sort(Iterator ItBegin, Iterator ItEnd, Comparator Comp,
                 std::bidirectional_iterator_tag) {
  if (ItBegin == ItEnd)
    return;
  for (Iterator size = ItBegin; size < ItEnd - 1; ++size) {
    for (Iterator it = ItBegin; it < ItEnd - 1; ++it) {
      if (Comp(*(it + 1), *(it)))
        std::swap(*(it + 1), *it);
    }
  }
}

template <typename Iterator, typename Comparator>
void bubble_sort(Iterator ItBegin, Iterator ItEnd, Comparator Comp) {
  bubble_sort(ItBegin, ItEnd, Comp,
              typename std::iterator_traits<Iterator>::iterator_category());
}