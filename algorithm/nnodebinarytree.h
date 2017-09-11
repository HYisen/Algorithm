#pragma once

#include <memory>

namespace nnodebinarytree
{
	template <typename T>
	struct Node
	{
	public:
		std::unique_ptr<Node<T>> leftChild;
		std::unique_ptr<Node<T>> rightSibling;
		T content;
	};

	template<typename T>
	class Tree
	{
	public:
		std::weak_ptr<Node<T>> add(T orig);
		void del(std::weak_ptr<Node<T>> orig);
		void traverse(std::weak_ptr<Node<T>> orig, decltype([](T)->{}) method);
	private:
		std::unique_ptr<Node<T>> root = nullptr;
	};
	template<typename T>
	inline void Tree<T>::traverse(std::weak_ptr<Node<T>> orig, decltype([](T)->{}) method)
	{
		if (orig != nullptr)
		{
			traverse(orig->leftChild, method);
			traverse(orig->rightSibling, method);
		}
	}
}