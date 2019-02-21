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
struct ListNode* end(struct ListNode* start);
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


struct ListNode* end(struct ListNode* start){
	if(start == NULL)
		return start;
	struct ListNode* t = start;
	do{
		t = t->next;
	}while(t->next != start);
	return t;
}

struct ListNode* reverse(struct ListNode* start){
	struct ListNode *t = NULL;
	struct ListNode *temp = start;
	do{
		struct ListNode* sw = temp;
		temp = temp->next;
		sw->next = t;
		if(t != NULL)
			t->prev = sw;
		sw->prev = NULL;
		t = sw;
	}while(temp != start);
	start->next = t;
	return t;	
}

int count(struct ListNode* start){
	if(start != NULL){
		struct ListNode* t = start;
		int c = 1;
		while(t->next != start){
			c++;
			t = t->next;
		}
		return c;
	}
	return 0;
}

int search(struct ListNode* start, int num){
	struct ListNode *t = start;
	do{
		if(t->data == num)
			return 1;
		t = t->next;
	}while(t != start);
	return 0;
}

void display(struct ListNode* start){
	if(start != NULL){
		struct ListNode* t = start;
		do{
		cout<<t->data<<"->";
		t = t->next;
		}while(t != start);
	}
}

struct ListNode* insert_begin(struct ListNode* start, int num){
	struct ListNode* t = new ListNode();
	t->data = num;
	if(start == NULL){
		t->next = t;
	}
	else{
		t->next = start;
		start->prev = t;
		struct ListNode* temp = end(start);
		temp->next = t;
	}
	t->prev = NULL;
	return t;
}

struct ListNode* insert_end(struct ListNode* start, int num){
	if(start == NULL){
		return insert_begin(start, num);
	}
	struct ListNode* t = new ListNode();
	struct ListNode* temp = start;
	t->data = num;
	while(temp->next != start){
		temp = temp->next;
	}
	t->next = temp->next;
	temp->next = t;
	t->prev = temp;
	return start;
}

struct ListNode* insert_position(struct ListNode* start, int num, int pos){
	if(pos == 1){
		return insert_begin(start,num);
	}
	if(start == NULL){
		cout<<"Stack UnderFlow\n";
		return start;
	}
	struct ListNode* t = new ListNode();
	t->data = num;
	struct ListNode* temp = start;
	while(--pos > 1 && temp->next != start){
		temp = temp->next;
	}
	if(pos == 1){
		t->next = temp->next;
		temp->next = t;
		t->prev = temp;
	}else{
		cout<<"Stack UnderFlow\n";
	}
	return start;
}

struct ListNode* delete_begin(struct ListNode* start){
	if(start != NULL){
		struct ListNode* t = start;
		struct ListNode* temp = end(start);
		if(start->next == start){
			start = NULL;
		}else{
			start = start->next;
			temp->next = start;
		}
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
	}
	struct ListNode* t = start;
	if(start->next == start){
		start = NULL;
	}else{
		t = end(start);
		struct ListNode* temp = t->prev;
		temp->next = start;	
	}
	delete(t);
	return start;

}

struct ListNode* delete_position(struct ListNode* start, int pos){
	if(start == NULL){
		cout<<"Stack UnderFlow\n";
		return start;
	}
	if(pos == 1){
		return delete_begin(start);
	}
	struct ListNode* t = start;
	while( --pos > 0 && t->next != start){
		t = t->next;
	}
	if(pos == 0){
		t->prev->next = t->next;
		if(t->next != start)
			t->next->prev = t->prev;
		delete(t);
	}else{
		cout<<"Stack UnderFlow\n";
	}

	return start;
}
