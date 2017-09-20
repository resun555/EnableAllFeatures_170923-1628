// stdafx.cpp : source file that includes just the standard includes
// $safeprojectname$.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

template <class Elem>
List<Elem>::List()
{
	first = new Node<Elem>;
	first->next = nullptr;
}


template <class Elem>
size_t List<Elem>::Length() const
{
	Node<Elem> *work = first->next;
	size_t count;
	for (count = 0; work != nullptr; count++, work = work->next)
	{
	}
	return count;
}


template <class Elem>
void List<Elem>::Insert(Elem element, size_t index)
{
	Node<Elem> *work = first;
	for (auto count = 0; work != nullptr && count < index - 1; work = work->next, count++)
	{
	}
	if (work == nullptr)
	{
		throw new std::exception("System.IndexOutOfRange");
	}
	else
	{
		Node<Elem> *node = new Node<Elem>;
		node->element = element;
		node->next = work->next;
		work->next = node;
	}
	return;
}


template <class Elem>
Elem List<Elem>::Delete(Node<Elem> *node)
{
	Node<Elem> *work = first;
	for (; work != nullptr && work->next != node; work = work->next)
	{
	}
	if (work == nullptr || work->next == nullptr)
	{
		throw new std::exception("System.NodeNotFound");
	}
	else
	{
		Elem element = node->element;
		work->next = node->next;
		delete node;
		return element;
	}
}


template <class Elem>
void List<Elem>::Traversal(void (*process)(List<Elem> *, Node<Elem> *))
{
	Node<Elem> *work = first;
	for (; work->next != nullptr; work = work->next)
	{
		(*process)(this, work->next);
	}
	return;
}


template <class Elem>
void List<Elem>::Traversal(void (*process)(Node<Elem> *, std::string&), Elem *names) const
{
	Node<Elem> *work = first->next;
	for (auto count = 0; work != nullptr; count++, work = work->next)
	{
		(*process)(work, names[count]);
	}
	return;
}


template <class Elem>
List<Elem>::~List()
{
	while (first != nullptr)
	{
		Node<Elem> *node = first;
		first = first->next;
		delete node;
	}
}


void Filter(List<> *list, Node<> *node)
{
	if (node->element.find("Disabled", 56) == std::string::npos)
	{
		try
		{
			list->Delete(node);
		}
		catch (const std::exception *e)
		{
			std::cerr << e->what();
		}
	}
	return;
}


void Extract(Node<> *work, std::string& FeatureName)
{
	std::istringstream *reader = new std::istringstream(work->element, std::ios::in | std::ios::_Nocreate);
	if (!*reader)
	{
		delete reader;
		throw new std::exception("System.NullReference");
	}
	*reader >> FeatureName;
	delete reader;
	return;
}

