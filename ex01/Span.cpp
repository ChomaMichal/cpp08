#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <exception>

Span::Span() {
  this->arr = NULL;
  this->buffer = 0;
  this->len = 0;
}

Span::Span(const unsigned int amount) {
  this->arr = new int[amount];
  this->buffer = amount;
  this->len = 0;
}

Span::Span(const Span &other) {
  this->arr = NULL;
  this->buffer = 0;
  this->len = 0;
  *this = other;
}

Span::~Span() { delete[] arr; }

Span &Span::operator=(const Span &obj) {
  if (&obj == this)
    return (*this);

  delete[] this->arr;

  this->arr = new int[obj.buffer];
  this->buffer = obj.buffer;
  this->len = obj.len;

  std::copy(obj.arr, obj.arr + obj.len, this->arr);
  return (*this);
}

void Span::addNumber(const int number) {
  if (len + 1 > buffer)
    throw std::exception();

  arr[len] = number;
  len++;
}

int Span::shortestSpan(void) const {
  if (len <= 1)
    throw std::exception();

  Span tmp = *this;
  int min_diff = INT_MAX;
  std::sort(tmp.arr, tmp.arr + len);
  for (size_t i = 0; i < tmp.len - 1; i++) {
    int hehe = tmp.arr[i + 1] - tmp.arr[i];
    if (min_diff > hehe)
      min_diff = hehe;
  }
  return min_diff;
}

int Span::longestSpan(void) const {
  if (len <= 1)
    throw std::exception();
  int max = *std::max_element(this->arr, this->arr + len);
  int min = *std::min_element(this->arr, this->arr + len);
  return (max - min);
}
