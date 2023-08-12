#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

template <typename T>
class MyVectorTParent
{
protected:
	std::vector<T> m_myVector;
public:
	MyVectorTParent(std::vector<T> myVector) : m_myVector(myVector)
	{
	}

	virtual void ShowMyVector() = 0;
	virtual bool PairwiseComparison() = 0;
};


template <typename T>
class MyVectorT : public MyVectorTParent<T>
{

public:
	MyVectorT(std::vector<T> myVector) : MyVectorTParent<T>(myVector)
	{
	}
	void ShowMyVector();
	bool PairwiseComparison();
	void ModifyMyVector(std::function<T(T)> myLambda);

};

template<typename T>
void MyVectorT<T>::ShowMyVector()
{
	for (const auto& el : this->m_myVector)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

template<typename T>
bool MyVectorT<T>::PairwiseComparison()
{
	//m_myVector.
	auto it = std::adjacent_find(this->m_myVector.begin(), this->m_myVector.end());
	if (it != this->m_myVector.end())
	{
		return true;
	}
	return false;
}

template<typename T>
void MyVectorT<T>::ModifyMyVector(std::function<T(T)> myLambda)
{
	std::transform(this->m_myVector.begin(), this->m_myVector.end(), this->m_myVector.begin(), myLambda);
}


//template <>
//class MyVectorT<std::string> : public MyVectorTParent<std::string>
//{
//
//public:
//	MyVectorT(std::vector<std::string> myVector) : MyVectorTParent<std::string>(myVector)
//	{
//	}
//	void ShowMyVector();
//	bool PairwiseComparison();
//	void ModifyMyVector(std::function<std::string(std::string)> myLambda);
//
//};