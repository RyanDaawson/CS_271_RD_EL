#ifndef SET_H
#define SET_H

#include <iostream>
#include <string>

using namespace std;

template <class T> 
class Set
{
private:
	struct Node
	{
		T		item;
		Node 	*next;
	};
	