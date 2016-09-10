#pragma once
#ifndef ex7_05_h
#define ex7_05_h

#include <string>

class Person {
	std::string name;
	std::string address;

public:
	const std::string& getName() const { return name; }
	const std::string& getAddress() const { return address; }
};
#endif // !ex7_05_h
