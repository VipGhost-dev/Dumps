// C++ Instructions
// Octal dump

#include <iostream>
#include <bitset>

using namespace std;

void print(char* pointer, int n)
{
	for (int i = 0; i <= n; ++i)
		cout << pointer[n-i];
}

void BinaryDump(char* binary_dump,int n)
{
	int mask(010000000000);

	binary_dump[31] = (n < 0 ? '1' : '0');			// 31   00000000000000000000000000000010
	for (int i = 0; i < 31; ++i, mask >>= 1)
		binary_dump[30-i] = (n & mask ? '1' : '0'); 	// 30 - 0
}

int ConvertBinaryToDecimal(char* binary_dump)
{
	int decimal = 0;
	int power = 1;

	for (int i = 0; i < 31; ++i, power <<= 1)
		if (binary_dump[i] == '1')
			decimal += power;

	if (binary_dump[31] == '1')
		decimal = -decimal;

	return decimal;
}


void OctalDump(char* octal_dump,int n)
{
	int mask(07000000000);

	octal_dump[10] = char(((n >> 30) & 03) + 48);				// 10
	for (int i = 0; i < 10; ++i, mask >>= 3)
		octal_dump[9-i] = char(((n & mask) >> 27 - i * 3) + 48);	// 9 - 0
}

int ConvertOctalToDecimal(char* octal_dump)
{
	int decimal = 0;
	int power = 1;

	for (int i = 0; i < 10; ++i, power *= 8)
	{
		int digit = octal_dump[9 - i] - '0';
		decimal += digit * power;
	}

	return decimal;
}


void HexadecimalDump(char* hexadecimal_dump,int n)
{
	int mask(0xf000000);
	int digit((n >> 28) & 0xf); //&-побитовое И

	hexadecimal_dump[7] = (digit > 9 ? char(digit + 87) : char(digit + 48));   	// 7   //?-тернарное условие тоже самое, что if..else (операнд1 ? опернад2 : операнд3     если операнд1 то опернад 2 иначе операнд3)
	for (int i = 0; i < 7; ++i, mask >>= 4)
	{
		digit = (n & mask) >> 24 - i * 4;
		hexadecimal_dump[6-i] = (digit > 9 ? char(digit + 87) : char(digit + 48));	// 6 - 0
	}
}


int main()
{
	setlocale(LC_ALL, "RU");
	int n;
	char binary_dump[32];
	char octal_dump[11];
	char hexadecimal_dump[8];
	do
	{
		cout << "Введите число: ";
		cin >> n;
		if (cin.good())
			break;
		else
		{
			cout << "Invalid data!\n";
			cin.clear();
			while (cin.get() != '\n');
		}
	} while (1);

	BinaryDump(binary_dump,n);
	print(binary_dump, 31);
	cout << endl;

	OctalDump(octal_dump,n);
	cout << oct << '\n' << n << endl;
	print(octal_dump,10);
	cout << endl;

	HexadecimalDump(hexadecimal_dump,n);
	cout << hex << '\n' << n << endl;
	print(octal_dump, 7);

	return 0;
}
