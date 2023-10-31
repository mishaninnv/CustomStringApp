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

		// Конструктор копирования
		String(const String& other);

		// Оператор присваивания
		String& operator=(const String& other);

		// Move-семантика
		String(String&& other) noexcept;

		// Оператор +=
		String& operator+=(const char* str);

		// Внешний оператор сложения двух строк
		friend String operator+(const String& str1, const String& str2);

		// Деструктор
		~String();

		int Length() const;
		const char* CStr() const;
	};
}

#endif