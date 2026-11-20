#include <iostream>
using namespace std;
float Divide(float a, float b) {
	float res = 0;
	if (b == 0)
	{
		throw exception("Cant divide by zero!!!");
	}
	else
	{
		res = a / b;
		cout << "Result: " << res << endl;
		return res;
	}

}
class PasswordInvalidException : public exception{
public:
	PasswordInvalidException(const char * message):exception(message)
	{

	}
};
class SmallPasswordException : public exception {
	int lenght;
public:
	SmallPasswordException(const char* message, int lenght):lenght(lenght),exception(message)
	{

	}
	void Message() {
		cout << what() << endl;
		cout << "Actual lenght: " << lenght << endl;
	}
};
void ValidateLogin(const char* login, const char* password) {
	if (strlen(password) < 6)
	{
		throw exception("To small password");
	}
	if (!islower(password[0]) || isalpha(password[0]))
	{
		throw exception("Password is invalid");
	}if (!isupper(login[0]) || !isalpha(login[0]))
	{
		throw exception( "Incorect login");
	}
	cout << "Loading..............." << endl;
}
class MyArray {
	int* arr;
	int size;
public:
	MyArray(int size = 10):size(size)
	{
		arr = new int[size] {};
	}
	void Print()const {
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	int getElement(int index) {
		if (index >= 0 and index < size)
		{
			return arr[index];
		}
		else {
			throw out_of_range("Index is less than 0 or more than size");
		}
	
	}
	void CheckLenght(int len) {
		if (len < 0)
		{
			throw length_error("Some length error");
		}cout << "Lenght is valid" << endl;
	}
	void SetSize(int newSize) {
		if (newSize < 0)
		{
			throw invalid_argument("New size is less than 0");
		}
		else {
			int* temp = new int[newSize];
			for (int i = 0; i < size && i < newSize; i++)
			{
				temp[i] = arr[i];
			}
			delete[]arr;
			arr = temp;
			size = newSize;
		}
	}
	~MyArray()
	{

	}
};
int main()
{
	char login[100];
	char password[100];
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter login: "; cin >> login;
		cout << "Enter password: "; cin >> login;
		try
		{
			ValidateLogin(login, password);
		}
		catch (exception ex)
		{
			cout << "General error" << endl;
			cout << ex.what() << endl;
		}
		catch (PasswordInvalidException ex) {
			cout << "invalid.......... do something" << endl;

		}
		
	}

	/*float a, b;
	cout << "Enter number: ";
	cin >> a >> b;
	float res = Divide(a, b);
	cout << "Result in main: " << res << endl;*/

}
