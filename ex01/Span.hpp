#pragma once

#include <iostream>

class Span {
public:
  Span();
  Span(const unsigned int amount);
  Span(const Span& obj);
  ~Span();

  Span& operator=(const Span& obj);

  void	addNumber(const int number);
  template <typename Iterator>
  void	addNumbers(Iterator start, Iterator end){
		for (; start != end; ++start){
			this->addNumber(*start);
		}
  }
  int	shortestSpan(void) const;
  int	longestSpan(void) const;

private:
  int			*arr;
  unsigned int	buffer;
  unsigned int	len;
};
