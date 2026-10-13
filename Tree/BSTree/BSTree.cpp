#include <iostream>
#include <queue>

using namespace std;

class Node {
	public:
		int data;
		Node *left, *right;
		Node() : data(0), left(nullptr), right(nullptr) {}
		Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

class BSTree {
	public:
		Node *root;

		BSTree() : root(nullptr) {}
		~BSTree() {
			if (root==nullptr) return;
			queue<Node *> myQ;			//enqueue
			myQ.push(root);
			while (!myQ.empty()) {
				Node *p = myQ.front();
				myQ.pop();				//dequeue
				if (p->left!=nullptr) myQ.push(p->left);
				if (p->right!=nullptr) myQ.push(p->right);
				delete p;
			}
			root=nullptr;
		}

		bool isEmpty() {
			return root==nullptr;
		}

		Node *addNode(int x) {
			Node *newNode = new Node(x);
			if (isEmpty()) {
				root=newNode;
				return root;
			}
			Node *cur=root;
			while (cur!=nullptr) {
				if (x==cur->data) {
					cout<<x<<" already existed."<<endl;
					break;
				}
				if (x < cur->data) {
					if (cur->left==nullptr) {
						cur->left=newNode;
						break;
					} else {
						cur=cur->left;
					}
				} else {
					if (cur->right==nullptr) {
						cur->right=newNode;
						break;
					} else {
						cur=cur->right;
					}
				}
			}
			return root;
		}

		void visit(Node *p) {
			if (p!=nullptr)
				cout<<p->data<<" ";
		}

		//GLR
		void preOrder(Node *root) {
			if (root==nullptr) return;
			visit(root);										//Visit Root
			if (root->left!=nullptr) preOrder(root->left);		//Visit Left
			if (root->right!=nullptr) preOrder(root->right);	//Visit Right
		}

		//Left -> Root -> Right
		void inOrder(Node *root) {
			if (root==nullptr) return;
			if (root->left!=nullptr) inOrder(root->left);		//Visit Left
			visit(root);										//Visit Root
			if (root->right!=nullptr) inOrder(root->right);		//Visit Right
		}

