#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<string.h>

typedef char element;      // 스택 원소(element)의 자료형을 int로 정의
typedef char q_element;     // 연결 큐 원소(q_element)의 자료형을 char로 정의

typedef struct  stackNode {   // 스택의 노드를 구조체로 정의
	element data;
	struct stackNode *link;
} stackNode, stackNode2;

stackNode* top;            // 스택의 top 노드를 지정하기 위해 포인터 top 선언

						   // 스택이 공백 상태인지 확인하는 연산
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;     // 삽입 노드를 top의 위에 연결
	top = temp;           // top 위치를 삽입 노드로 이동
}

// 스택의 top에서 원소를 삭제하는 연산
element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {      // 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {               // 스택이 공백 리스트가 아닌 경우
		item = temp->data;
		top = temp->link;   // top 위치를 삭제 노드 아래로 이동
		free(temp);         // 삭제된 노드의 메모리 반환
		return item;      // 삭제된 원소 반환
	}
}

// 스택의 top 원소를 검색하는 연산
element peek() {
	if (top == NULL) {      // 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {               // 스택이 공백 리스트가 아닌 경우
		return(top->data);  // 현재 top의 원소 반환
	}
}

// 스택의 원소를 top에서 bottom 순서로 출력하는 연산
void printStack() {
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%c ", p->data);
		p = p->link;
	}
	printf("] ");
}


typedef struct QNode {    // 연결 큐의 노드를 구조체로 정의
	q_element data;
	struct QNode *link;
} QNode;

typedef struct {		// 연결 큐에서 사용하는 포인터 front와 rear를 구조체로 정의
	QNode *front, *rear;
} LQueueType;

// 공백 연결 큐를 생성하는 연산
LQueueType *createLinkedQueue() {
	LQueueType *LQ;
	LQ = (LQueueType *)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

// 연결 큐가 공백 상태인지 검사하는 연산
int isEmpty_q(LQueueType *LQ) {
	if (LQ->front == NULL) {
		printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

// 연결 큐의 rear에 원소를 삽입하는 연산
void enQueue(LQueueType *LQ, element item) {
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {		// 현재 연결 큐가 공백 상태인 경우
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {						// 현재 연결 큐가 공백 상태가 아닌 경우
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

// 연결 큐에서 원소를 삭제하고 반환하는 연산
q_element deQueue(LQueueType *LQ) {
	QNode *old = LQ->front;
	q_element item;
	if (isEmpty_q(LQ)) return 0;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}

// 연결 큐에서 원소를 검색하는 연산
q_element peek_q(LQueueType *LQ) {
	q_element item;
	if (isEmpty_q(LQ)) return 0;
	else {
		item = LQ->front->data;
		return item;
	}
}

// 연결 큐의 원소를 출력하는 연산
void printLQ(LQueueType *LQ) {
	QNode *temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] ");
}

void main(void) {
	LQueueType *LQ = createLinkedQueue();  // 연결 큐 생성
	q_element data;
	element item;
	int i;
	char *str = "Korea Polytechnic University Love Me";
	top = NULL;
	printLQ(LQ);
	printf("\n");
	for (i = 0; i < strlen(str); i++)   //개더럽게 KOREA POLY...Enqueue하는 과정인거같음
	{
		enQueue(LQ, input_string[i]);
		printLQ(LQ);
		printf("\n");
	}
	enQueue(LQ, '\0');
	for (int i = 0; i < 5; i++)
	{
		while (1)
		{
			data = deQueue(LQ);
			if (data == ' ' || data == '\0')
				break;
			push(data);
			printStack();
		}
		printf("\n");
		while (1)
		{
			if (isEmpty())
				break;
			item = pop();
			printf("%c", item);
		}
		printf("\n");
	}

}