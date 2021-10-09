#pragma once
#include "BaseArray.h"

template <class t>
class OrderedArray : public Array<t>
{
private:

public:
	OrderedArray(int size, int growBy = 1) : Array<t>(size, growBy)
	{
	};

	~OrderedArray() {};


	void push(t val) override
	{
		assert(this->m_array != nullptr);
		if (this->m_numElements >= this->m_maxSize)
		{
				this->Expand();
		}

		int i, k;

		for (i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] > val)
				break;
		}

		
			for (k = this->m_numElements; k > i; k--)
			{
				this->m_array[k] = this->m_array[k - 1];
			}

			this->m_array[i] = val;

			this->m_numElements++;	

	};

	int search(t searchKey) override
	{
		assert(this->m_array != nullptr);

		int lowerBound = 0;
		int upperBound = this->m_numElements - 1;
		int current = 0;

		while (1)
		{
			current = (lowerBound + upperBound) >> 1;

			if (this->m_array[current] == searchKey)
				return current;

			else if (lowerBound > upperBound)
				return -1;

			else
			{
				if (this->m_array[current] < searchKey)
					lowerBound = current + 1;
				else
					upperBound = current - 1;
			}
		}
		return -1;
	}
};