		//Left -> Right -> Root
		void postOrder(Node *root) {
			if (root==nullptr) return;
			if (root->left!=nullptr) postOrder(root->left);		//Visit Left
			if (root->right!=nullptr) postOrder(root->right);		//Visit Right
			visit(root);										//Visit Root
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

		//Return number of nodes within the treee
		int countNodes() {
			int count=0;
			if (root==nullptr) return count;
			queue<Node *> myQ;			//enqueue
			myQ.push(root);
			while (!myQ.empty()) {
				Node *p = myQ.front();
				count++;
				myQ.pop();				//dequeue
				if (p->left!=nullptr) myQ.push(p->left);
				if (p->right!=nullptr) myQ.push(p->right);
			}
			return count;
		}

		//Return number of Internal nodes within the treee
		int countInternalNodes() {
			int count=0;
			if (root==nullptr) return count;
			queue<Node *> myQ;			//enqueue
			myQ.push(root);
			while (!myQ.empty()) {
				Node *p = myQ.front();
				if (p->left!=nullptr || p->right!=nullptr) count++;
				myQ.pop();				//dequeue
				if (p->left!=nullptr) myQ.push(p->left);
				if (p->right!=nullptr) myQ.push(p->right);
			}
			return count;
		}
		//Helper for count leaf nodes
		int countExternalRecursive(Node *p) {
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
		int countExternalNodes() {
			return countExternalRecursive(root);
		}

		//Return number of nodes which have only a left child within the treee
		int countNodesOnlyHasLeftChild() {
			int count=0;
			if (root==nullptr) return count;
			queue<Node *> myQ;			//enqueue
			myQ.push(root);
			while (!myQ.empty()) {
				Node *p = myQ.front();
				if (p->left!=nullptr && p->right==nullptr) count++;
				myQ.pop();				//dequeue
				if (p->left!=nullptr) myQ.push(p->left);
				if (p->right!=nullptr) myQ.push(p->right);
			}
			return count;
		}

		//Return number of nodes which have only a right child within the treee
		int countNodesOnlyHasRightChild() {
			int count=0;
			if (root==nullptr) return count;
			queue<Node *> myQ;			//enqueue
			myQ.push(root);
			while (!myQ.empty()) {
				Node *p = myQ.front();
				if (p->left==nullptr && p->right!=nullptr) count++;
				myQ.pop();				//dequeue
				if (p->left!=nullptr) myQ.push(p->left);
				if (p->right!=nullptr) myQ.push(p->right);
			}
			return count;
		}

		//Return number of nodes which have two children within the treee
		int countNodesWithTwoChildren() {
			int count=0;
			if (root==nullptr) return count;
			queue<Node *> myQ;			//enqueue
			myQ.push(root);
			while (!myQ.empty()) {
				Node *p = myQ.front();
				if (p->left!=nullptr && p->right!=nullptr) count++;
				myQ.pop();				//dequeue
				if (p->left!=nullptr) myQ.push(p->left);
				if (p->right!=nullptr) myQ.push(p->right);
			}
			return count;
		}

		//Return the node which has the maximum value of the left subtree
		Node* findTheRightMostNode(Node *p) {
			if (p==nullptr) return nullptr;
			Node* cur=p->left;
			if (cur->right==nullptr) return cur;
			while (cur->right!=nullptr) {
				cur=cur->right;
			}
			return cur;
		}

		//Copy the right most node of the left subtree
		Node* deleteByCopying(Node *xRoot, int x) {
			if (xRoot==nullptr) return nullptr;
			if (x < xRoot->data) {
				xRoot->left = deleteByCopying(xRoot->left, x);
			} else if (x > xRoot->data) {
				xRoot->right = deleteByCopying(xRoot->right, x);
			} else {
				//Case 1: leaf node
				if (xRoot->left == nullptr && xRoot->right == nullptr) {
					delete xRoot;
					return nullptr;
				}
				//Case 2: Only has a left child
				if (xRoot->right==nullptr) {
					Node* tmp=xRoot->left;
					delete xRoot;
					return tmp;
				}
				//Case 3: Only has a right child
				if (xRoot->left==nullptr) {
					Node* tmp=xRoot->right;
					delete xRoot;
					return tmp;
				}
				//Case 4: has two children
				if (xRoot->left!=nullptr && xRoot->right!=nullptr) {
					Node* copyNode = findTheRightMostNode(xRoot);
					xRoot->data = copyNode->data;
					xRoot->left = deleteByCopying(xRoot->left, copyNode->data);
				}
			}
			return xRoot;
		}

		//Merge the right most node of the left subtree
		//by the right subtree of deleted node
		Node* deleteByMerging(Node *xRoot, int x) {
			if (xRoot==nullptr) return nullptr;
			if (x < xRoot->data) {
				xRoot->left = deleteByMerging(xRoot->left, x);
			} else if (x > xRoot->data) {
				xRoot->right = deleteByMerging(xRoot->right, x);
			} else {
				//Case 1: leaf node
				if (xRoot->left == nullptr && xRoot->right == nullptr) {
					delete xRoot;
					return nullptr;
				}
				//Case 2: Only has a left child
				if (xRoot->right==nullptr) {
					Node* tmp=xRoot->left;
					delete xRoot;
					return xRoot->left;
				}
				//Case 3: Only has a right child
				if (xRoot->left==nullptr) {
					Node* tmp=xRoot->right;
					delete xRoot;
					return xRoot->right;
				}
				//Case 4: has two children
				if (xRoot->left!=nullptr && xRoot->right!=nullptr) {
					Node* mergeNode = findTheRightMostNode(xRoot);
					mergeNode->right = xRoot->right;
					Node* tmp=xRoot->left;
					delete xRoot;
					return tmp;
				}
			}
			return xRoot;
		}

		//Return node the-K which has two children using Post Order Traversal
		Node* getNodeTheKTwoChildrenPostOrder(Node *p, int theK) {
//			if (root==nullptr) return;
//			if (root->left!=nullptr) postOrder(root->left);		//Visit Left
//			if (root->right!=nullptr) postOrder(root->right);		//Visit Right
//			visit(root);										//Visit Root
			return nullptr;
		}
};

int main() {
	BSTree myBST;
	myBST.root=myBST.addNode(11);
	myBST.root=myBST.addNode(6);
	myBST.root=myBST.addNode(15);
	myBST.root=myBST.addNode(2);
	myBST.root=myBST.addNode(9);
	myBST.root=myBST.addNode(5);
	myBST.root=myBST.addNode(12);
	myBST.root=myBST.addNode(13);
	myBST.root=myBST.addNode(1);
	myBST.root=myBST.addNode(0);
	myBST.root=myBST.addNode(8);
	myBST.root=myBST.addNode(10);
	myBST.root=myBST.addNode(25);
	myBST.root=myBST.addNode(20);
	myBST.root=myBST.addNode(27);
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
//	cout<<"---Delete by copying ---"<<endl;
//	myBST.root = myBST.deleteByCopying(myBST.root, 6);
//	myBST.breadthFirstTraversal();
	cout<<"---Delete by Merging ---"<<endl;
	myBST.root=myBST.deleteByMerging(myBST.root, 11);
	myBST.breadthFirstTraversal();
	cout<<"\n---Get node the-k ---"<<endl;
	cout<<myBST.getNodeTheKTwoChildrenPostOrder(myBST.root, 3)->data<<endl;

	return 0;
}
