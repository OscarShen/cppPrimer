#pragma once
#ifndef ex13_book_h
#define ex13_book_h

#include <string>
#include <allocators>
class StrVec
{
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec &operator=(const StrVec&);
	~StrVec() { free(); }
	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }
private:
	std::allocator<std::string> alloc;
	// check the capacity
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void reallocate();
	void free();

	std::string *elements; // point to first element
	std::string *first_free; // point to first-free element
	std::string *cap; // point to element after last	


};
#endif // !ex13_book_h
