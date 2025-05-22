# Vozilo

Да се дефинира класа Vozilo која ќе содржи информација за неговата маса (децимален број), ширина и висина (цели броеви).

Од оваа класа да се изведе класата Автомобил во која како дополнителна информација се чува информацијата за бројот на
врати (цел број).

Од класата возило да се изведе и класата Автобус во која се чуваат информации и за бројот на патници кои може да ги
пренесува.

Од класата возило да се изведе класата Камион во која се чуваат информации и за максималната маса која може да се товари
на него (децимална вредност).

За сите класи да се креираат погодни контруктори, како и set и get функции.

Да се дефинира класа ParkingPlac за која се чува динамичко алоцирано поле од покажувачи кон Vozilo, како и бројот на
елементи во полето. Во оваа класа да се дефинираат:

* конструктор
* деструктор
* операторот += за додавање на ново возило (аргументот е покажувач кон Vozilo)
* функција float presmetajVkupnaMasa() со која се пресметува вкупната маса на сите возила во паркинг плацот
* функција int brojVozilaPoshirokiOd(int l) со која се пресметува бројот на возила кои се пошироки од дадената вредност
* функција void pecati() со која се печати: Brojot na avtomobili e X, brojot na avtobusi e Y i brojot na kamioni e Z.
* функција int pogolemaNosivostOd(Vozilo& v) во која се враќа бројот на сите камиони кои имаат носивост поголема од
  масата
  на возилото предадено како аргумент.
* Да се дефинира виртуелна функција int vratiDnevnaCena() во класата Vozilo и истата да се преоптовари во сите изведени
  класи. За секој автомобил со помалку од 5 врати дневната цена е 100, а инаку е 130 денари. За секој камион цената се
  пресметува со формулата: (masa+nosivost)*0.02. За секој автобус цената е 5 денари по лице кое може да се пренесува.

Во класата ParkingPlac да се додаде следната функција: - функција int vratiDnevnaZarabotka() со која се враќа дневната
заработка од сите возила на паркингот.

```
Input:
5
1 1300 3 2 3
2 4500 10 4 45
3 6000 8 5 2000
1 2100 3 3 5
2 4200 9 5 52

Output:
Brojot na avtomobili e 2, brojot na avtobusi e 2 i brojot na kamioni e 1.

Zarabotkata e 875
Vkupnata masa e 18100
Brojot poshiroki od 5 e 3
Brojot na kamioni so nosivost pogolema od avtomobilot e 1
```

```
Input:	
7
1 1300 3 2 3
2 4500 10 4 45
3 6000 8 5 2000
1 2100 3 3 5
2 4200 9 5 52
2 4250 9 3 32
3 5900 11 5 2500

Output:
Brojot na avtomobili e 2, brojot na avtobusi e 3 i brojot na kamioni e 2.

Zarabotkata e 1203
Vkupnata masa e 28250
Brojot poshiroki od 5 e 5
Brojot na kamioni so nosivost pogolema od avtomobilot e 2
```

```
Input:
	
3
1 1300 3 2 3
2 4500 10 4 45
3 6000 8 5 2000

Output:
Brojot na avtomobili e 1, brojot na avtobusi e 1 i brojot na kamioni e 1.

Zarabotkata e 485
Vkupnata masa e 11800
Brojot poshiroki od 5 e 2
Brojot na kamioni so nosivost pogolema od avtomobilot e 1
```

