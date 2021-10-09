#pragma once
#include "BaseArray.h"

template <class t>
class OrderedArray : public Array<t>
{
private:
	bool duplicate = false;
	bool allow;
public:
	OrderedArray(int size, bool allowDuplicate, int growBy = 1) : Array<t>(size, growBy), allow(allowDuplicate)
	{
	};

	~OrderedArray() {};


	void push(t val) override
	{
		assert(this->m_array != nullptr);
		if (this->m_numElements >= this->m_maxSize)
		{
			if (allow || search(val) < 0)
				this->Expand();
		}

		int i, k;

		for (i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] > val)
				break;
		}

		if (!allow)
		{
			if (search(val) < 0)
				duplicate = false;
			else
			{
				duplicate = true;
				std::cout << std::endl << " >>> You've entered number "<< val << " more than once, therefore, duplicates were deleted <<<" << std::endl << std::endl;
			}
		}
		if (!duplicate || allow)
		{
			for (k = this->m_numElements; k > i; k--)
			{
				this->m_array[k] = this->m_array[k - 1];
			}

			this->m_array[i] = val;

			this->m_numElements++;
		}

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