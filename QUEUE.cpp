#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1,rear = -1;

void enqueue(int value) {
	if(rear == SIZE - 1)
	  printf("Queue is full\n");
	else{
		if(front == -1)
		front = 0;
		rear++;
		queue[rear] = value;
		printf("Inserted %d\n", value);
	}
}
void dequeue() {
	if(front == -1 || front > rear)
	 printf("Queue is empty\n");
	 else{
	 	printf("Deleted %d\n", queue[front]);
	 	front++;
	 }
}
void display() {
	if(front == -1 || front > rear)
	printf("Queue is empty\n");
	else{
		printf("Queue:");
		for(int i = front; i <= rear; i++)
		 printf("%d\n",queue[i]);
		 printf("\n");
	}
}
int main() {
	enqueue(22);
	enqueue(33);
	enqueue(44);
	display();
	
	dequeue();
	display();
	
	enqueue(55);
	enqueue(66);
	enqueue(76);
	display();
	
	return 0;	
}
