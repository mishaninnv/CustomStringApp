#pragma once

#ifndef STRING_H
#define STRING_H

namespace Custstr
{
	class String {
	private:
		char* buffer;
		int length;

	public:
		String(const char* str);

		// Copy constructor
		String(const String& other);

		// Assignment operator
		String& operator=(const String& other);

		// Move semantics
		String(String&& other) noexcept;

		// Operator +=
		String& operator+=(const char* str);

		// External addition operator for two strings
		friend String operator+(const String& str1, const String& str2);

		// Destructor
		~String();

		int Length() const;
		const char* CStr() const;
	};
}

#endif