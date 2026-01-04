#include "Span.hpp"
#include <exception>
#include <cstddef>
#include <climits>
#include <cstdlib>

Span::Span(){
	this->arr = NULL;
	this->buffer = 0;
	this->len = 0;
}

Span::Span(const unsigned int amount){
	this->arr = new int [amount];
	this->buffer = amount;
	this->len = 0;
}

Span::Span(const Span& other){
	*this = other;
}

Span::~Span(){
	delete [] arr;
}

Span& Span::operator=(const Span& obj){
	if (&obj == this)
		return (*this);

	delete[] this->arr;

	this->arr = new int [obj.buffer];
	this->buffer = obj.buffer;
	this->len = obj.len;

	for (unsigned int i = 0; i < this->len; i++){
		this->arr[i] = obj.arr[i];
	}
	return (*this);
}

void	Span::addNumber(const int number){
	if (len + 1 > buffer)
		throw std::exception();

	arr[len] = number;
	len ++;
}
	
int		Span::shortestSpan(void) const{
	if (len <= 1)
		throw std::exception();

	int min_diff = INT_MAX;

	for (unsigned int i = 0; i < len; ++i){
		for (unsigned int j = i + 1; j < len; ++j){
			int diff = std::abs(arr[i] - arr[j]);
			if (diff < min_diff)
				min_diff = diff;
		}
	}
	return min_diff;
}
	
int		Span::longestSpan(void) const{
	if (len <= 1)
		throw std::exception();

	int min_val = INT_MAX;
	int max_val = INT_MIN;

	for (unsigned int i = 0; i < len; ++i) {
		if (arr[i] < min_val) min_val = arr[i];
		if (arr[i] > max_val) max_val = arr[i];
	}
	return max_val - min_val;
}
