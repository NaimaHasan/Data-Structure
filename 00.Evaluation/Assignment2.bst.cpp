#include <stdio.h>

using namespace std;

struct node{
	int data;
	node *left, *right, *parent;

	node(int _data){
		data = _data;
		left = NULL;
		right = NULL;
		parent = NULL;
	}

	node(int _data, node *_parent){
		data = _data;
		left = NULL;
		right = NULL;
		parent = _parent;
	}

	node(){
		data = 0;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

struct BST{
	node *root;

	BST(){
		root = NULL;
	}

	node *search(int x){
		node *cur = root;
		
		while(cur != NULL){
			if(cur->data < x) cur = cur->right;
			else if(cur->data > x) cur = cur->left;
			else return cur;
		}

		return NULL;
	}

	void insert(int x){
		insert(root, x);
	}

	void insert(node *n, int data){
		if(root == NULL){
			root = new node(data);
			return;
		}
		if(data <= n->data){
			if(n->left == NULL){
				n->left = new node(data, n);
				return;
			}
			else{
				insert(n->left, data);
			}
		}

		else{
			if(n->right == NULL){
				n->right = new node(data, n);
				return;
			}
			else{
				insert(n->right, data);
			}
		}
	}

	node *upperBound(int x){
		node *ans = NULL, *cur = root;
	
		while(cur != NULL){
			if(cur->data <= x)
				cur = cur->right;
			else{
				ans = cur;
				cur = cur->left;
			}
		}

		return ans;
	}

	node *lowerBound(int x){
		node *ans = NULL, *cur = root;

		while(cur != NULL){
			if(cur -> data < x)
				cur = cur->right;
			else{
				ans = cur;
				cur = cur->left;
			}
		}

		return ans;
	}

	void deleteData(int x){
		node *temp = search(x);

		if(temp != NULL)
			deleteData(temp);
	}

	void deleteData(node *cur){
		if(cur->left == NULL && cur->right == NULL){
			if(cur != root){
				if(cur->parent->left == cur)
					cur->parent->left = NULL;
				else if(cur->parent->right == cur)
					cur->parent->right = NULL;
			}
			else{
				root = NULL;
			}
		}
		else if(cur->left == NULL || cur->right == NULL){
			if(cur != root){
				if(cur->left != NULL){
					if(cur->parent->left == cur){
						cur->parent->left = cur->left;
						cur->left->parent = cur->parent;
					}
					else if(cur->parent->right == cur){
						cur->parent->right = cur->left;
						cur->left->parent = cur->parent;
					}
				}
				else{
					if(cur->parent->left == cur){
						cur->parent->left = cur->right;
						cur->right->parent = cur->parent;
					}
					else if(cur->parent->right == cur){
						cur->parent->right = cur->right;
						cur->right->parent = cur->parent;
					}
				}
			}
			else{
				if(cur->left != NULL){
					root = cur->left;
					cur->left->parent = NULL;
				}
				else{
					root = cur->right;
					cur->right->parent = NULL;
				}
			}
		}
		else{
			node * temp = upperBound(cur->data);
			cur->data = temp->data;
			deleteData(temp);
		}
	}


	void insertNonRecursive(int x){
		node *cur = root;

		if(root == NULL){
			root = new node(x);
			return;
		}

		while(1){
			if(x <= cur->data){
				if(cur->left == NULL){
					cur->left = new node(x, cur);
					break;
				}
				else{
					cur = cur->left;
				}
			}
			else{
				if(cur->right == NULL){
					cur->right = new node(x, cur);
					break;
				}
				else{
					cur = cur->right;
				}
			}
		}
	}

	void inorderTraversal(node *toBePrinted){
		if(toBePrinted == NULL)
			return;

		inorderTraversal(toBePrinted->left);
		printf("%d ", toBePrinted->data);
		inorderTraversal(toBePrinted->right);
	}

	void inorderTraversal(){
		inorderTraversal(root);
		printf("\n");
	}
};


int main(){
	BST a;


	a.insert(18);
	a.insert(15);
	a.insert(13);
	a.insert(17);

	a.inorderTraversal();

	printf("\n\n");

	a.deleteData(18);

	a.inorderTraversal();

	return 0;
}
