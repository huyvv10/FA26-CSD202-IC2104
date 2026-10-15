#include <iostream>
#include <queue>

using namespace std;
class Node{
	public:
		int data, height;
		Node *left, *right;
		Node (int _data):
			data(_data), height(1), left(nullptr), right(nullptr) {}	
};

class AVLTree{
	public:
		Node* root;
		AVLTree(){
			this->root=nullptr;
		}
			//AVLTree(): root(nullptr){}
		~AVLTree(){
			queue<Node *> myQ;
			myQ.push(root);				//enqueue
			while (!myQ.empty()) {
				Node *p = myQ.front();
				myQ.pop();				//dequeue
				Node *tmp=p;
				if (p->left!=nullptr)
					myQ.push(p->left);
				if (p->right!=nullptr)
					myQ.push(p->right);
				delete tmp;
			}		
		}
		
		bool isEmpty(){
			return root==nullptr;
		}
		
		int getHeight(Node* p){
			if (p==nullptr) return 0;
			return p->height;
		}
		
		int getBalanceInfo(Node* p){
			if (p==nullptr) return 0;
			return getHeight(p->left) - getHeight(p->right);
		}
		
		Node* rightRotate(Node* p){
			if (p==nullptr) return nullptr;
			Node* k = p->left;
			p->left = k->right;
			k->right = p;
			//Update height
			p->height = max(getHeight(p->left), getHeight(p->right))+1;
			k->height = max(getHeight(k->left), getHeight(k->right))+1;
			return k;
		}
		
		Node* leftRotate(Node* p){
			if (p==nullptr) return nullptr;
			Node* k = p->right;
			p->right = k->left;
			k->left = p;
			//Update height
			p->height = max(getHeight(p->left), getHeight(p->right))+1;
			k->height = max(getHeight(k->left), getHeight(k->right))+1;
			return k;
		}
		
		Node* insertAVLNode(Node* root, int x){
			Node* newNode = new Node(x);
			if (root==nullptr) return newNode;
			if (x < root->data){
				root->left = insertAVLNode(root->left, x);
			} else if (x > root->data){
				root->right = insertAVLNode(root->right, x);
			} else {
				return root;
			}
			
			//Update height
			root->height = max(getHeight(root->left), getHeight(root->right))+1;
			//Calculate balance factor?
			int balanceFactor = getBalanceInfo(root);
			//Case 1:
			if (balanceFactor>1 && x<root->left->data)
				return rightRotate(root);
			//Case 2:
			if (balanceFactor>1 && x>root->left->data){
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}	
			//Case 3:
			if (balanceFactor<-1 && x>root->right->data)
				return leftRotate(root);
			//Case 4:
			if (balanceFactor<-1 && x<root->right->data){
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
			return root;	
		}
		
		void visit(Node *p) {
			if (isEmpty()) return;
			cout<<p->data<<" ";
		}		
		//Breadth first traversal
		void breadthFirstTraversal() {
			if (root==nullptr) return;
			queue<Node *> myQ;			//enqueue
			myQ.push(root);
			while (!myQ.empty()) {
				Node *p = myQ.front();
				visit(p);
				myQ.pop();				//dequeue
				if (p->left!=nullptr) myQ.push(p->left);
				if (p->right!=nullptr) myQ.push(p->right);
			}
		}	
		
		Node* findTheRightMostNode(Node* p) {
			if (p==nullptr) return nullptr;
			Node *cur=p->left;
			if (cur->right ==nullptr) return cur;
			while (cur->right!=nullptr) {
				cur=cur->right;
			}
			return cur;
		}

		Node* deleteByCopying(Node *root, int x) {
			if (root==nullptr) return nullptr;
			if (x < root->data) {
				root->left=deleteByCopying(root->left, x);
			} else if (x > root->data) {
				root->right=deleteByCopying(root->right, x);
			} else {
				//Case1: deleted node is a leaf node
				if (root->left==nullptr && root->right==nullptr) {
					delete root;
					return nullptr;
				}
				//Case2: has a left subtree
				if (root->right==nullptr) {
					Node *tmp = root->left;
					delete root;
					return tmp;
				}
				//Case3: has a right subtree
				if (root->left==nullptr) {
					Node* tmp = root->right;
					delete root;
					return tmp;
				}
				//Case4: has two children
				if (root->left!=nullptr && root->right!=nullptr) {
					Node* copyNode = findTheRightMostNode(root);
					root->data = copyNode->data;
					root->left = deleteByCopying(root->left, copyNode->data);
				}
			}
			root->height = max(getHeight(root->left), getHeight(root->right))+1;
			int balanceFactor = getBalanceInfo(root);
			//Case 1:
			if (balanceFactor>1 && getBalanceInfo(root->left)>=0)
				return rightRotate(root);
			//Case 2: 
			if (balanceFactor>1 && getBalanceInfo(root->left)<0){
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}	
			//Case 3: 
			if (balanceFactor<-1 && getBalanceInfo(root->right)<=0)
				return leftRotate(root);
			//Case 4:
			if (balanceFactor<-1 && getBalanceInfo(root->right)>0){
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}	
			return root;
		}			
};

int main(){
	AVLTree myAVL;
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 20);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 10);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 6);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 30);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 35);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 40);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 17);
	myAVL.root = myAVL.insertAVLNode(myAVL.root, 19);
//	myAVL.root = myAVL.insertAVLNode(myAVL.root, 40);
	myAVL.breadthFirstTraversal();
	cout<<"\n---Delete by copying---"<<endl;
	myAVL.root = myAVL.deleteByCopying(myAVL.root, 30);
//	myAVL.root = myAVL.deleteByCopying(myAVL.root, 6);
	myAVL.breadthFirstTraversal();

	return 0;
}
