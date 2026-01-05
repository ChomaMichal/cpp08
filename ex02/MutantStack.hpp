#pragma once
#include <cstddef>
#include <stdexcept>


template <typename T>
class MutantStack{

	struct linked_list{
		T					val;
		struct linked_list *next;
	};
	
	private:
		linked_list *head;
		size_t	len;


	public:
		MutantStack():head(NULL), len(0){};
		MutantStack(const MutantStack&other){
			*this = other;
		}

		~MutantStack(){
			this->clear();
		};

		MutantStack &operator=(const MutantStack &other){
			if (this == &other) return *this;
			clear();
			linked_list *curr = other.head;
			linked_list **tail = &this->head;
			while (curr) {
				*tail = new linked_list;
				(*tail)->val = curr->val;
				(*tail)->next = NULL;
				tail = &((*tail)->next);
				curr = curr->next;
				len++;
			}
			return *this;
		}
			
		void	clear(void){
			this->len = 0;
			while (this->head){
				linked_list *tmp = this->head;
				this->head  = this->head->next;
				delete tmp;
			}
		};

		bool	empty(void) const{
			if (this->head == NULL) return false;
			else return (true);
		}

		size_t	size(void) const{
			return this->len;
		}

		T& top(void){
			if (this->head == NULL)
				throw std::invalid_argument("can't check top of empty stack");
			return (head->val);
		}

		const T& top(void) const{
			if (this->head == NULL)
				throw std::invalid_argument("can't check top of empty stack");
			return (head->val);
		}

		void	push(const T& value){
			linked_list *tmp = new linked_list;
			tmp->val = value;
			tmp->next = this->head;
			this->head = tmp;
			len ++;
		}

		void	pop(void){
			if (this->head == NULL)
				throw std::invalid_argument("can't pop empty stack");
			linked_list *tmp = this->head;
			this->head = this->head->next;
			delete tmp;
			len --;
		}

		void	swap(MutantStack& other){
			size_t		tmplen = other.len;
			linked_list	*tmplist = other.head;

			other.head = this->head;
			other.len = this->len;

			this->head = tmplist;
			this->len = tmplen;
		}

		class iterator {
		private:
			linked_list* node;

		public:
			iterator(linked_list* ptr = NULL) : node(ptr) {}

			T& operator*() {
				return (this->node->val);
			}

			T* operator->() {
				return (&this->node->val);
			}

			iterator& operator++() {
				this->node = this->node->next;
				return (*this);
			}

			iterator operator++(int) {
				iterator rt = *this;
				++ *this;
				return (rt);
			}

			bool operator==(const iterator& other) const {
				return (this->node == other.node);
			}

			bool operator!=(const iterator& other) const {
				return (this->node != other.node);
			}
		};

		class const_iterator {
		private:
			const linked_list* node;

		public:
			const_iterator(const linked_list* ptr = NULL) : node(ptr) {}

			const T& operator*() const {
				return (this->node->val);
			}

			const T* operator->() const {
				return (&this->node->val);
			}

			const_iterator& operator++() {
				this->node = this->node->next;
				return (*this);
			}

			const_iterator operator++(int) const {
				const_iterator rt = *this;
				++ *this;
				return (rt);
			}

			bool operator==(const const_iterator& other) const {
				return (this->node == other.node);
			}

			bool operator!=(const const_iterator& other) const {
				return (this->node != other.node);
			}
		};

		iterator begin() {
			return iterator(this->head);
		}

		iterator end() {
			return (iterator(NULL));
		}

		const_iterator begin() const {
			return const_iterator(this->head);
		}

		const_iterator end() const {
			return (const_iterator(NULL));
		}
};
