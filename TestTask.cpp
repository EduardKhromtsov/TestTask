// Комментарий.
#include <iostream>

int SearchSubstringInString(const char* const cStr, const char* const cSubStr, int iNum);

int main()
{
	setlocale(LC_ALL, "RU");

	const char* cString = "Searching for a substring in a string", * cSubstring = "substring"; // Объявляем массивы типа char: строку и подстроку.

	int iNumber = 0; // Номер вхождения в строку.

	for (int i = 1; iNumber != -1; ++i)
	{
		iNumber = SearchSubstringInString(cString, cSubstring, i);

		if (iNumber >= 0)
			std::cout << "Начало подстроки было найдено в ячейке символьного массива " << "[" << iNumber << "]" << "\n";
	}

}

int SearchSubstringInString(const char* const cStr, const char* const cSubstr, int iNum)
{
	int iLengthStr, iLengthSubstr; // Длины строк.

	// Находим размеры строки и подстроки.
	for (iLengthStr = 0; cStr[iLengthStr]; ++iLengthStr);
	for (iLengthSubstr = 0; cSubstr[iLengthSubstr]; ++iLengthSubstr);

	int i, j; // Счетчики для циклов.

	for (i = 0; i <= iLengthStr - iLengthSubstr; ++i) // Пока есть возможность поиска
	{
		/*Проверяем посимвольно совпадение.
		Если посимвольно совпадает по длине искомого, то вернем из функции номер ячейки, откуда начинается совпадение.
		Также учитываем нуль-терминатор('\0');*/
		for (j = 0; cStr[i + j] == cSubstr[j]; ++j);
		if (j - iLengthSubstr == 1 && i == iLengthStr - iLengthSubstr && !(iNum - 1)) return i;

		if (j == iLengthSubstr)
			if (iNum - 1) --iNum;
			else return i;
	}
	return -1; // Иначе вернем -1, если подстрока отсутствует.
}

