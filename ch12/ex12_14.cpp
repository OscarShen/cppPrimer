#include <string>
#include <memory>
#include <iostream>
using namespace std;

struct destination
{
	string ip;
	int port;
	destination(string ip, int port) :ip(ip), port(port) {}
};

struct connection
{
	string ip;
	int port;
	connection(string ip, int port) :ip(ip), port(port) {}
};

connection connect(destination* dest) {
	shared_ptr<connection> conn(new connection(dest->ip, dest->port));
	cout << "create connection (" << conn.use_count() << ")" << endl;
	return *conn;
}

void disconnect(connection conn) {
	cout << "connection close(" << conn.ip << ":" << conn.port << ")" << endl;
}

void f(destination& d) {
	connection conn = connect(&d);
	shared_ptr<connection> p(&conn, [](connection *p) {disconnect(*p); });
	cout << "connection now(" << p.use_count() << ")" << endl;
}

int main() {
	destination dest("10.83.122.122", 3333);
	f(dest);
}