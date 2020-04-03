#include <iostream>
#include <string.h>
using namespace std;

void interleaveString(char *str1, char *str2, char *interleave, int index, int str1len, int str2len)
{
	if (str1len + str2len == 0) //Base case for recursion to end: str1length + str2length are both 0
	{
		
		cout << interleave << endl;
		return;
	}
	if (str1len != 0) //If the length of str1 is not 0
	{
		interleave[index] = str1[0]; //Assign first character in str1 to index 
		interleaveString(str1 + 1, str2, interleave, index + 1, str1len-1, str2len); //Call function again, increment for next character of str1 to be first character, increment index, decrease str1 length
	}
	if (str2len != 0)//If the length of str2 is not 0
	{
		interleave[index] = str2[0]; //Assign first character in str1 to index
		interleaveString(str1, str2 + 1, interleave, index + 1, str1len, str2len - 1); //Call function again, increment for next character of str2 to be first character, increment index, decrease str2 length

	}
}
int main()
{
	char *str1 = new char[255]; //Allocate memory for str1
	char *str2 = new char[255]; //Allocate memory for str2

	cout << "Enter the string str1 : ";
	cin >> str1;
	cout << "Enter the string str2 : ";
	cin >> str2;
	char* interleave = new char[strlen(str1) + strlen(str2)]; //Assign memory to interleave of the length of str1 and str2
	interleave[strlen(str1) + strlen(str2)] = '\0'; //Make sure the string ends appropriately
	
	cout << "The interleavings are: \n";
	interleaveString(str1, str2, interleave, 0, strlen(str1), strlen(str2)); //Run the recursion function
	return 0;
}