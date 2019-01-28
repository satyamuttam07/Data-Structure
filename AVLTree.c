#include<stdio.h>
#include<stdlib.h>
struct AVLTree{
	int data,degree;
	struct AVLTree *left,*right;
};
struct AVLTree* insert(struct AVLTree* root, int num);
struct AVLTree* deletion(struct AVLTree* root, int num);
void display(struct AVLTree* root);
void inorder(struct AVLTree* root);
void preorder(struct AVLTree* root);
void postorder(struct AVLTree* root);
struct AVLTree* rotate_left(struct AVLTree* root);
struct AVLTree* rotate_right(struct AVLTree* root);
int smallest(struct AVLTree* root);
int largest(struct AVLTree* root);
int height(struct AVLTree* root);
int maximum(int a,int b);
int main(){
	struct AVLTree *root = NULL;
	while(1){
		int n,num;
		printf("Enter your option\n");
		printf("Press 0 to Exit\n");
		printf("Press 1 to Insert new Node in the Tree\n");
		printf("Press 2 to Delete the Node in the Tree\n");
		printf("Press 3 to Display All the Nodes in the Tree\n");
		scanf("%d",&n);
		switch(n){
			case 0:
				return 0;
			case 1:
				printf("Enter the value of new Node\n");
				scanf("%d",&num);
				root = insert(root, num);
				display(root);
				printf("Height : %d\n", height(root));
				display(root);
				break;
			case 2:
				printf("Enter the value to Node\n");
				scanf("%d",&num);
				root = deletion(root, num);
				printf("Height : %d\n", height(root));
				display(root);
				break;
			case 3:
				display(root);
				break;
			// case 4:
			// 	root = rotate_left(root);
			// 	break;
			// case 5:
			// 	root = rotate_right(root);
			// 	break;
			// case 6:
			// 	printf("%d\n",height(root));
			break;
			default:
				printf("Invalid Input\n");
		}
	}
	return 0;
}

struct AVLTree* insert(struct AVLTree* root, int num){
	if(root == NULL){
		struct AVLTree *temp = malloc(sizeof(struct AVLTree));
		temp->data = num;
		temp->degree = 0;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}else if(root->data < num){
		root->right = insert(root->right, num);
	}else{
		root->left = insert(root->left, num);
	}
	int left_height, right_height;
	left_height = height(root->left);
	right_height = height(root->right);
	root->degree = left_height - right_height;
	if(root->degree > 1){
		return rotate_right(root);
	}else if(root->degree < -1){
		return rotate_left(root);
	}
	return root;
}
struct AVLTree* deletion(struct AVLTree* root, int num){
	if(root == NULL){
		return root;
	}
	if(root->data == num){
		if(root->left == NULL && root->right == NULL){
			free(root);
			return NULL;
		}else if(root->left == NULL){
			int temp = smallest(root->right);
			root->data = temp;
			root->right = deletion(root->right, temp);
		}else{
			int temp = largest(root->left);
			root->data = temp;
			root->left = deletion(root->left, temp);
		}
	}else if(root->data < num){
		root->right = deletion(root->right, num);
	}else{
		root->left = deletion(root->left, num);
	}
	int left_height, right_height;
	left_height = height(root->left);
	right_height = height(root->right);
	root->degree = left_height - right_height;
	if(root->degree > 1){
		return rotate_right(root);
	}else if(root->degree < -1){
		return rotate_left(root);
	}
	return root;
}
void inorder(struct AVLTree* root){
	if(root == NULL){
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void preorder(struct AVLTree* root){
	if(root == NULL){
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct AVLTree* root){
	if(root == NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}
struct AVLTree* rotate_left(struct AVLTree* root){
	struct AVLTree* t;
	if(root->right == NULL){
		return root;
	}
	t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}
struct AVLTree* rotate_right(struct AVLTree* root){
	struct AVLTree* t;
	if(root->left == NULL){
		return root;
	}
	t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}
void display(struct AVLTree* root){
	printf("Nodes in the Tree (Inorder) : ");
	inorder(root);
	printf("\n");
	printf("Nodes in the Tree (Preorder) : ");
	preorder(root);
	printf("\n");
	printf("Nodes in the Tree (Postorder) : ");
	postorder(root);
	printf("\n");
}
int smallest(struct AVLTree* root){
	if(root == NULL){
		return 1000;
	}
	if(root->left == NULL){
		return root->data;
	}else{
		return smallest(root->left);
	}
}
int largest(struct AVLTree* root){
	if(root == NULL){
		return -1;
	}
	if(root->right == NULL){
		return root->data;
	}else{
		return largest(root->right);
	}
}
int height(struct AVLTree* root){
	if(root == NULL){
		return 0;
	}
	int left_height, right_height;
	left_height = height(root->left);
	right_height = height(root->right);
	root->degree = left_height - right_height;
	return maximum(left_height,right_height) + 1;
}
int maximum(int a, int b){
	return a > b ? a : b;
}