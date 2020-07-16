#include <iostream>
#include <string>
#include <string.h>

using std::cout;
using std::cin;
using std::string;

template <class Data>
struct Node{
	Data *data;
	Node *left, *right;
	Node(Data *data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

template<class Data>
class BST{
	Node<Data> *root;
	void addNodePrivate(Node<Data> *node, Node<Data> *tempRoot){
		if (tempRoot == NULL){
			this->root = node;
		} 
		else{
			if (node->data->getID() <= tempRoot->data->getID()){
				if (tempRoot->left != NULL){
					addNodePrivate(node,tempRoot->left);
				}
				else{
					tempRoot->left = node;
				}
			}		
			if (node->data->getID() > tempRoot->data->getID()){
				if (tempRoot->right != NULL){
					addNodePrivate(node,tempRoot->right);
				}
				else{
					tempRoot->right = node;
				}
			}
		}
	}
	void printTreePrivate(Node<Data> *tempRoot){
		if (this->root != NULL){
			cout << "Root:"<< tempRoot->data->getName() << "\n";
			if (tempRoot->left != NULL){
				cout << "Left of " << tempRoot->data->getName() <<" :"<<"\n";
				tempRoot->left->data->str();
				printTreePrivate(tempRoot->left);
			}
			if (tempRoot->right != NULL){
				cout << "Right of " << tempRoot->data->getName() <<" :"<<"\n";
				tempRoot->right->data->str();
				printTreePrivate(tempRoot->right);
			}
		}
		else{
			cout << "The tree is empty.\n";
		}
	}
	Node<Data> *searchNodePrivate(int data, Node<Data> *tempRoot){
		if (tempRoot != NULL){
			if (tempRoot->data->getID() == data){
				return tempRoot;
			}
			else{
				if(data <= tempRoot->data->getID()){
					return searchNodePrivate(data, tempRoot->left);
				}
				else{
					return searchNodePrivate(data, tempRoot->right);
				}
			}
		}
		else{
			return NULL;
		}
	}
	Node<Data> *findMin(Node<Data> *node){
		Node<Data> *cur = node;
		while(cur && cur->left != NULL){
			cur = cur->left;
		}
		return cur;
	}
	Node<Data> *removeNodePrivate(Node<Data> *node, int data){
		if(node == NULL){
			return node;
		}
		if(node->data->getID() < data){
			return removeNodePrivate(node->right,data);
		}
		else if(node->data->getID() > data){
			return removeNodePrivate(node->left, data);
		}
		else{
			if (node->left == NULL){
				Node<Data> *temp = node->right; 
				free(node); 
				return temp; 
			}
			else if (node->right == NULL){
				Node<Data> *temp = node->left; 
				free(node); 
				return temp; 
			}  
			Node<Data> *temp = findMin(node->right);
			node->data = temp->data;  
			node->right = removeNodePrivate(node->right, temp->data->getID()); 
		} 
		return node; 
	}
	void modifiedTree(Node<Data> *node, Node<Data> *tempRoot, int ID){
		if (node->data->getID() <= tempRoot->data->getID()){
			if (tempRoot->left->data->getID() != ID){
				modifiedTree(node,tempRoot->left,ID);
			}
			else{
				tempRoot->left = node;
			}
		}		
		if (node->data->getID() > tempRoot->data->getID()){
			if (tempRoot->right->data->getID() != ID){
				modifiedTree(node,tempRoot->right,ID);
			}
			else{
				tempRoot->right = node;
			}
		}
	}
	public:
		BST(){
			this->root = NULL;	
		}
		void addNode(Node<Data> *node){
			addNodePrivate(node, this->root);
		}
		void printTree(){
			printTreePrivate(this->root);
		}		
		Node<Data> *searchNode(int data){
			return searchNodePrivate(data,this->root);
		}
		void removeNode(int ID){
			Node<Data> *node = removeNodePrivate(this->root, ID);
			modifiedTree(node, this->root, ID);
		}
};
