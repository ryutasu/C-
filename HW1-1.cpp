/*分別以 Iteration與 Recursion的方式來撰寫底下的 Functions：
i. countI(...) / countR(...)：計算並回傳字串中所含某個字元的總數。
ii. findI(...) / findR(...)：找出並回傳字串中最小的字元。
iii. removeI(...) / removeR(...)：將字串中連續重複出現的字元移除後回傳(例如： engineering =>enginering )。
iv. TI(m, n) / TR(m, n)：求出m和n的乘積並回傳。*/

#include <iostream>
#include <string>

using namespace std;

void input(string sMessage, string& sInputString)
{
	cout << sMessage << endl;
	cin >> sInputString;

	return;
}

void writeBackwardI(string s)
{
	int length = s.size();

	if (length == 0)  // base case 
		return;

	for (int i = length - 1; i >= 0; i--)
		cout << s[i];
}

void writeBackwardR1(string s)
{
	int length = s.size();

	if (length == 0)  // base case 
		return;

	cout << s[length - 1];
	writeBackwardR1(s.substr(0, length - 1));
}

void writeBackwardR2(string s)
{
	int length = s.size();

	if (length == 0)  // base case 
		return;

	writeBackwardR2(s.substr(1, length - 1));
	cout << s[0];
}


int countI(string s, char c)
{
	int length = s.size();
	int a = 0;
	while (length > -1)
	{
		if (s[length] == c)
		{
			a++;
		}
		length--;
	}
	return a;
}

int countR(string s, char c)
{
	int length = s.size();
	if (s[0] == c && length > 1)
	{
		return 1 + countR(s.substr(1), c);
	}
	else if (length > 1)
	{
		return countR(s.substr(1), c);
	}
	else if (length == 1 && s[0] == c)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned char findI(string s)
{
	int length = s.size();
	int a = length - 1;
	while (length > 0)
	{
		if (s[length - 1] < s[a])
		{
			a = length - 1;
		}
		length--;
	}
	return s[a];
}

char findR(string s)
{
	int length = s.size();
	int a = length - 1;
	if (s[0] < s[1])
	{
		s[1] = s[0];
	}
	if (a == 0)
	{
		return s[a];
	}
	else
	{
		return findR(s.substr(1));
	}
}

string removeI(string s)
{
	int length = s.size();
	int a;
	int b = length;
	while (length > 0)
	{
		if (s[length - 1] == s[length])
		{
			a = length;
			while (a < b)
			{
				s[a] = s[a + 1];
				a++;
			}
		}
		length--;
	}
	return s;
}

string removeR(string s)
{
	int length = s.size();
	if (length == 1)
	{
		return s;
	}
	if (s[0] == s[1])
	{
		return removeR(s.substr(1, length - 1));
	}
	else
	{
		return s[0] + removeR(s.substr(1, length - 1));
	}
}

int TI(int m, int n)
{
	int a = 0, b = 0;
	if (m > n)
	{
		while (n > 0)
		{
			a = a + m;
			n--;
		}
	}
	else if (m <= n)
	{
		while (m > 0)
		{
			a = a + n;
			m--;
		}
	}
	return a;

	/*
		T(m, n) = 0, if m = 0 or n = 0
		T(m, n) = m + ... + m (n times), if m > n
		T(m, n) =  n + ... + n (m times), otherwise
	*/


}

int TR(int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 0;
	}
	else if (m > n)
	{
		return m + TR(m, n - 1);
	}
	else
	{
		return n + TR(m - 1, n);
	}

	/*
		T(m, n) = 0, if m = 0 or n = 0
		T(m, n) = m + T( m, n - 1 ), if m > n
		T(m, n) =  n + T( m - 1, n ), otherwise
	*/
	//return m * n;
}

int main()
{
	string commandStr;
	string inputStr, appendStr;
	char inputChr;
	int m, n;

	while (1) {
		input("\nEnter command: "
			"\n I to input a string, A to append a string, B to write the string backward, "
			"\n C to count the given character , F to find the smallest character,"
			"\n R to remove the repeated characters, T to compute, and X to Exit", commandStr);

		if (commandStr == "I" || commandStr == "i") {
			cout << "\nInput the string: ";
			cin >> inputStr;
		}
		else if (commandStr == "A" || commandStr == "a") {
			cout << "\nInput the string: ";
			cin >> appendStr;
			inputStr += appendStr;
			cout << "\nThe new string: " << inputStr << endl;
		}
		else if (commandStr == "B" || commandStr == "b") {
			if (inputStr.length() > 0) {
				cout << endl;
				writeBackwardI(inputStr);
				cout << endl;
				writeBackwardR1(inputStr);
				cout << endl;
				writeBackwardR2(inputStr);
				cout << endl;
			}
		}
		else	if (commandStr == "C" || commandStr == "c") {
			if (inputStr != "") {
				cout << "\nInput the character: ";
				cin >> inputChr;
				cout << "\nCount of " << inputChr << ": " << countI(inputStr, inputChr);
				cout << "\nCount of " << inputChr << ": " << countR(inputStr, inputChr) << endl;
			}
		}
		else if (commandStr == "R" || commandStr == "r") {
			if (inputStr != "") {
				cout << endl << "Repeated characters removed: " << removeI(inputStr);
				cout << endl << "Repeated characters removed: " << removeR(inputStr) << endl;;
			}
		}
		else if (commandStr == "F" || commandStr == "f") {
			if (inputStr != "") {
				cout << endl << "Smallest character found: " << findI(inputStr);
				cout << endl << "Smallest character found: " << findR(inputStr) << endl;
			}
		}
		else  if (commandStr == "T" || commandStr == "t")
		{
			cout << "\nInput two values, m and n: ";
			cin >> m >> n;
			cout << endl << "The result is " << TI(m, n);
			cout << endl << "The result is " << TR(m, n) << endl;
		}
		else  if (commandStr == "X" || commandStr == "x")
			return 0;
		else
			cout << "\nUnknown command!";
	}
	return 0;
}
