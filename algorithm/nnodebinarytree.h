#pragma once

#include <memory>
#include <functional>

namespace nnodebinarytree
{
	template <typename T>
	class Node
	{
	public:
		Node(T cnt, std::shared_ptr<Node<T>> &&child = nullptr, std::shared_ptr<Node<T>> &&sibling = nullptr) :
			content(cnt), leftChild(child), rightSibling(sibling) {};
		T content;
		std::shared_ptr<Node<T>> leftChild;
		std::shared_ptr<Node<T>> rightSibling;
	};

	template<typename T>
	class Tree
	{
	public:
		std::shared_ptr<Node<T>> add(T orig);
		std::shared_ptr<Node<T>> addChild(T src, std::shared_ptr<Node<T>> trg);
		std::shared_ptr<Node<T>> addSibling(T src, std::shared_ptr<Node<T>> trg);
		void del(std::shared_ptr<Node<T>> orig);
		void traverse(std::shared_ptr<Node<T>> orig, std::function<void(T)> method);
		std::shared_ptr<Node<T>> getRoot();
	private:
		std::shared_ptr<Node<T>> root = std::make_shared<Node<T>>(0,nullptr,nullptr);
	};

	template<typename T>
	inline std::shared_ptr<Node<T>> Tree<T>::add(T orig)
	{

		return std::shared_ptr<Node<T>>();
	}

	template<typename T>
	inline std::shared_ptr<Node<T>> Tree<T>::addChild(T src, std::shared_ptr<Node<T>> trg)
	{
		trg->leftChild = std::make_shared<Node<T>>(src,nullptr,nullptr);
		return std::shared_ptr<Node<T>>(trg->leftChild);
	}

	template<typename T>
	inline std::shared_ptr<Node<T>> Tree<T>::addSibling(T src, std::shared_ptr<Node<T>> trg)
	{
		trg->rightSibling = std::make_shared<Node<T>>(src,nullptr,nullptr);
		return std::shared_ptr<Node<T>>(trg->rightSibling);
	}

	template<typename T>
	inline void Tree<T>::traverse(std::shared_ptr<Node<T>> orig, std::function<void(T)> method)
	{
		if (orig != nullptr)
		{
			method(orig->content);
			traverse(orig->rightSibling, method);
			traverse(orig->leftChild, method);
		}
	}
	template<typename T>
	inline std::shared_ptr<Node<T>> Tree<T>::getRoot()
	{
		return root;
	}
}