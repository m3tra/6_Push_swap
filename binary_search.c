#include <stdio.h>
#include <stdlib.h>

int binaryIterative(int arr[], int len, int x)
{
	int low = 0, high = len - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (x == arr[mid])
			return (mid);
		else if(x > arr[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

int binaryRecursive(int arr[], int low, int high, int x)
{
	if (low > high)
		return (-1);
	int mid = low + (high - low) / 2;
	if (x == arr[mid])
		return (mid);
	else if (x > arr[mid])
		binaryRecursive(arr, mid + 1, high, x);
	else
		binaryRecursive(arr, low, high - 1, x);
}

int main(int argc, char **argv)
{
	int A[] = {1, 4, 6, 8, 9, 13, 16, 21};
	int input = atoi(argv[1]);
	int result = binaryRecursive(A, 0, 7, input);
	if (result == -1)
	{
		printf("Input (%d) Is Not in array.\n", input);
	}
	else
		printf("Input (%d) Is in index %d.\n", A[result], result);

	return (0);
}
