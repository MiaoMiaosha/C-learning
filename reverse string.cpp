
#include <stdio.h>
#include<iostream>
using namespace std;
void reverseFixlen(char *str, int n) {
	char* p = str + n - 1;
	while (str < p) {
		char c = *str;
		*str = *p; *p = c;
	}
}
void reverseWordsInSentence(char * sen) {
	int len = strlen(sen);
	reverseFixlen(sen, len);
	char * p = sen;
	while (*p != '\0') {
		while (*p == ' ' && *p != '\0') p++;
		sen = p;
		while (*p != ' ' && *p != '\0') p++;
		reverseFixlen(sen, p - sen );
	}
}
void ReverseStr(char *begin, char *end)

{

	//reverse the whole string

	while (begin < end)

	{

		char temp = *begin;

		*begin = *end;

		*end = temp;

		begin++;

		end--;

	}

}



void Reverse(char *str)

{
	//reverse the whole string
	size_t len = strlen(str);
	ReverseStr(str, str + len - 1);
	//reverse every word
	char *p1 = str;
	char *p2 = str;
	while (*p2 != '\0')
	{
	   while (*p2 != '\0' && *p2 != ' ')
			p2++;
		ReverseStr(p1, p2 - 1);
		while (*p2 == ' ')
			p2++;
		p1 = p2;
	}
}

int main()
{
	char str[] = "I   am   a   student.";

	Reverse(str);


	cout << str << endl;

	system("PAUSE");

}