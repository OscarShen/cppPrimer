#pragma once


#ifndef ex7_15_h
#define ex7_15_h
#include <string>

class Person {
	std::string name;
	std::string address;

	Person() :name("name is null!"), address("address is null!") {}
	Person(std::string name, std::string address) :name(name), address(address) {}

public:
	const std::string& getName() const { return name; }
	const std::string& getAddress() const { return address; }
};
#endif // !ex7_15_h
