### Лабораторная работа №1

Задачи:

* monotonic: В строках текстового файла записаны десятичные числа (не целые – т.е. может быть точка), разделённые пробелами и (или) символами перевода строки. Необходимо определить минимальное количество чисел, после удаления которых числовая последовательность станет монотонной.

* concat: Текстовый файл состоит из двух строк. Определить, есть ли во второй строке слова, которые не получаются путём конкатенации нескольких слов из первой строки.

* set:
Имеется два текстовых файла. Определить, может ли второй файл быть получен путём перестановки и дублирования некоторых строк первого файла.

* linear_system: Текстовый файл состоит из N строк, в каждой из которых записано N десятичных чисел A1,…,AN. Решить систему линейных уравнений AX=0

Общая функциональность вынесена в отдельные файлы, находящиеся в ./utils

Структура проектов:

* source: *.c файлы
* include: заголовочные файлы
* build: объектные файлы и само приложение taskname.out
* examples: примеры входных данных
