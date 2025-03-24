Да се дефинира класа `IceCream` во која се чуваат податоци за:

* име (динамичка низа од знаци),
* состав (низа од знаци, најмногу 100)
* цена (децимален број),
* попуст (цел број, изразен во проценти) иницијална вредност 0.

За потребите на класата да се имплементираат:

* соодветни конструктори и деструктор (да се погледнат повиците во функцијата main)
* оператор << за печатење на податоците за сладоледот во следниов формат:
  `име: состав цена [цена на попуст]`

делот „цена на попуст“ се печати само ако за сладоледот се нуди попуст (вредноста на попустот е поголема од нула)

* оператор ++ во префикс нотација за зголемување на попустот за 5
* оператор + - за собирање на објект од класата IceCream со низа од знаци. Собирањето се реализира на начин што името на
  новиот сладолед се добива со спојување на името на сладоледот и низата од знаци одделени со „ + “. Цената на новиот
  сладолед се зголемува за 10, а попустот и составот на сладоледот остануваат исти.
* метод `void setDiscount(int discount)` со кој може да се смени вредноста на попустот. Дозволените вредности на
  попустот се
  во интервалот [0,100]
* метод `void setName(char* name)` со кој се менува името на сладоледот.

Да се креира класа `IceCreamShop` во која се чува:

* име на продавницата (низа од знаци, најмногу 50)
* динамички резервирано поле од објекти од класата IceCream
* број на сладоледи во полето (цел број).

За оваа класа да се обезбедат:

* соодветни конструктори и деструктор (погледнете ги повиците во main функцијата)
* оператор += за додавање нов објект од класата IceCream во полето
* оператор << за печатење на листа од сите сладоледи во продавницата. Прво се печати името на продавницата, а потоа се
  печатат податоците за сите сладоледи одделени со нов ред.

```
Влез:
3
Ecode Ice Cream
3
Strawberry Ice Cream in Lemon Bowls
Strawberry ice cream, Lemons
100
Caramel Apple Delight
Caramel Delight ice cream, Apples
120
Dreyer’s Ice Cream Blueberry Pie
French Vanilla ice cream, Graham cracker pie crust, blueberries
60
Излез:
====== TESTING IceCreamShop ======
CONSTRUCTOR
OPERATOR +=
Ecode Ice Cream
Strawberry Ice Cream in Lemon Bowls: Strawberry ice cream, Lemons 100 
Caramel Apple Delight: Caramel Delight ice cream, Apples 120 
Dreyer’s Ice Cream Blueberry Pie: French Vanilla ice cream, Graham cracker pie crust, blueberries 60
```

```
Влез:
2
Caramel Apple Delight
Caramel Delight ice cream, Apples
60
Caramel Apple Delight Ice Cream in Apples
Special Ice Cream
-40
Излез:
====== TESTING IceCream CONSTRUCTORS ======
CONSTRUCTOR
Caramel Apple Delight: Caramel Delight ice cream, Apples 60
COPY CONSTRUCTOR
Caramel Apple Delight: Caramel Delight ice cream, Apples 60
Caramel Apple Delight Ice Cream in Apples: Caramel Delight ice cream, Apples 60
OPERATOR =
Caramel Apple Delight Ice Cream in Apples: Caramel Delight ice cream, Apples 60
Special Ice Cream: Caramel Delight ice cream, Apples 60
```

```
Влез:
1
Strawberry Ice Cream in Lemon Bowls
Strawberry ice cream, Lemons
80
10
Caramel Apple Delight
Caramel Delight ice cream, Apples
60
20
Излез:
====== TESTING IceCream CLASS ======
CONSTRUCTOR
OPERATOR <<
Strawberry Ice Cream in Lemon Bowls: Strawberry ice cream, Lemons 80 (72)
Caramel Apple Delight: Caramel Delight ice cream, Apples 60 (48)
OPERATOR ++
Strawberry Ice Cream in Lemon Bowls: Strawberry ice cream, Lemons 80 (68)
OPERATOR +
Caramel Apple Delight + chocolate: Caramel Delight ice cream, Apples 70 (56)
```

```
Влез:
4
Ecode Ice Cream
3
Strawberry Ice Cream in Lemon Bowls
Strawberry ice cream, Lemons
100
Caramel Apple Delight
Caramel Delight ice cream, Apples
120
Dreyer’s Ice Cream Blueberry Pie
French Vanilla ice cream, Graham cracker pie crust, blueberries
80
Излез:
====== TESTING IceCreamShop CONSTRUCTORS ======
Ecode Ice Cream
Strawberry Ice Cream in Lemon Bowls: Strawberry ice cream, Lemons 100
Caramel Apple Delight: Caramel Delight ice cream, Apples 120
Dreyer’s Ice Cream Blueberry Pie: French Vanilla ice cream, Graham cracker pie crust, blueberries 80
Ecode fruits: strawberry ice cream, raspberry ice cream, blueberry ice cream 60

Ecode Ice Cream
Strawberry Ice Cream in Lemon Bowls: Strawberry ice cream, Lemons 100
Caramel Apple Delight: Caramel Delight ice cream, Apples 120
Dreyer’s Ice Cream Blueberry Pie: French Vanilla ice cream, Graham cracker pie crust, blueberries 80
```