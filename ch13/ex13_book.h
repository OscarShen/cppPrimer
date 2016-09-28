#pragma once
#ifndef ex13_book_h_
#define ex13_book_h_
#include <string>
#include <set>
class Message
{
	friend class Folder;
	friend void swap(Message &, Message &);
public:
	explicit Message(const std::string & str = "") :contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);

private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

class Folder 
{
	friend Message;
public:
	Folder(const std::string);
	void addMsg(Message*);
	void remMsg(Message*);
	~Folder();
private:
	std::set<Message*> messages;
	std::string name;
	void remove_from_Messages();
};

#endif // !ex13_book_h_
