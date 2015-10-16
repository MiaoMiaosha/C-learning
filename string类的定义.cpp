#include <iostream>
#include <cstring>
using namespace std;
class String {
public:
	//String();
	String(const char* str = NULL);
	String(const String &other);
	~String();
	String &operator=(const String & other);
	operator const char *() const;
public:
	char * m_data;
};

String::String(const char *str)
{
	if (str)
	{
		m_data = new char(strlen(str) + 1);
		memcpy(m_data, str, strlen(str) + 1);
	}
	else
	{
		m_data = new char(1);
		*m_data = '\0';
	}
}

String::String(const String &other)
{
	if (other)
	{
		m_data = new char(strlen(other.m_data) + 1);
		memcpy(m_data, other.m_data, strlen(other.m_data) + 1);
	}
	else
		m_data = NULL;
}

String:: ~String()
{
	if (m_data)
	{
		delete[] m_data;
	}
}

String & String::operator= (const String &other)
{
	if (this == &other)
		return *this;
	else
	{
		delete[] m_data;
		m_data = new char(strlen(other.m_data) + 1);
		//memcpy(m_data, other.m_data, strlen(other.m_data)+1);
		strcpy(m_data, other.m_data);
		return *this;
	}
}