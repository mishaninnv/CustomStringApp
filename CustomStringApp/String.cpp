#include "String.h"
#include <iostream>

namespace Custstr
{
	String::String(const char* str) {
		length = static_cast<int>(strlen(str));
		buffer = (char*)malloc((length + 1) * sizeof(char));
		if (buffer != 0)
		{
			strcpy_s(buffer, length + 1, str);
		}
	}

	String::String(const String& other) {
		length = other.length;
		buffer = (char*)malloc((length + 1) * sizeof(char));
		if (buffer != 0)
		{
			strcpy_s(buffer, other.Length() + 1, other.CStr());
		}
	}

	String& String::operator=(const String& other) {
		if (this != &other) {
			free(buffer);
			length = other.length;
			buffer = (char*)malloc((length + 1) * sizeof(char));
			if (buffer != 0)
			{
				strcpy_s(buffer, other.Length() + 1, other.CStr());
			}
		}
		return *this;
	}

	String::String(String&& other) noexcept {
		length = other.length;
		buffer = other.buffer;
		other.length = 0;
		other.buffer = nullptr;
	}

	String& String::operator+=(const char* str) {
		int newLength = length + strlen(str);
		char* newBuffer = (char*)malloc((newLength + 1) * sizeof(char));

		if (newBuffer != 0)
		{
			strcpy_s(newBuffer, Length() + 1, CStr());
			strcat_s(newBuffer, newLength + 1, str);
		}

		free(buffer);
		buffer = newBuffer;
		length = newLength;

		return *this;
	}

	String operator+(const String& str1, const String& str2) {
		String result(str1);
		result += str2.CStr();
		return result;
	}

	int String::Length() const {
		return length;
	}

	const char* String::CStr() const {
		return buffer;
	}

	String::~String() {
		free(buffer);
	}
}