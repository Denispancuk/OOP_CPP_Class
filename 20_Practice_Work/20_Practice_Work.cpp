#include <iostream>
using namespace std;
class Stack {
private:
	enum { EMPTY = -1 };
	int* arr;
	int size;
	int topIndex;
public:
	Stack() = default;
	Stack(int size) :size(size)
	{
		if (size > 0)
		{
			arr = new int[size];
			topIndex = EMPTY;
		}
		else {
			throw invalid_argument("Size less than 0");
		}
	}
	
	bool IsFull()
	{
		return topIndex == size - 1;
	}
	void Push(int elem) {

		if (!IsFull())
		{
			arr[++topIndex] = elem;
		}
		else {
			throw overflow_error("List is full");
		}
		
	}
	bool IsEmpty()
	{
		return topIndex == EMPTY;
	}
	int Pop()
	{
		if (!IsEmpty())
		{
			return arr[topIndex--];
		}
		else {
			throw underflow_error("List is empty");
		}
	}
	int GetCount()
	{
		return topIndex + 1;
	}
	void Clear()
	{
		topIndex = EMPTY;
	}
	int Peek()
	{
		if (!IsEmpty())
		{
			return arr[topIndex];
		}
		else {
			throw underflow_error("List is empty");
		}
	}
	void Print()
	{
		for (int i = 0; i <= topIndex; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	~Stack()
	{
		if (arr != nullptr)
			delete[]arr;
	}
};

int main()
{
	try
	{
		Stack st(15);
		cout << "Size = " << st.GetCount() << endl;
		for (int i = 0; i < 7; i++)
		{
			st.Push(rand() % 50);
		}

		cout << "Size = " << st.GetCount() << endl;
		st.Print();
		while (!st.IsEmpty())
		{
			cout << "Delete element : " << st.Pop() << endl;
			st.Print();
		}
		cout << "Size = " << st.GetCount() << endl;
	}
	catch (invalid_argument ex)
	{
		cout << ex.what() << endl;
	}
	catch (underflow_error ex)
	{
		cout << ex.what() << endl;
	}
	catch (overflow_error ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
	}

	




}