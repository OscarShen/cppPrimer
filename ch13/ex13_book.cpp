#include "ex13_book.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

Message::Message(const Message &m):contents(m.contents),folders(m.folders)
{
	add_to_Folders(m);
	cout << "Message " << m.contents << " add to folders: ";
	for (auto f : m.folders)
		cout << f->name << ",";
	cout << endl;
}

Message & Message::operator=(const Message &rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
	cout << this->contents << " is added to " << f.name;
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
	cout << this->contents << " is deleted from " << f.name;
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

Folder::Folder(const std::string name):name(name)
{
	cout << "folder " << name << " is build" << endl;
}

void Folder::addMsg(Message *m)
{
	messages.insert(m);
	cout << this->name << " add message " << m->contents << endl;
}

void Folder::remMsg(Message *m)
{
	messages.erase(m);
	cout << this->name << " erase message " << m->contents << endl;
}

Folder::~Folder()
{
	remove_from_Messages();
}

void Folder::remove_from_Messages()
{
	for (auto m : messages)
		m->folders.erase(this);
}