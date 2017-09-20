// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here

#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>



// TODO: object declarations your program requires here

template <class Elem = std::string>
struct Node
{
	Elem element;
	Node<Elem> *next;
};

template <class Elem = std::string>
class List
{
public:
	List();
	size_t Length() const;
	void Insert(Elem, size_t);
	Elem Delete(Node<Elem> *);
	void Traversal(void (*process)(List<Elem> *, Node<Elem> *));
	void Traversal(void (*process)(Node<Elem> *, std::string&), Elem *) const;
	~List();

private:
	Node<Elem> *first;

};

template <class Elem = std::string>
void Filter(List<Elem> *, Node<Elem> *);

template <class Elem = std::string>
void Extract(Node<Elem> *, std::string&);
