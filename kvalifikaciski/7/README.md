# Book

Да се дефинира класа Book во која ќе се чуваат информации за:

Насловот на книгата (тип: string, со default вредност "TEST_BOOK")
Бројот на страници кои се прочитани (тип: integer, со default вредност 0)
За класата да се дефинираат:

Конструктори (согласно кодот во main методот)
readPages(int pages) - метод кој додава број на прочитани страници. Да се внимава прочитаните страници да не го надминат
вкупниот број на страници за 200.
print() - метод кој ги печати информациите за книгата во следниот формат:
TITLE - READ_PAGES/200 - STATUS, каде што статус може да биде:
IN PROGRESS (ако се прочитани помалку од 100 страници)
ALMOST DONE (ако се прочитани 100 или повеќе страници, но помалку од 200)
FINISHED (ако се прочитани сите 200 страници)

```
Input
print
readPages 50
print
readPages 60
print
readPages 100
print

Output
TEST_BOOK - 0/200 - IN PROGRESS
TEST_BOOK - 50/200 - IN PROGRESS
TEST_BOOK - 110/200 - ALMOST DONE
TEST_BOOK - 200/200 - FINISHED
```

```
Input
constructor1 "Harry_Potter" 50
print
readPages 30
print
readPages 150
print

Output
"Harry_Potter" - 50/200 - IN PROGRESS
"Harry_Potter" - 80/200 - IN PROGRESS
"Harry_Potter" - 200/200 - FINISHED
```

```
Input
constructor2 "Lord_of_the_Rings"
print
readPages 80
print
readPages 20
print
readPages 150
print

Output
"Lord_of_the_Rings" - 0/200 - IN PROGRESS
"Lord_of_the_Rings" - 80/200 - IN PROGRESS
"Lord_of_the_Rings" - 100/200 - ALMOST DONE
"Lord_of_the_Rings" - 200/200 - FINISHED
```