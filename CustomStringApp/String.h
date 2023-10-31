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

		// ����������� �����������
		String(const String& other);

		// �������� ������������
		String& operator=(const String& other);

		// Move-���������
		String(String&& other) noexcept;

		// �������� +=
		String& operator+=(const char* str);

		// ������� �������� �������� ���� �����
		friend String operator+(const String& str1, const String& str2);

		// ����������
		~String();

		int Length() const;
		const char* CStr() const;
	};
}

#endif