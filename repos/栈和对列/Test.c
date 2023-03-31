//#include "Stack.h"
#include "Queue.h"
/*ջ
	int main()
	{
		ST st;
		StackInit(&st);
		StackPush(&st, 1);
		StackPush(&st, 2);
		StackPush(&st, 3);
		StackPush(&st, 4);
		StackPop(&st);
		StackPush(&st, 5);
		while (!StackEmpty(&st))
		{
			printf("%d ", StackTop(&st));
			StackPop(&st);
		}
		printf("\n");

		StackDestory(&st);
		return 0;
	}
*/
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,1);
	QueuePush(&q,2);
	QueuePush(&q,3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))
	{

	printf("%d ", QueueFront(&q));
	QueuePop(&q);

	}
	QueueDestory(&q);



}

int main()
{
	
	TestQueue();
	return 0;
}