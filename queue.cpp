#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};

struct Node* enQueue(struct Node* start, int num){
	if(start == NULL){
		struct Node* t = new Node();
		t->data = num;
		t->next = start;
		return t;		
	}
	start->next = enQueue(start->next, num);
	return start;
}

struct Node* deQueue(struct Node* start){
	if(start != NULL){
		struct Node* t = start;
		start = start->next;
		delete(t);
	}else{
		printf("Queue empty\n");
	}
	return start;
}

int front(struct Node* start){
	if(start != NULL){
		return start->data;
	}
	return -1;
}

int count(struct Node* start){
	if(start != NULL){
		return 1 + count(start->next);
	}
	return 0;
}

int main(){
	struct Node *start = NULL;
	while(1){
		int ch,num;
		printf("Press 0 to exit\n");
		printf("Press 1 to push in the Queue\n");
		printf("Press 2 to pop in the Queue\n");
		printf("Press 3 to display front element of the Queue\n");
		printf("Press 4 to display the total number of element in the Queue\n");
		scanf("%d",&ch);
		switch(ch){
			case 0:	return 0;
			break;
			case 1:
					printf("Enter key\n");
					scanf("%d",&num);
					start = enQueue(start,num);
			break;
			case 2:
					start = deQueue(start);
			break;
			case 3:	
					num = front(start);
					if(num != -1){
						printf("Queue front : %d \n",num);
					}else{
						printf("Queue empty\n");
					}
			break;
			case 4:
					num = count(start);
					if(num != -1){
						printf("Number of element in the Queue : %d \n",num);
					}else{
						printf("Queue empty\n");
					}
			break;
			default:printf("Invalid Input\n");
		}
	}
	return 0;
}