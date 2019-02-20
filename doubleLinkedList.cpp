#include<bits/stdc++.h>
using namespace std;
struct ListNode{
	int data;
	struct ListNode *next, *prev;
};
struct ListNode* reverse(struct ListNode* start);
int count(struct ListNode* start);
int search(struct ListNode* start, int num);
void display(struct ListNode* start);
struct ListNode* insert_begin(struct ListNode* start, int num);
struct ListNode* insert_end(struct ListNode* start, int num);
struct ListNode* insert_position(struct ListNode* start, int num, int pos);
struct ListNode* delete_begin(struct ListNode* start);
struct ListNode* delete_end(struct ListNode* start);
struct ListNode* delete_position(struct ListNode* start, int pos);
int main(){
	struct ListNode* start = NULL;
	while(1){
		int ch,num,n,pos,temp;
		printf("Press 0 to exit\n");
		printf("Press 1 to insert node in the List\n");
		printf("Press 2 to delete node from the List\n");
		printf("Press 3 to reverse the List\n");
		printf("Press 4 to count the number of Nodes\n");
		printf("Press 5 to search the List\n");
		printf("Press 6 to display the List\n");
		scanf("%d",&ch);
		switch(ch){
			case 0: 
				return 0;
				break;
			case 1:
				printf("Enter the key\n");
				scanf("%d",&num);
				printf("Press 1 to insert in beginning\n");
				printf("Press 2 to insert in end\n");
				printf("Press 3 to insert in given location\n");
				scanf("%d",&n);
				switch(n){
					case 1: 
						start = insert_begin(start, num);
						break;
					case 2: 
						start = insert_end(start, num);
						break;
					case 3:
						printf("Enter the position\n");
						scanf("%d",&pos);
						start = insert_position(start, num, pos);
						break;
					default: printf("Invalid Option\n");
				}
				break;
			case 2:
				printf("Press 1 to delete in beginning\n");
				printf("Press 2 to delete in end\n");
				printf("Press 3 to delete in given location\n");
				scanf("%d",&n);
				switch(n){
					case 1: 
						start = delete_begin(start);
						break;
					case 2: 
						start = delete_end(start);
						break;
					case 3:
						printf("Enter the position\n");
						scanf("%d",&pos);
						start = delete_position(start, pos);
						break;
					default: printf("Invalid Option\n");
				}
				break;
			case 3:
				start = reverse(start);
				break;
			case 4:
				printf("Number of Nodes in the List : %d\n", count(start));
				break;
			case 5:
				printf("Enter the key to search\n");
				scanf("%d",&num);
				temp = search(start, num);
				if(temp){
					printf("Key Present in the List\n");
				}else{
					printf("Key not presnt in the List\n");
				}
				break;
			case 6:
				display(start);
				printf("NULL\n");
				break;
			default:
				cout<<"Invalid Option\n";
		}
	}
	return 0;
}


struct ListNode* reverse(struct ListNode* start){
	struct ListNode *t = NULL;
	while(start != NULL){
		struct ListNode * temp = start;
		start = start->next;
		temp->next = t;
		if(t != NULL)
			t->prev =temp;
		temp->prev = NULL;
		t = temp;
	}
	return t;	
}

int count(struct ListNode* start){
	if(start != NULL)
		return 1 + count(start->next);
	return 0;
}

int search(struct ListNode* start, int num){
	if(start != NULL){
		if(start->data == num)
			return 1;
		else
			return search(start->next, num);
	}else{
		return 0;
	}
}

void display(struct ListNode* start){
	if(start != NULL){
		cout<<start->data<<"->";
		display(start->next);
	}
}

struct ListNode* insert_begin(struct ListNode* start, int num){
	struct ListNode* t = new ListNode();
	t->data = num;
	t->next = start;
	if(start != NULL)
		start->prev = t;
	t->prev = NULL;
	return t;
}

struct ListNode* insert_end(struct ListNode* start, int num){
	if(start == NULL){
		struct ListNode* t = new ListNode();
		t->data = num;
		t->next = start;
		if(start != NULL)
			start->prev = t;
		t->prev = NULL;
		return t;
	}else if(start->next == NULL){
		struct ListNode* t = new ListNode();
		t->data = num;
		t->next = NULL;
		start->next = t;
		t->prev = start;
		return start;
	}else{
		start->next = insert_end(start->next, num);
		return start;
	}
}

struct ListNode* insert_position(struct ListNode* start, int num, int pos){
	if(pos == 1){
		return insert_begin(start,num);
	}
	if(start == NULL){
		cout<<"Stack UnderFlow\n";
		return start;
	}
	if(pos == 2){
		struct ListNode* t = new ListNode();
		t->data = num;
		t->next = start->next;
		if(start->next != NULL)
			start->next->prev = t;
		t->prev = start;
		start->next = t;
		return start;
	}
	start->next = insert_position(start->next, num, pos - 1);
	return start;
}

struct ListNode* delete_begin(struct ListNode* start){
	if(start != NULL){
		struct ListNode* t = start;
		start = start->next;
		if(start != NULL)
			start->prev = NULL;
		delete(t);
	}else{
		cout<<"Stack UnderFlow\n";
	}
	return start;
}

struct ListNode* delete_end(struct ListNode* start){
	if(start == NULL){
		cout<<"Stack UnderFlow\n";
		return start;
	}else if(start->next == NULL){
		struct ListNode* t = start;
		delete(t);
		return NULL;
	}
}

struct ListNode* delete_position(struct ListNode* start, int pos){
	if(start == NULL){
		cout<<"Stack UnderFlow\n";
		return start;
	}
	if(pos == 1){
		return delete_begin(start);
	}
	if(start->next == NULL){
		cout<<"Stack UnderFlow\n";
		return start;
	}
	if(pos == 2){
		struct ListNode* t = start->next;
		start->next = t->next;
		if(t->next != NULL)
			t->next->prev = start;
		delete(t);
		return start;
	}
	start->next = delete_position(start->next, pos - 1);
	return start;
}
