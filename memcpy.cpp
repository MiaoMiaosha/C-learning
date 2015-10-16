#include<iostream>
using namespace std;
#include<assert.h>

typedef unsigned char byte;
void* memcpy(void * des, const void *src, size_t size)
{
	assert(des && src);
	byte *to = (byte*)des;
	byte *from = (byte*)src;
	while (size--)
	{
		*to++ = *from++;
	}
	return des;
}

int main(void)
{
	

	system("pause");
}