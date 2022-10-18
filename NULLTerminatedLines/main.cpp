#include<iostream>
#include<Windows.h>

using namespace std;
//#define EXAMPLE_1
#define EXAMPLE_2

int StringLength(const char str[]);
void upper_case(char str[]);
void lower_case(char str[]);
void shrink(char str[]);
bool palindrome(char str[]);
bool is_int_number(const char str[]);
void grohnut_probel(char str[]);
int  to_int_number(char str[]);
bool is_bin_number(char str[]);
int bin_to_dec_number(char str[]);
bool is_hex_number(char str[]);
int  hex_to_dec(char str[]);
void main()
{
	setlocale(LC_ALL, "");
#ifdef EXAMPLE_1
	//char str[] = { 'H','e', 'l','l','o', 0};
	char str[] = "Hello";
	cout << str << endl;
	cout << typeid(str).name() << endl;
	cout << typeid("Hello").name() << endl;
#endif // EXAMPLE_1
	for (int i = 0; i < 256; i++)
	{
		//cout << i << "\t" << char(i) << endl;
	}

	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "Введите строки: ";
	//cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	//SetConsoleCP(866);
	cout << str << endl;
	cout << "Размер строки в символах: " << StringLength(str) << endl;
	cout << "Размер строки в символах: " << strlen(str) << endl;
	cout << "Размер строки в Байтах: " << sizeof(str) << endl;
	/*cout << "Изменение строчных букв на заглавные: " << endl;
	upper_case(str);
	cout << str << endl;
	cout << "Изменение заглавных букв на строчные: " << endl;
	lower_case(str);
	cout << str << endl;
	cout << "Удаление лишних пробелов: " << endl;
	shrink(str);
	cout << str << endl;*/

	cout << (palindrome(str) ? "" : "Не ") << "является палиндромом" << endl;
	cout << str << endl;

	cout << (is_int_number(str) ? "" : "Не ") << "является целым десятичным числом" << endl;
	cout << to_int_number(str) << endl;
	cout << (is_bin_number(str) ? "" : "Не ") << "является двоичным числом " << endl;
	cout << "Введенное двоичное число при переводе в десятичную будет = " << bin_to_dec_number(str) << endl;
	cout << (is_hex_number(str) ? "" : "Не ") << "является шестнадцатиричным числом" << endl;
	
	cout << hex_to_dec(str);
}
int StringLength(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;	
}
void upper_case(char str[])
{
	for (int i=0; str[i]; i++)
	{
		/*if (str[i] >= 'a' && str[i] < 'z')
		{
			str[i] -= 32;
		}
		if (str[i] >= 'а' && str[i] < 'я')
		{
			str[i] -= 32;
		}		*/
		str[i] = toupper(str[i]);
	}
}
void lower_case(char str[])
{
	for (int i = 0; str[i]; i++)
	{		
		str[i] = tolower(str[i]);
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] ==' ' && str[i] == str[i-1])
		{
			for (int j = i-1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}		
	}
}
bool palindrome(char str[]) 
{
	int size = strlen(str);
	char* buffer = new char[size + 1]{};
	strcpy(buffer, str);
	lower_case(buffer);
	grohnut_probel(buffer);
	int size1 = strlen(buffer);
	
	for (int i=0; i < size1; i++)
	{
		if(buffer[i] != buffer[size1 - 1 - i])
		{
			delete[] buffer;
			return false;			
		}
		else
		{
			delete[] buffer;
			return true;
		}
		
	}	
}

bool is_int_number(const char str[])
{
	int size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		
		if(str[i] >= 48 && str[i] <= 57 && i==size-1)
		{
				return true;
		}		
		if (str[i] < 48 || str[i] > 57)
		{
			return false;			
		}		
	}
}
void grohnut_probel(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ')
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
int to_int_number(char str[])
{
	int size = strlen(str);
	int x=0;
	int y = size-1;	
	for (int i = 0;  y>=0; i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{		
			//cout << "y = " << y << endl;
			x += (str[i]-48) * pow(10, y--);
			
			//cout << "x = " << x << endl;
			//cout << "str[i]= " << str[i]-48 << endl;
		}
		
	}
	return x;
}

bool is_bin_number(char str[])
{	
	int size = strlen(str);
	
	for (int i = 0; i < size; i++)
	{
		if (str[i] >= 48 && str[i] <= 49 && i == size - 1)
		{			
			return true;
		}
		if (str[i] < 48 || str[i] > 49)
		{
			return false;
		}
	}
	
}
int bin_to_dec_number(char str[])
{
	int x;	
	int y = 0;
	int size = strlen(str);
	int c = size;	
	for (int i = 0; i < size; i++)
	{
		if (str[i] >= 48 && str[i] <= 49)
		{	
			x = pow(2, --c);
			y += x * (str[i] - 48);	
		}
		if (str[i] < 48 || str[i] > 49)
		{
			return false;			
		}
    }   
	return y;
}
bool is_hex_number(char str[])
{
	upper_case(str);
	int size = strlen(str);	
	
	for (int i = 0; i < size; i++)	
	{	
		if (str[i] >= 48 && str[i] <= 57 && i == size - 1)
		{
			return true;
		}
		if (str[i] >= 65 && str[i] <= 70 && i == size - 1)
		{
			return true;
		}
		if (str[i] < 48 || str[i] > 57 && str[i]!=65 && str[i] != 66 && str[i] != 67 && str[i] != 68 && str[i] != 69 && str[i] != 70)
		{
			return false;
		}
	}
}
int  hex_to_dec(char str[])
{
	int size = strlen(str);
	char* buffer = new char[size + 1]{};
	strcpy(buffer, str);
	upper_case(buffer);
	int x;
	int y = 0;	
	int c = size;
	for (int i = 0; i < size; i++)
	{
		if (buffer[i] >= 48 && buffer[i] <= 57)
		{
			x = pow(16, --c);
			y += x * (buffer[i] - 48);
		}
		if (buffer[i] >= 65 && buffer[i] <= 70)
		{
			x = pow(16, --c);
			y += x * (buffer[i] - 55);
		}	
	}
	return y;
}

