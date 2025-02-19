Да се дефинира класа Film, во која ќе се чуваат информации за:

* `име` низа од 100 знаци
* `режисер` низа од 50 знаци
* `жанр` низа од 50 знаци
* `година` цел број

Сите променливи треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:

* default конструктор и конструктор со аргументи
* метод за печатење на информациите за филмот

Дополнително да се реализира надворешна функција:

* `void pecati_po_godina(Film *f, int n, int godina)` која ќе прима аргумент низа од филмови, вкупниот број на филмови и
  година, а треба да ги отпечати само филмовите кои се направени во дадената година.

```
Влез:
  4
  Frankenweenie
  Tim_Burton
  Animation
  2012
  Lincoln
  Steven_Spielberg
  History
   2012
  Wall-E
  Andrew_Stanton
  Animation
  2008
  Avatar
  James_Cameron
  Fantasy
  2009
  2008
Излез:
  Ime: Wall-E
  Reziser: Andrew_Stanton
  Zanr: Animation
  Godina: 2008
```

```
Влез:
  5
  TheWolfofWallStreet
  Martin_Scorsese
  Biography
  2013
  Frozen
  Chris_Buck
  Animation
  2013
  Wall-E
  Andrew_Stanton
  Animation
  2008
  Avatar
  James_Cameron
  Fantasy
  2009
  2012:IceAge
  Travis_Fort
  Action
  2011
  2013
Излез:
  Ime: TheWolfofWallStreet
  Reziser: Martin_Scorsese
  Zanr: Biography
  Godina: 2013
  Ime: Frozen
  Reziser: Chris_Buck
  Zanr: Animation
  Godina: 2013
```
