#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	int height;
	struct Node *next;
};

struct Node* push(struct Node* top, int num){
	struct Node* t = new Node();
	t->data = num;
	if(top != NULL)
		t->height = 1 + top->height;
	else
		t->height = 1;
	t->next = top;
	return t;
}

struct Node* pop(struct Node* top){
	if(top != NULL){
		struct Node* t = top;
		top = top->next;
		delete(t);
	}else{
		printf("Stack Underflow\n");
	}
	return top;
}

int display_top(struct Node* top){
	if(top != NULL){
		return top->data;
	}
	return -1;
}

int count(struct Node* top){
	if(top != NULL){
		return top->height;
	}
	return -1;
}

int main(){
	struct Node * top = NULL;
	while(1){
		int ch,num;
		printf("Press 0 to exit\n");
		printf("Press 1 to push in the stack\n");
		printf("Press 2 to pop in the stack\n");
		printf("Press 3 to display top element\n");
		printf("Press 4 to display the total number of element in the stack\n");
		scanf("%d",&ch);
		switch(ch){
			case 0:	return 0;
			break;
			case 1:
					printf("Enter key\n");
					scanf("%d",&num);
					top = push(top,num);
			break;
			case 2:
					top = pop(top);
			break;
			case 3:	
					num = display_top(top);
					if(num != -1){
						printf("Stack Top : %d \n",num);
					}else{
						printf("Stack Underflow\n");
					}
			break;
			case 4:
					num = count(top);
					if(num != -1){
						printf("Number of element in the Stack : %d \n",num);
					}else{
						printf("Stack Underflow\n");
					}
			break;
			default:printf("Invalid Input\n");
		}
	}
	return 0;
}