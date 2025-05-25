Дадена е класа Kurs во која се чуваат информации за име на курс (низа од знаци) и број на кредити (цел број).

Дадена е класа Student што содржи инфомрации за: индекс на студентот (цел број), низа од оценки на студентот (динамички
алоцирана низа на оценките кои претставуваат броеви од 5 до 10) и број на оценки.

Дадена е класа Predavach што содржи инфомрации за: име на предавачот (динамички алоцирана низа од знаци), листа од
курсеви кои ги предава предавачот (низа од објекти од класата Kurs) и број на курсеви (цел број).

Да се креира класа Demonstrator, со која се претставуваат студентите држат лабораториските вежби на некои курсеви.
Објектите од оваа класа треба да содржат инфомрации за: индекс на студентот, оценки на студентот, број на оценки, име на
демонстраторот, листа од курсеви, број на курсеви чии лабораторисски вежби ги држи студентот и број на часови во
неделата кога студентот држи лабораториски вежби (цел број). (5 поени)

За секој студент да се овозможат следните функции:

* getBodovi() - која враќа цел број кој го претставува број на бодови за даден студент. Студентите кои не се
  демонстратори
  имаат бодови кои го претставуваат процентот на преодни оценки на студентот. (На пример студент со оценки: 5 6 7 ќе има
  66 бодови (цел дел од 66.666...) затоа што во 66% од оценките има оценка поголема од 5 ). Кај секој демонстратор на
  овие
  бодовите од оценките се додаваат бодовите од лабораториските вежби: (20*C)/N, каде N e бројот на курсеви кои ги држи,
  C
  бројот на часови во неделата кога студентот држи лабораториски вежби. Во случај кога некој демонстратор не држи ниту
  еден курс се фрла исклучокот NoCourseException. Справување со исклучокот треба да реализира онаму каде што е потребно
  и
  притоа да се испечати соодветна порака за грешка "Demonstratorot so indeks XXXX ne drzi laboratoriski vezbi", каде
  XXXX
  е индексот на демонстраторот. (15 поени)

* pecati()- во која се печати само индексот на студентот ако студентот не е демонстратор, а во случај кога студентот е
  демонстратор во продолжение се печатат информации за курсевите чии лабораториски вежби ги држи демонстраторот. (10
  поени)

Форматот за печатење е:

```
Indeks: ime (Kurs1 Krediti1 ECTS, Kurs2 Krediti2 ECTS,...)
```

Да се имплементираат следните глобални функции:

* Student& vratiNajdobroRangiran(Student ** studenti, int n ) што враќа референца кон студентот кој има најмногу бодови
  од
  листата на дадените n студенти (studenti). Да забележиме дека оние демонстратори кои не држат лабораториски вежби ќе
  земеме дека имаат 0 бодови. Да забележиме и дека во примерите секогаш има точно еден студент кој има најголем број на
  бодови. (15 поени)
* void pecatiDemonstratoriKurs (char* kurs, Student** studenti, int n) - која од дадена листа на студенти, ќе ги
  испечати
  само оние кои држат лабораториски вежби на курсот kurs. (10 поени)
  Комплетна функционалност на програмата. (5 поени)

```
Input:
2
123456 3 10 5 9

Output:
-----TEST pecati-----
123456
```

```
Input:
4
123456 5 5 6 7 5 8
T.Test 2 OOP 6 Angliski 2
10

Output:
-----TEST getVkupnaOcenka-----
Broj na bodovi: 160
```

```
Input:	
7
4
1 11111 3 10 5 8
2 11444 4 5 6 6 6 T.Test 0 0
1 22222 3 10 9 8
2 33333 5 5 6 5 5 5 T2.Test2 5 OOP 6 Angliski 2 Kalkulus 6 DMatematika 6 Infromatika 3 10

Output:
-----TEST vratiNajdobroRangiran-----
Demonstratorot so indeks 11444 ne drzi laboratoriski vezbi
Maksimalniot broj na bodovi e:100
Najdobro rangiran:22222
```

```
Input:	
3
11133 3 10 5 9

Output:
-----TEST getVkupnaOcenka-----
Broj na bodovi: 66
```

```
Input:	
6
11020 5 10 6 7 10 10
T.Test 4 OOP 6 Angliski 2 Kalkulus 6 Dmatematika 6
12

Output:
-----TEST Student i Demonstrator-----
11020: T.Test (OOP 6ECTS, Angliski 2ECTS, Kalkulus 6ECTS, Dmatematika 6ECTS)
Broj na bodovi: 160
```

```
Input:	
8
5
2 55555 5 5 6 9 7 10 T.Test 3 OOP 6 Angliski 2 DMatematika 6 10
2 44444 3 5 7 9 T2.Test2 3 Informatika 3  OOP 6 Angliski 2 12
1 11111 3 10 5 8
1 22222 3 10 9 8
2 33333 5 5 6 10 10 10 T3.Test3 4 Angliski 2 Kalkulus 6 DMatematika 6 Infromatika 3 10
OOP

Output:
-----TEST pecatiDemonstratoriKurs-----
Demonstratori na OOP se:
55555: T.Test (OOP 6ECTS, Angliski 2ECTS, DMatematika 6ECTS)
44444: T2.Test (Informatika 3ECTS, OOP 6ECTS, Angliski 2ECTS)
```

```
Input:		
4
11020 5 5 6 5 5 5
T.Test 5 OOP 6 Angliski 2 Kalkulus 6 DMatematika 6 Infromatika 3
10

Output:
-----TEST getVkupnaOcenka-----
Broj na bodovi: 60
```

```
Input:		
5
11020 5 10 6 7 5 8
T.Test 5 OOP 6 Angliski 2 Kalkulus 6 DMatematika 6 Infromatika 3
10

Output:
-----TEST pecati -----
11020: T.Test (OOP 6ECTS, Angliski 2ECTS, Kalkulus 6ECTS, DMatematika 6ECTS, Infromatika 3ECTS)
```

```
Input:		
5
11020 5 10 6 7 5 8
T.Test 5 OOP 6 Angliski 2 Kalkulus 6 DMatematika 6 Infromatika 3
10

Output:
-----TEST Demonstrator-----
Objekt od klasata Demonstrator e kreiran
```

```
Input:		
7
3
1 11111 3 10 5 8
1 22222 3 10 9 8
2 33333 5 5 6 10 10 10
T.Test 5 OOP 6 Angliski 2 Kalkulus 6 DMatematika 6 Infromatika 3
10

Output:
-----TEST vratiNajdobroRangiran-----
Maksimalniot broj na bodovi e:120
Najdobro rangiran:33333: T.Test (OOP 6ECTS, Angliski 2ECTS, Kalkulus 6ECTS, DMatematika 6ECTS, Infromatika 3ECTS)
```