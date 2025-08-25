#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*next;
};
struct queue{
	struct node *front,*rear;
};
void create_queue(struct queue *q){
	q->front=q->rear=NULL;
}
void insert(struct queue *q,int val){
	struct node *ptr=malloc(sizeof(struct node));
	ptr->data=val;
	ptr->next=NULL;
	if(q->rear==NULL)q->front=q->rear=ptr;
	else q->rear=q->rear->next=ptr;
}
void delete_element(struct queue *q){
	if(q->front==NULL){
		printf("\nUnderflow");
		return;
	}struct node* temp=q->front;
	printf("\nDeleted: %d",temp->data);
	q->front=q->front->next;
	free(temp);
}
int peek(struct queue*q){
	return q->front?q->front->data:-1;
}
void display(struct queue *q){
	if(q->front==NULL){
		printf("\nQueue is empty");
		return;
	}struct node*temp=q->front;
	printf("\nQueue: ");
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}free(temp);
}
void main(){
	struct queue q;
	int val,option;
	create_queue (&q);
	
	int ch;
	do{
		printf("\n1.Insert \n2. Deletion \n3. peek \n4. Display\n5. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter value: ");
				scanf("%d",&val);
				insert(&q,val);
				break;
			case 2:
				delete_element(&q);
				break;
			case 3:
				val=peek(&q);
				if(val==-1)printf("\nQueue is empty");
				else printf("\nfront: %d",val);
				break;
			case 4:
				display(&q);
				break;
		}
		
	}while(option!=5);
}

