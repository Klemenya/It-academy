#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <functional>

template <typename T>
class MyTVector
{
private:

	T m_myVector;

public:

	MyTVector(T myVector) : m_myVector{ myVector }
	{
	}
	
	void ShowMyVector();

	void ModifyMyVector(std::function<int(int)> myLambda);

	bool PairwiseComparison();
	

};

template <>
class MyTVector<std::vector<std::string>>
{
private:
	std::vector<std::string> m_myVector;
public:
	MyTVector(std::vector<std::string> myVector) : m_myVector{ myVector }
	{
	}
	void ShowMyVector();
	void ModifyMyVector();
	bool PairwiseComparison();

};


template<typename T>
inline void MyTVector<T>::ShowMyVector()
{
	for (const auto& el : m_myVector)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

template<typename T>
inline void MyTVector<T>::ModifyMyVector(std::function<int(int)> myLambda)
{
	std::transform(m_myVector.begin(), m_myVector.end(), m_myVector.begin(), myLambda);
}

template<typename T>
inline bool MyTVector<T>::PairwiseComparison()
{
	auto it = std::adjacent_find(m_myVector.begin(), m_myVector.end());
	if (it != m_myVector.end())
	{
		return true;
	}
	return false;
}

inline void MyTVector<std::vector<std::string>>::ShowMyVector()
{
	for (const auto& str : m_myVector)
	{
		std::cout << str << std::endl;
	}
}

inline void MyTVector<std::vector<std::string>>::ModifyMyVector()
{
	for (auto& str : m_myVector)
	{
		std::transform(str.begin(), str.end(), str.begin(), std::toupper);
	}
	
}

inline bool MyTVector<std::vector<std::string>>::PairwiseComparison()
{
	auto it = std::adjacent_find(m_myVector.begin(), m_myVector.end());
	if (it != m_myVector.end())
	{
		return true;
	}
	return false;
}
