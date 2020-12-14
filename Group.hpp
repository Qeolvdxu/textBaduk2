#ifndef GROUP_HPP
#define GROUP_HPP

#include "Stone.hpp"

class Group
{
	private:
		Stone* stones;
		int size;
	public:
		Group(); 
		virtual ~Group();
};

#include "Group.cpp"

#endif
