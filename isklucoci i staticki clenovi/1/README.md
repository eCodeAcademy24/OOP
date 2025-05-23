# Customer

Да се креира класа Customer за опишување на купувачи на една книжара. За секој купувач се чуваат податоци за:

* името (низа од 50 знаци),
* електронска адреса (низа од 50 знаци),
* вид на купувач (стандардни, лојални или вип),
* основен попуст (цел број изразен во проценти),
* дополнителен попуст (цел број изразен во проценти) и
* број на купени производи.

Сите лојални купувачи со покажување на клуб картичка имаат право на основниот попуст при купување од книжарата.
Основниот попуст е ист за сите лојални купувачи и изнесува 10%. Оваа вредност може да се смени со одлука на
раководството на книжарата. Дополнителниот попуст е фиксен и може да го користат само вип купувачите и изнесува 20%.
Стандардните купувачи немаат право на попуст.

За оваа класа да се имплементира оператор << за печатење на купувач во формат:

```
[ime_na_kupuvac]
[email_na_kupuvac
[broj_na_proizvodi]
[vid_na_kupuvac] [popust_sto_moze_da_go_koristi]
```

каде попустот е 0% ако купувачот е стандарден, вредноста на основниот попуст, ако е лојален или збир од основниот и
дополнителниот попуст, ако купувачот е вип.

Да се креира класа за онлајн книжара ECODE-bookstore во која се чува низа од регистрирани купувачи (динамички алоцирана
низа) и број на купувачи. За класата да се обезбедат:

* operator+= (10 поени) за додавање купувач во листата од купувачи, но само ако веќе не е дел од неа (ако во листата
  нема
  купувач со иста електронска адреса). Ако во листата постои корисник со иста електронска адреса, треба да се генерира
  исклучок UserExistsException. Потребно е да се обезбеди справување со исклучокот во функцијата main на означеното
  место.
  Во ваква ситуација се печати порака "The user already exists in the list"
* Функција update со која сите стандардни купувачи со купени повеќе од 5 производи стануваат лојални, а сите лојални
  купувачи со над 10 купени производи, стануваат вип
* Оператор << за печатење на информациите за сите регистрирани купувачи .
  Да се обезбедат сите дополнителни методи потребни за правилно функционирање на програмата.

```
Input:
6
5
Albert Einstein
einstein@ecode.mk
1
2
Isaac Newton
newton@ecode.mk
2
10
Galileo Galilei
galilei@ecode.mk
1
12
Stephen Hawking
hawking@ecode.mk
0
17
Nikola Tesla
tesla@ecode.mk
0
7

Output:
===== Test Case - update method  ======

Update:
Albert Einstein
einstein@ecode.mk
2
loyal 10
Isaac Newton
newton@ecode.mk
10
vip 30
Galileo Galilei
galilei@ecode.mk
12
vip 30
Stephen Hawking
hawking@ecode.mk
17
loyal 10
Nikola Tesla
tesla@ecode.mk
7
loyal 10
```

```
Input:
3
3
Albert Einstein
einstein@ecode.mk
1
2
Isaac Newton
newton@ecode.mk
2
10
Galileo Galilei
galilei@ecode.mk
0
10

Output:
===== Test Case - ECODE-bookstore ======
Albert Einstein
einstein@ecode.mk
2
loyal 10
Isaac Newton
newton@ecode.mk
10
vip 30
Galileo Galilei
galilei@ecode.mk
10
standard 0
```

```
Input:	
4
3
Albert Einstein
einstein@ecode.mk
1
2
Isaac Newton
newton@ecode.mk
2
10
Galileo Galilei
galilei@ecode.mk
0
10
Stephen Hawking
hawking@ecode.mk
2
17

Output:
===== Test Case - operator+= ======
OPERATOR +=
Albert Einstein
einstein@ecode.mk
2
loyal 10
Isaac Newton
newton@ecode.mk
10
vip 30
Galileo Galilei
galilei@ecode.mk
10
standard 0
Stephen Hawking
hawking@ecode.mk
17
vip 30
```

```
Input:	
2
Albert Einstein
einstein@ecode.mk
1
2

Output:
===== Test Case - Static Members ======
===== CONSTRUCTOR ======
Albert Einstein
einstein@ecode.mk
2
loyal 10
Albert Einstein
einstein@ecode.mk
2
loyal 5
```

```
Input:	
1
Albert Einstein
einstein@ecode.mk
1
2

Output:
===== Test Case - Customer Class ======
===== CONSTRUCTOR ======
Albert Einstein
einstein@ecode.mk
2
loyal 10
```

```
Input:		
5
4
Albert Einstein
einstein@ecode.mk
1
2
Isaac Newton
newton@ecode.mk
2
10
Galileo Galilei
galilei@ecode.mk
0
10
Stephen Hawking
hawking@ecode.mk
2
17
Al Ein
einstein@ecode.mk
0
3

Output:
===== Test Case - operator+= (exception) ======
OPERATOR +=
The user already exists in the list!
Albert Einstein
einstein@ecode.mk
2
loyal 10
Isaac Newton
newton@ecode.mk
10
vip 30
Galileo Galilei
galilei@ecode.mk
10
standard 0
Stephen Hawking
hawking@ecode.mk
17
vip 30
```