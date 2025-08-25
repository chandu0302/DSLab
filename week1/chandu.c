#include<stdio.h>
#include<stdlib.h>
void insert();
void display();
void del();
void search();


struct node{
	int data;
	struct node*next;
};
struct node*n,*head = NULL,*temp = NULL,*p;

void main(){
	int ch;
	while(1){
		printf("1.Insert 2.Deletion 3.Search 4.Display");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				search();
				break;
			case 4:
				display();
				break;
			default:
				exit;
		}
	}
}
void insert(){
	int c,val;
	n = (struct node*)malloc(sizeof(struct node));
	printf("Enter Data : ");
	scanf("%d",&n->data);
	if(head == NULL){
		head = n;
		n->next = NULL;
	}else{
		printf("1.Begin 2.Ending 3.After Some Node 4.Before Some Data");
		printf("Enter your Choice : ");
		scanf("%d",&c);
		switch(c){
			case 1:
				n->next = head;
				head = n;
				break;
			case 2:
				n->next == NULL;
				temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = n;
				break;
			case 3:
				printf("Enter after which data to input : ");
				scanf("%d",&val);
				temp = head;
				while(temp->data != val){
					temp = temp->next;
				}
				n->next = temp->next;
				temp->next = n;
			case 4:
				printf("Before Which node : ");
				scanf("%d",&val);
				temp = head;
				p = NULL;
				while(temp->data != val){
					p = temp;
					temp = temp->next;
				}
				n->next = temp;
				p->next = n;
				break;
		}
	}
}
void display(){
	if(head == NULL){
		printf("!!NO ELEMENT FOUND!!");
	}
	else{
	    temp=head;
	    while(temp != NULL){
		  printf("%d\n",temp->data);
		  temp = temp->next;
	    }
	}
}
void del(){
	int c,val;
	if(head == NULL){
		printf("!!LINKED LIST IS EMPTY!!");
	}
	else{
		printf("1.Begin 2.Ending 3.Particular");
		printf("Enter Your Choice : ");
		scanf("%d",&c);
		switch(c){
			case 1:
				temp = head;
				head = head->next;
				free(temp);
				break;
			case 2:
				p=NULL;
				temp=head;
				while(temp->next != NULL){
					p=temp;
					temp = temp->next;
				}
				p->next=NULL;
				free(temp);
				break;
			case 3:
				printf("Enter Node to Delete : ");
				scanf("%d",&val);
				p=NULL;
				temp=head;
				while(temp->data != val){
					p=temp;
					temp=temp->next;
				}
				p->next=temp->next;
				free(temp);
				break;
		}
	}
}
void search(){
	int val,c;
	if(head==NULL){
		printf("!!LINKED LIST IS EMPTY!!");
	}
	else{
		printf("Enter data to search : ");
		scanf("%d",&val);
		temp=head;
		while(temp != NULL){
			if(temp->data == val){
				c=1;
				break;
			}
			else{
				temp=temp->next;
			}
		}
		if(c==1){
			printf("Element is FOUND");
		}
		else{
			printf("No Data is Present");
		}	
    }
}
