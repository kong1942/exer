#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 10000
#define MAXLEN 4

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int heapsort(int *arr, int size)
{
	if(size == 1) return 0;
	int i, max, head;
	for(i=size; i>size/2-1; i--)
	{
		head = i/2;
		while(head > 0)
		{
			max = head;
			if(arr[head*2] > arr[max]) max = head*2;
			if(head*2+1 <= i && arr[head*2+1] > arr[max]) max = head*2+1;
			if(head != max) swap(&arr[head], &arr[max]);
			head--;
		}
		swap(&arr[1], &arr[i]);
	}
	return i+1;
}

int main()
{
	int i=1, j;
	int arr[MAXNUM];
	memset(arr, 0, sizeof(int) * MAXNUM);
	
	scanf("%d", &arr[i]);
	printf("%d\n", arr[i]); i++;
	while(scanf("%d", &arr[i]) != EOF)
	{
		if(i % 2)
		{
			if(arr[i] < arr[i/2]) j = i/2;
			else if(arr[i] > arr[i/2+1]) j = i/2+1;
			else j = i;
			printf("%d\n", arr[j]);
		}
		else
		{
			j = heapsort(arr, i);
			printf("%d\n", (arr[j]+arr[j+1])/2);
		}
		i++;
	}

	return 0;
}
