Да се дефинира класата `Pesna` во која се чуваат информации за:

* име на песна (динамички алоцирано поле од знаци)
* времетраење на песната во минути
* тип на песна кој може да биде: поп, рап или рок (енумерација tip)

Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата.

Дополнително за оваа класа да се дефинира методот:

* `pecati()` - функција во која ќе се печатат одделени со цртичка(-): името на песната во наводници и времетраењето на
  песната со постфикс min.

Да се креира класата `CD` во која се чуваат информации за:

* низа од песни снимени на CD-то (Поле од најмногу 10 објекти од класата Pesna )
* број на песни снимени на CD-то
* максимално времетраење на песните на CD-то (во минути)

Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата.

Дополнително за оваа класа да се дефинираат методите:

* `dodadiPesna (Pesna p)` - со кој се додава песната p на CDто, но само ако има доволно преостанато место (земајќи го
  предвид максималното времетраење на песните на CDто и времетраењата на песните на CD-то) и ако има помалку од 10 песни
  на CD-то. (10 поени)
* `pecatiPesniPoTip(tip t)` – со кој се печатат информациите за сите песни од тип t (поп, рап или рок).

```
Влез:
3
4
Happy 5 0
Layla 8 2
Stan 4 1
Revolution 7 2
Излез:
===== Testiranje na metodot dodadiPesna() od klasata CD ======
"Happy"-5min
"Layla"-8min
"Stan"-4min
```

```
Влез:
2
4
Happy 5 0
Layla 2 2
Stan 2 1
Revolution 3 2
Излез:
===== Testiranje na klasata CD ======
"Happy"-5min
"Layla"-2min
"Stan"-2min
"Revolution"-3min
```

```
Влез:
5
4
Happy 5 0
Layla 8 2
Stan 4 1
Revolution 7 2
2
Излез:
===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======
"Layla"-8min
```

```
Влез:
	
5
11
Happy 1 0
Layla 1 2
Stan 1 1
Revolution 1 2
Love 1 0
Life 1 0
Photograph 1 2
Listen 1 0
Anaconda 1 1
Game 1 1
Hello 1 0
0
Излез:
===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======
"Happy"-1min
"Love"-1min
"Life"-1min
"Listen"-1min
```

```
Влез:
5
4
Happy 5 0
Layla 8 2
Stan 4 1
Revolution 7 2
1
Излез:
===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======
"Stan"-4min
```

```
Влез:
1
Happy 5 0
Излез:
===== Testiranje na klasata Pesna ======
"Happy"-5min
```

```
Влез:
4
4
Happy 5 0
Layla 2 2
Stan 2 1
Revolution 3 2
2
Излез:
===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======
"Layla"-2min
"Revolution"-3min
```