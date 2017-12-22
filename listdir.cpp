#include <windows.h>
#include <stdio.h>
#pragma warning( disable : 4996)

static int count;
static long long size;

void dfs() {
	// начинает перебор файлов и папок в текущей папке
	// 1) папки . и .. пропускаем
	// 2) если папка, то заходим в нее и вызываем dfs
	// 3) если файл, то посчитаем его в суммах count и size
	// 4) выходим в родительскую папку

	HANDLE hFind;                   	// номер поиска
	WIN32_FIND_DATA res;            	// результат поиска

	hFind = FindFirstFile(L"*", &res);   // найти первый файл

	do {
		count++; // некоторые файлы не считаются??
		wprintf(L"file #%d is <%s>\n", count, res.cFileName);

		// if (...) { // если это подпапка
		// 	здесь будет обход в глубину
		// }
		// else {// это файл
		// size+=res....
		// }
	} while (FindNextFile(hFind, &res) != 0);
	FindClose(hFind);
	SetCurrentDirectory(L"..");
}

int main(int argc, wchar_t* argv[]) {
	wchar_t s[512];               	// текущая папка
	GetCurrentDirectory(512, s);  	// получить текущую папку
	wprintf(L"Starting in: %s\n", s);

	count = 0;                  	// обнулить счетчик файлов
	size = 0;                   	// обнулить суммарный размер файлов
	dfs();                      	// запустить обход в глубину из текущей папки

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
    	wchar_t s[512];              	// текущая папка
    	GetCurrentDirectory(512, s);	// получить текущую папку
    	wprintf(L"Starting in: %s\n", s);

    	count = 0;                  	// обнулить счетчик файлов    	

		HANDLE hFind;
		WIN32_FIND_DATA fileinfo;
		hFind = FindFirstFile(L"*", &fileinfo);
		wprintf(L"%s\n", fileinfo.cFileName);
        //dfs();                     	// запустить обход в глубину
		do {
			count++; // некоторые файлы не считаются??
			wprintf(L"%s\n", fileinfo.cFileName);

			// ...
			// здесь будет обход в глубину
		} while (FindNextFile(hFind, &fileinfo) != 0);
		FindClose(hFind);
    	wprintf(L"File count = %d\n", count);
    	return 0;
}

void dfs() {
	HANDLE hFind;                   	// номер поиска
	WIN32_FIND_DATA res;            	// результат поиска

	CHAR dir[] = ".\\*";
	hFind = FindFirstFile(dir, &res);   // найти первый файл

	do {
    	count++; // некоторые файлы не считаются??
    	_tprintf(TEXT("file #%d is <%s>\n"), count, res.cFileName);

    	// ...
    	// здесь будет обход в глубину
	} while (FindNextFile(hFind, &res) != 0);
	FindClose(hFind);
}

*/
