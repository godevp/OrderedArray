#pragma once
#include "BaseArray.h"

template <class t>
class UnorderedArray : public Array<t>
{
public:
	UnorderedArray(int size, int growBy = 1) : Array<t>(size, growBy) {};

	~UnorderedArray() {};

	void push(t val) override
	{
		assert(this->m_array != nullptr);

		if (this->m_numElements >= this->m_maxSize)
			this->Expand();


		this->m_array[this->m_numElements] = val;
		this->m_numElements++;
	};

	int search(t searchKey) override
	{
		assert(this->m_array != nullptr);

		for (int i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] == searchKey)
				return i;
		}
		return -1;
	}

};