#include <iostream>
#include <thread>
using namespace std;

int addInts(int intArray[], int index, int num);

int main()
{
	const int arraySize = 10000000;
	int intArray[arraySize];
	const int numOfThreads = 10;
	int indexHelp = arraySize / numOfThreads;
	int num;
	
	for (int i = 1; i < arraySize; i++)
		intArray[i - 1] = i;
	thread t[numOfThreads];
	for (int i = 0;i < numOfThreads; i++)
	{
		t[i] = thread(addInts, intArray, indexHelp * i, indexHelp * (i + 1));
		t[i].join();
	}
}

int addInts(int intArray[], int index, int num)
{
	int sum = 0;
	for (index; index < num; index++)
	{
		sum += intArray[index];
		cout << sum << endl;
	}
	return sum;
}