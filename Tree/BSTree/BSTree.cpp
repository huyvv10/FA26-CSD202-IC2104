#include <iostream>
#include <queue>

using namespace std;

class Node{
	public:
		int data;
		Node *left, *right;
		Node() : data(0), left(nullptr), right(nullptr){}
		Node(int _data) : data(_data), left(nullptr), right(nullptr){}
};

class BSTree{
	public:
		Node *root;
		
		BSTree() : root(nullptr) {}
		~BSTree() {}
		
		bool isEmpty(){
			return root==nullptr;
		}
		
		Node *addNode(int x){
			Node *newNode = new Node(x);
			if (isEmpty()){
				root=newNode; return root;
			}
			Node *cur=root;
			while (cur!=nullptr){
				if (x==cur->data) {
					cout<<x<<" already existed."<<endl; break;
				}
				if (x < cur->data){
					if (cur->left==nullptr){
						cur->left=newNode; break;
					} else {
						cur=cur->left;
					}
				} else {
					if (cur->right==nullptr){
						cur->right=newNode; break;
					} else {
						cur=cur->right;
					}
				}
			}
			return root;
		}
		
		void visit(Node *p){
			if (p!=nullptr)
				cout<<p->data<<" ";
		}
		
		//GLR
		void preOrder(Node *root){
			if (root==nullptr) return;
			visit(root);										//Visit Root
			if (root->left!=nullptr) preOrder(root->left);		//Visit Left
			if (root->right!=nullptr) preOrder(root->right);	//Visit Right
		}
		
		//Left -> Root -> Right
		void inOrder(Node *root){
			if (root==nullptr) return;
			if (root->left!=nullptr) inOrder(root->left);		//Visit Left
			visit(root);										//Visit Root
			if (root->right!=nullptr) inOrder(root->right);		//Visit Right			
		}
		
		//Left -> Right -> Root
		void postOrder(Node *root){
			if (root==nullptr) return;
			if (root->left!=nullptr) postOrder(root->left);		//Visit Left
			if (root->right!=nullptr) postOrder(root->right);		//Visit Right			
			visit(root);										//Visit Root
		}
		
		//Breadth first traversal
		void breadthFirstTraversal(){
			if (root==nullptr) return;
			queue<Node *> myQ;			//enqueue
			myQ.push(root);
			while (!myQ.empty()){
				Node *p = myQ.front();	
				visit(p);
				myQ.pop();				//dequeue
				if (p->left!=nullptr) myQ.push(p->left);
				if (p->right!=nullptr) myQ.push(p->right);				
			}
		}
		
		//Return number of nodes within the treee
		int countNodes(){
			int count=0;
			if (root==nullptr) return count;
			queue<Node *> myQ;			//enqueue
			myQ.push(root);
			while (!myQ.empty()){
				Node *p = myQ.front();	
				count++;
				myQ.pop();				//dequeue
				if (p->left!=nullptr) myQ.push(p->left);
				if (p->right!=nullptr) myQ.push(p->right);				
			}
			return count;
		}
		
		//Return number of Internal nodes within the treee
		int countInternalNodes(){
			int count=0;
			if (root==nullptr) return count;
			queue<Node *> myQ;			//enqueue
			myQ.push(root);
			while (!myQ.empty()){
				Node *p = myQ.front();	
				if (p->left!=nullptr || p->right!=nullptr) count++;
				myQ.pop();				//dequeue
				if (p->left!=nullptr) myQ.push(p->left);
				if (p->right!=nullptr) myQ.push(p->right);				
			}
			return count;
		}
		//Helper for count leaf nodes
		int countExternalRecursive(Node *p){
			int c=0, l=0, r=0;
			if (p==nullptr) return 0;
			if (p->left==nullptr && p->right==nullptr) c++;
			if (p->left!=nullptr) 
				l = countExternalRecursive(p->left);
			if (p->right!=nullptr)
				r = countExternalRecursive(p->right);
			return c+l+r;		
		}
		
		//Return number of leaf nodes within the treee
		int countExternalNodes(){
			return countExternalRecursive(root);
		}
		
		//Return number of nodes which have only a left child within the treee
		int countNodesOnlyHasLeftChild(){
			int count=0;
			if (root==nullptr) return count;
			queue<Node *> myQ;			//enqueue
			myQ.push(root);
			while (!myQ.empty()){
				Node *p = myQ.front();	
				if (p->left!=nullptr && p->right==nullptr) count++;
				myQ.pop();				//dequeue
				if (p->left!=nullptr) myQ.push(p->left);
				if (p->right!=nullptr) myQ.push(p->right);				
			}
			return count;
		}
		
		//Return number of nodes which have only a right child within the treee
		int countNodesOnlyHasRightChild(){
			int count=0;
			if (root==nullptr) return count;
			queue<Node *> myQ;			//enqueue
			myQ.push(root);
			while (!myQ.empty()){
				Node *p = myQ.front();	
				if (p->left==nullptr && p->right!=nullptr) count++;
				myQ.pop();				//dequeue
				if (p->left!=nullptr) myQ.push(p->left);
				if (p->right!=nullptr) myQ.push(p->right);				
			}
			return count;
		}
		
		//Return number of nodes which have two children within the treee
		int countNodesWithTwoChildren(){
			int count=0;
			if (root==nullptr) return count;
			queue<Node *> myQ;			//enqueue
			myQ.push(root);
			while (!myQ.empty()){
				Node *p = myQ.front();	
				if (p->left!=nullptr && p->right!=nullptr) count++;
				myQ.pop();				//dequeue
				if (p->left!=nullptr) myQ.push(p->left);
				if (p->right!=nullptr) myQ.push(p->right);				
			}
			return count;
		}
		
		
		
};

int main(){
	BSTree myBST;
	myBST.root=myBST.addNode(10);
	myBST.root=myBST.addNode(6);
	myBST.root=myBST.addNode(15);
	myBST.root=myBST.addNode(2);
	myBST.root=myBST.addNode(7);
	myBST.root=myBST.addNode(5);
	myBST.root=myBST.addNode(12);
	myBST.root=myBST.addNode(13);
	cout<<"--- PreOrder ---"<<endl;
	myBST.preOrder(myBST.root);
	cout<<"\n--- InOrder ---"<<endl;
	myBST.inOrder(myBST.root);
	cout<<"\n--- PostOrder ---"<<endl;
	myBST.postOrder(myBST.root);
	cout<<"\n--- BFS ---"<<endl;
	myBST.breadthFirstTraversal();
	cout<<"\nNumber of nodes: "<<myBST.countNodes()<<endl;
	cout<<"Number of Internal nodes: "<<myBST.countInternalNodes()<<endl;
	cout<<"Number of External nodes: "<<myBST.countExternalNodes()<<endl;
	cout<<"Number of nodes only has a left child: "<<myBST.countNodesOnlyHasLeftChild()<<endl;
	cout<<"Number of nodes only has a right child: "<<myBST.countNodesOnlyHasRightChild()<<endl;
	cout<<"Number of nodes with two children: "<<myBST.countNodesWithTwoChildren()<<endl;
	return 0;
}
