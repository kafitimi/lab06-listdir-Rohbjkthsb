#include <windows.h>
#include <stdio.h>
#pragma warning( disable : 4996)

static int count;
static long long size;

void dfs() {
	// �������� ������� ������ � ����� � ������� �����
	// 1) ����� . � .. ����������
	// 2) ���� �����, �� ������� � ��� � �������� dfs
	// 3) ���� ����, �� ��������� ��� � ������ count � size
	// 4) ������� � ������������ �����

	HANDLE hFind;                   	// ����� ������
	WIN32_FIND_DATA res;            	// ��������� ������

	hFind = FindFirstFile(L"*", &res);   // ����� ������ ����

	do {
		count++; // ��������� ����� �� ���������??
		wprintf(L"file #%d is <%s>\n", count, res.cFileName);

		// if (...) { // ���� ��� ��������
		// 	����� ����� ����� � �������
		// }
		// else {// ��� ����
		// size+=res....
		// }
	} while (FindNextFile(hFind, &res) != 0);
	FindClose(hFind);
	SetCurrentDirectory(L"..");
}

int main(int argc, wchar_t* argv[]) {
	wchar_t s[512];               	// ������� �����
	GetCurrentDirectory(512, s);  	// �������� ������� �����
	wprintf(L"Starting in: %s\n", s);

	count = 0;                  	// �������� ������� ������
	size = 0;                   	// �������� ��������� ������ ������
	dfs();                      	// ��������� ����� � ������� �� ������� �����

	printf("File count = %d, size = %lld\n", count, size);
	return 0;
}

//ololo

/*
#include "windows.h"
#include "stdio.h"
#pragma warning( disable : 4996)

static int count;


int main() {
    	wchar_t s[512];              	// ������� �����
    	GetCurrentDirectory(512, s);	// �������� ������� �����
    	wprintf(L"Starting in: %s\n", s);

    	count = 0;                  	// �������� ������� ������    	

		HANDLE hFind;
		WIN32_FIND_DATA fileinfo;
		hFind = FindFirstFile(L"*", &fileinfo);
		wprintf(L"%s\n", fileinfo.cFileName);
        //dfs();                     	// ��������� ����� � �������
		do {
			count++; // ��������� ����� �� ���������??
			wprintf(L"%s\n", fileinfo.cFileName);

			// ...
			// ����� ����� ����� � �������
		} while (FindNextFile(hFind, &fileinfo) != 0);
		FindClose(hFind);
    	wprintf(L"File count = %d\n", count);
    	return 0;
}

void dfs() {
	HANDLE hFind;                   	// ����� ������
	WIN32_FIND_DATA res;            	// ��������� ������

	CHAR dir[] = ".\\*";
	hFind = FindFirstFile(dir, &res);   // ����� ������ ����

	do {
    	count++; // ��������� ����� �� ���������??
    	_tprintf(TEXT("file #%d is <%s>\n"), count, res.cFileName);

    	// ...
    	// ����� ����� ����� � �������
	} while (FindNextFile(hFind, &res) != 0);
	FindClose(hFind);
}

*/
