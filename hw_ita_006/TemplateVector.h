#pragma once
#include <vector>
#include <iostream>

template <typename T>

class TemplateVector
{
private:

	T m_myVector;

public:

	TemplateVector(T myVector) : m_myVector{ myVector }
	{
	}

	void showVector()
	{
		for (auto& el : m_myVector)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;
	};

};

