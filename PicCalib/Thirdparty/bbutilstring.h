#pragma once
#include <stdarg.h>  // For va_start, etc.
#include <memory>    // For std::unique_ptr
#include <string>
#include <vector>
#include "mytime.h"
using namespace std;
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

inline static
std::string StringFormat2(const std::string fmt, ...)
{
	int size = ((int)fmt.size()) * 2; /* Reserve two times as much as the length of the fmt_str */
	std::string buffer;
	va_list ap;
	while (1) {
		buffer.resize(size);
		va_start(ap, fmt);
		int n = vsnprintf((char*)buffer.data(), size, fmt.c_str(), ap);
		va_end(ap);
		if (n > -1 && n < size) {
			buffer.resize(n);
			return buffer;
		}
		if (n > -1)
			size = n + 1;
		else
			size *= 2;
	}
	return buffer;
}

#ifdef __linux__
//linux code goes here
#include <unistd.h>
#elif WINDOWS
// windows code goes here
#include <windows.h>
#include <direct.h>
#include <time.h>
#else

#endif

inline static
inline std::string GetTimeString()
{
	time_t t = time(0);
	//struct tm* now = localtime(&t);
	struct tm now;
	localtime_s(&now, &t); //  �ʴ��� �ð����� ���� �Ͻø� ���ϴ� �Լ�

	struct timeval ts;
	gettimeofday(&ts, 0);
	double tu = ts.tv_usec;

	std::string ret = StringFormat2("%d%02d%02d_%02d%02d%02d_%.f", now.tm_year + 1900,
		now.tm_mon + 1,
		now.tm_mday,
		now.tm_hour,
		now.tm_min,
		now.tm_sec,
		tu);
	return ret;
}


// ����ð��� string type���� return�ϴ� �Լ�
inline static
const std::string currentDateTime() {
	time_t     now = time(0); //���� �ð��� time_t Ÿ������ ����
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	/*
	char bufch[255] = { 0, };
	memset(bufch, 0, 255);
	
	sprintf(bufch, "%d%02d%02d_%02d%02d%02d", tstruct.tm_year + 1900,
		tstruct.tm_mon + 1,
		tstruct.tm_mday,
		tstruct.tm_hour,
		tstruct.tm_min,
		tstruct.tm_sec);

	*/
	strftime(buf, sizeof(buf), "%Y%m%d.%X", &tstruct); // YYYY-MM-DD.HH:mm:ss ������ ��Ʈ��

	return std::string(buf);
}

inline static
std::string MakeFileNameWithTime(const std::string &ext)
{
	std::string ret = GetTimeString() + "." + ext;
	return ret;
}


// case insensitive equal
inline static
bool IsEqualStrings(const std::string& a, const std::string& b)
{
	size_t sz = a.size();
	if (b.size() != sz)
		return false;
	for (unsigned int i = 0; i < sz; ++i)
		if (tolower(a[i]) != tolower(b[i]))
			return false;
	return true;
}

// https://wiki.kldp.org/HOWTO/html/C++Programming-HOWTO/standard-string.html
inline static
void Tokenize(const std::string& str,
	std::vector<std::string>& tokens,
	const string& delimiters)
{
	// �� ù ���ڰ� �������� ��� ����
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// �����ڰ� �ƴ� ù ���ڸ� ã�´�
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// token�� ã������ vector�� �߰��Ѵ�
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// �����ڸ� �پ�Ѵ´�.  "not_of"�� �����϶�
		lastPos = str.find_first_not_of(delimiters, pos);
		// ���� �����ڰ� �ƴ� ���ڸ� ã�´�
		pos = str.find_first_of(delimiters, lastPos);
	}
}
