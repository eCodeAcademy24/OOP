Потребно е да се имплементираат класи File (датотека) и Folder (директориум) за работа со едноставен датотечен систем.

Во класата File треба да се чуваат следниве податоци:

* Име на датотеката (динамички алоцирана низа од знаци)
* Екстензија на датотеката (енумерација со можни вредности: txt, pdf, exe)
* Име на сопственикот на датотеката (динамички алоцирана низа од знаци)
* Големина на датотеката (цел број на мегабајти)

Дополнително, во класата потребно е да се напишат и:

* Конструктор без параметри
* Конструктор со параметри
* Конструктор за копирање
* Деструктор
* Преоптоварување на операторот =
* Метод за печатење на информациите за една датотека (видете го излезот од тест примерите за структурата на печатење) -
  `print()`
* Метод за проверка на еднаквост помеѓу две датотеки со потпис `bool equals(const File & that)` кој ќе враќа true ако
  датотеките имаат исто име, екстензија и сопственик
* Метод за споредба на типот помеѓу две датотеки со потпис `bool equalsType(const File & that)` кој ќе враќа true ако
  датотеките се од ист тип, т.е. имаат исто име и екстензија

Во класата Folder треба да се чуваат следниве податоци:

* Име на директориумот (динамички алоцирана низа од знаци)
* Број на датотеки во него (на почеток директориумот е празен)
* Динамички алоцирана низа од датотеки, објекти од класата File

Дополнително, во класата потребно е да се напишат и:

* Конструктор со потпис `Folder(const char* name)`
* Деструктор
* Метод за печатење на информациите за еден директориум (видете го излезот од тест примерите за структурата на
  печатење) -
  `print()`
* Метод за бришење на датотека од директориумот со потпис `void remove(const File & file)` кој ќе ја избрише првата
  датотека од директориумот која е еднаква според `equals` методот
* Метод за додавање на датотека во директориумот со потпис `void add(const File & file)` кој ќе додава датотеката во
  директориумот

```
Влез:
1
oop
Ecode
2
0
Излез:
======= FILE CONSTRUCTORS AND = OPERATOR =======
======= CREATED =======
File name: oop.pdf
File owner: Ecode
File size: 2

======= COPIED =======
File name: oop.pdf
File owner: Ecode
File size: 2

======= ASSIGNED =======
File name: oop.pdf
File owner: Ecode
File size: 2
```

```
Влез:
2
oop
Ecode
2
0
oop
Ecode
3
0
oop
Ecode
1
1
Излез:
======= FILE EQUALS AND EQUALS TYPE =======
File name: oop.pdf
File owner: Ecode
File size: 2
File name: oop.pdf
File owner: Ecode
File size: 3
File name: oop.txt
File owner: Ecode
File size: 1
FIRST EQUALS SECOND: TRUE
FIRST EQUALS THIRD: FALSE
FIRST EQUALS TYPE SECOND: TRUE
SECOND EQUALS TYPE THIRD: FALSE
```

```
Влез:	
4
results
3
oop
Ecode
2
0
oop
Ecode.mk
2
0
oop
Ecode.mk
2
1
Излез:
======= ADD FILE IN FOLDER =======
Folder name: results
File name: oop.pdf
File owner: Ecode
File size: 2
File name: oop.pdf
File owner: Ecode
File size: 2
File name: oop.txt
File owner: Ecode
File size: 2
```

```
Влез:
5
results
3
oop
Ecode
1
2
sp
Ecode
2
1
aps
Ecode
3
1
vp
Ecode
2
1
Излез:
======= REMOVE FILE FROM FOLDER =======
Folder name: results
File name: oop.exe
File owner: Ecode
File size: 1
File name: sp.txt
File owner: Ecode
File size: 2
```