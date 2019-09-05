#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

typedef char element;		// 스택 원소(element)의 자료형을 int로 정의 
int cnt = 0;
typedef struct  stackNode {	// 스택의 노드를 구조체로 정의
	element data;
	struct stackNode *link;
} stackNode;

stackNode* top;				// 스택의 top 노드를 지정하기 위해 포인터 top 선언

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
	cnt++;
}

// 스택의 top에서 원소를 삭제하는 연산
element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {		// 스택이 공백 리스트인 경우
		//printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// 스택이 공백 리스트가 아닌 경우
		item = temp->data;
		top = temp->link;	// top 위치를 삭제 노드 아래로 이동
		free(temp);	
		cnt--;		// 삭제된 노드의 메모리 반환
		return item;		// 삭제된 원소 반환
	}
}

// 스택의 top 원소를 검색하는 연산
element peek() {
	if (top == NULL) {		// 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {					// 스택이 공백 리스트가 아닌 경우
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

void view_stack()
{
	int flag = 10;
	system("cls");
	stackNode* temp;
	temp = top;
	printf("	|    stack    |\n");
	printf("	|-------------|\n");
	for (flag; flag > cnt; flag--)
		printf("	|             |\n");

	while (temp != NULL)
	{
		printf("	|      %c      |\n", temp->data);
		temp = temp->link;
		flag--;
	}
	printf("	|-------------|\n");
}

void delay(clock_t n)
{
	clock_t start = clock();
	while (clock() - start < n);
}

void main(void) {
	char n;
	system("COLOR 02");
	system("mode con cols=45 lines=23");
	element item, temp;
	top = NULL;
	while (1)
	{
		view_stack();
		printf("%30s", "* 1. Push mode.       \n");
		printf("%30s", "* 2. Pop mode.        \n");
		printf("%30s", "* 3. Exit the program.\n");
		printf("\n%24s", "Select number : ");
		scanf("%c", &n);

		if (n == '1')
		{
			while (1)
			{
				view_stack();
				printf("\n\n%39s", "(Press '/' to out)");
				printf("\n%39s", "Push data : ");
				scanf("%c", &n);

				if (n == '/')
				{
					break;
				}
				else if ((n >= 48 && n <= 57) || (n >= 65 && n <= 90) || (n >= 97 && n <= 122))
				{
					if (cnt == 10)
					{
						printf("\n\n%35s", "The stack is full....");
						delay(500);
					}
					else
						push(n);
				}
			}
		}
		else if (n == '2')
		{
			while (getchar() != '\n');
			while (1)
			{
				view_stack();
				printf("\n\n%39s", "(Press '/' to out)");
				printf("\n%39s", "Press enter to pop : ");
				scanf("%c", &n);

				if (n == '/')
				{
					break;
				}
				else
				{
					temp = pop();
					if (temp == 0)
					{
						printf("\n\n%39s", "The stack is emty....");
						delay(1000);
					}
					else
					{
						printf("\n\n%39s", "Output data : ");
						printf("%c", temp);
						delay(1000);
					}
				}
			}
		}
		else if (n == '3')
			break;
	}
}