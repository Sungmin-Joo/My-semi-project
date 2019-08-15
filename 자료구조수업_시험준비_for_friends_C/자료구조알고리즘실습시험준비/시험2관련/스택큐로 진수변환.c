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

char switch_decimal_to_16_notation(int A)
{
	switch (A)
	{
	case 15:
		return 'F';
		break;
	case 14:
		return 'E';
		break;
	case 13:
		return 'D';
		break;
	case 12:
		return 'C';
		break;
	case 11:
		return 'B';
		break;
	case 10:
		return 'A';
		break;
	default:
		return '0' + A;
		break;
	}
}

void main(void) {
	LQueueType *LQ = createLinkedQueue();
	q_element data;
	element item;
	int i, count = 0, decimal, part, q_count = 0;
	char temp[4];

	top = NULL;
	printf("10진수를 입력하세연~ : ");
	scanf("%d", &decimal);
	while (1)
	{
		if (decimal / 2)
		{
			push((decimal % 2) + 0x30);
			decimal /= 2;
		}
		else
		{
			push(decimal + 0x30);
			break;
		}
	}
	printStack();
	putchar('\n');
	printf("2진수 결과 입니다. : ");
	while (!isEmpty())
	{
		data = pop();
		putchar(data);
		enQueue(LQ, data);
		q_count++;
	}
	enQueue(LQ, '\0');
	putchar('\n');
	printLQ(LQ);

	
	decimal = 0;
	for (i = (q_count % 4) - 1; i >= 0; i--)
	{
		data = deQueue(LQ);
		q_count--;
		if (data == '1')
		{
			switch (i)
			{
			case 2:
				decimal += 4;
				break;
			case 1:
				decimal += 2;
				break;
			case 0:
				decimal += 1;
				break;
			default:
				break;
			}
		}
	}
	putchar('\n');
	printf("16진수로 변환한 값 입니다. : ");
	putchar(switch_decimal_to_16_notation(decimal));
	
	while (1)
	{	
		decimal = 0;
		for (i = 3; i >= 0; i--)
		{
			data = deQueue(LQ);
			q_count--;
			if (data == '1')
			{
				switch (i)
				{
				case 3:
					decimal += 8;
					break;
				case 2:
					decimal += 4;
					break;
				case 1:
					decimal += 2;
					break;
				case 0:
					decimal += 1;
					break;
				default:
					break;
				}
			}
		}
		putchar(switch_decimal_to_16_notation(decimal));
		if (q_count == 0)
			break;
	}
	putchar('\n');
}