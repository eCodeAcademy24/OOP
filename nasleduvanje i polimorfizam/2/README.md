# Kvadrat

Да се дефинира класата Kvadrat во која што се чува информација за:

* должината на страната а на квадратот (double)

За класата да се дефинираат:

* default конструктор
* конструктор со аргументи
* copy конструктор
* double perimetar () што пресметува периметар на квадратот
* double plostina () што пресметува плоштина на квадратот
* void pecati () што печати информации за квадратот како во тест примерите

Да се имплементира класа Pravoagolnik што наследува од класата Kvadrat. Во неа се чуваат дополнителни информации за:

* проширувањето x на двете паралелни страни на квадратот (double)
* проширувањето у на другите две паралелни страни (double)

Правоаголникот всушност сега ќе има 2 страни со должина a+x и две страни со должина a+y.

За класата да се дефинираат:

* default конструктор
* конструктор Pravoagolnik (const Kvadrat &k, double x, double y)
* copy конструктор

Да се препокријат трите методи дефинирани погоре за класата Kvadrat.

Напомени:

Ако x и y се исти, тогаш формата не е правоаголник туку е повторно квадрат. Во тој случај pecati() се повикува исто како за квадрат.
При препокривање на методите во класата Pravoagolnik мора да има повик кон истоимените методи од класата Kvadrat

```
Input:
5
4.5
4
10
17.5
8.9
1 2
1.5 2.5
3 4.5
7 7
8 9
2

Output:
===Testiranje na klasata Pravoagolnik===
Pravoagolnik so strani: 5.5 i 6.5 ima plostina P=35.75 i perimetar L=24
Pravoagolnik so strani: 5.5 i 6.5 ima plostina P=35.75 i perimetar L=24
Pravoagolnik so strani: 13 i 14.5 ima plostina P=188.5 i perimetar L=55
Kvadrat so dolzina a=24.5 ima plostina P=600.25 i perimetar L=98
Pravoagolnik so strani: 16.9 i 17.9 ima plostina P=302.51 i perimetar L=69.6
```

```
Input:
5
4.5
4
10
17.5
8.9
1 2
1.5 2.5
3 4.5
7 7
8 9
1

Output:
===Testiranje na klasata Kvadrat===
Kvadrat so dolzina a=4.5 ima plostina P=20.25 i perimetar L=18
Kvadrat so dolzina a=4 ima plostina P=16 i perimetar L=16
Kvadrat so dolzina a=10 ima plostina P=100 i perimetar L=40
Kvadrat so dolzina a=17.5 ima plostina P=306.25 i perimetar L=70
Kvadrat so dolzina a=8.9 ima plostina P=79.21 i perimetar L=35.6
```