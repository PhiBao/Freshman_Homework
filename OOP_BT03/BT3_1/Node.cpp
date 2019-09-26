#include "Node.h"
Node::Node(NhanVien data)
{
	this->data = data;
}
Node::~Node()
{
}
void Node::print()
{
	cout << this->data << endl;
}