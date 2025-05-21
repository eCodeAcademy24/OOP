# NBAPlayer

### NBAPlayer

Да се дефинира класа NBAPlayer за која ќе се чуваат:

* динамички алоцирана низа од карактери за името на играчот
* низа од максимум 40 карактери за тимот во кој играчот моментално настапува
* просечен број на поени на играчот оваа сезона (double)
* просечен број на асистенции на играчот оваа сезона (double)
* просечен број на скокови на играчот оваа сезона (double)

За потребите на класата да се дефинираат:

* default конструктор и конструктор со аргументи
* copy constructor и оператор =
* деструктор
* метод rating() кој го враќа рејтингот на кошаркарот кој се пресметува како:
  `45% од поените + 30% од асистенциите + 25% од скоковите`

* метод print() кој го печати играчот во следниот формат:

```
Име - тим
Points: поени
Assists: асистенции
Rebounds: скокови
Rating: рејтинг
```

### AllStarPlayer

Од претходната класа NBAPlayer да се изведе класата AllStarPlayer за која дополнително ќе се чуваат и:

* просечен број на поени на играчот од All Star натпреварите (double)
* просечен број на асистенции на играчот од All Star натпреварите (double)
* просечен број на скокови на играчот од All Star натпреварите (double)

За потребите на класата да се дефинираат:

* default конструктор
* конструктор кој прима објект од NBAPlayer и плус додатните информации (погледни main)
* конструктор кој ги прима сите аргументи (погледни main)
* copy constructor, оператор =, деструктор
* метод allStarRating() кој го враќа рејтингот на кошаркарот од All Star натпреварите и кој се пресметува како:
  `30% од поените + 40% од асистенциите + 30% од скоковите`

Да се препокријат методите:

* rating() кој го враќа просекот од обичниот рејтинг на кошаркарот и неговиот All Star рејтинг
* print() кој покрај основните информации за кошаркарот печати и:

```
All Star Rating: рејтингот од All Star натпреварите
New Rating: просечниот рејтинг
```

```
Input:
1
Nikola_Jokic Denver_Nuggets 18.3 6.1 10.6
Lonzo_Ball Los_Angeles_Lakers 10.2 7.2 6.9
Donovan_Mitchell Utah_Jazz 20.4 3.6 3.7
Ben_Simmons Philadelphia_76ers 16 8.2 8.2
Kristaps_Porzingis New_York_Knicks 22.7 1.2 6.6

Output:
NBA PLAYERS:
=====================================
Nikola_Jokic - Denver_Nuggets
Points: 18.3
Assists: 6.1
Rebounds: 10.6
Rating: 12.715
Lonzo_Ball - Los_Angeles_Lakers
Points: 10.2
Assists: 7.2
Rebounds: 6.9
Rating: 8.475
Donovan_Mitchell - Utah_Jazz
Points: 20.4
Assists: 3.6
Rebounds: 3.7
Rating: 11.185
Ben_Simmons - Philadelphia_76ers
Points: 16
Assists: 8.2
Rebounds: 8.2
Rating: 11.71
Kristaps_Porzingis - New_York_Knicks
Points: 22.7
Assists: 1.2
Rebounds: 6.6
Rating: 12.225
```
```
Input:
2
Carmelo_Anthony Oklahoma_City_Thunder 16.3 1.3 5.9 24.1 3 6.5
LeBron_James Cleveland_Cavaliers 27.7 9.2 8.7 27.2 7.2 7.4
James_Harden Houston_Rockets 30.6 8.7 5.4 23 6 5.1
Stephen_Curry Golden_State_Warriors 26.4 6.1 5.1 23.1 6.8 4.4
Giannis_Antetokounmpo Milwaukee_Bucks 27.1 4.8 10 17.2 3.8 7.5

Output:
NBA PLAYERS:
=====================================
Carmelo_Anthony - Oklahoma_City_Thunder
Points: 16.3
Assists: 1.3
Rebounds: 5.9
Rating: 9.2
LeBron_James - Cleveland_Cavaliers
Points: 27.7
Assists: 9.2
Rebounds: 8.7
Rating: 17.4
James_Harden - Houston_Rockets
Points: 30.6
Assists: 8.7
Rebounds: 5.4
Rating: 17.73
Stephen_Curry - Golden_State_Warriors
Points: 26.4
Assists: 6.1
Rebounds: 5.1
Rating: 14.985
Giannis_Antetokounmpo - Milwaukee_Bucks
Points: 27.1
Assists: 4.8
Rebounds: 10
Rating: 16.135
ALL STAR PLAYERS:
=====================================
Carmelo_Anthony - Oklahoma_City_Thunder
Points: 16.3
Assists: 1.3
Rebounds: 5.9
Rating: 9.2
All Star Rating: 10.38
New Rating: 9.79
LeBron_James - Cleveland_Cavaliers
Points: 27.7
Assists: 9.2
Rebounds: 8.7
Rating: 17.4
All Star Rating: 13.26
New Rating: 15.33
James_Harden - Houston_Rockets
Points: 30.6
Assists: 8.7
Rebounds: 5.4
Rating: 17.73
All Star Rating: 10.83
New Rating: 14.28
Stephen_Curry - Golden_State_Warriors
Points: 26.4
Assists: 6.1
Rebounds: 5.1
Rating: 14.985
All Star Rating: 10.97
New Rating: 12.9775
Giannis_Antetokounmpo - Milwaukee_Bucks
Points: 27.1
Assists: 4.8
Rebounds: 10
Rating: 16.135
All Star Rating: 8.93
New Rating: 12.5325
```

```
Input:
3
Carmelo_Anthony Oklahoma_City_Thunder 16.3 1.3 5.9 24.1 3 6.5
LeBron_James Cleveland_Cavaliers 27.7 9.2 8.7 27.2 7.2 7.4
James_Harden Houston_Rockets 30.6 8.7 5.4 23 6 5.1
Stephen_Curry Golden_State_Warriors 26.4 6.1 5.1 23.1 6.8 4.4
Giannis_Antetokounmpo Milwaukee_Bucks 27.1 4.8 10 17.2 3.8 7.5

Output:
ALL STAR PLAYERS:
=====================================
Carmelo_Anthony - Oklahoma_City_Thunder
Points: 16.3
Assists: 1.3
Rebounds: 5.9
Rating: 9.2
All Star Rating: 10.38
New Rating: 9.79
LeBron_James - Cleveland_Cavaliers
Points: 27.7
Assists: 9.2
Rebounds: 8.7
Rating: 17.4
All Star Rating: 13.26
New Rating: 15.33
James_Harden - Houston_Rockets
Points: 30.6
Assists: 8.7
Rebounds: 5.4
Rating: 17.73
All Star Rating: 10.83
New Rating: 14.28
Stephen_Curry - Golden_State_Warriors
Points: 26.4
Assists: 6.1
Rebounds: 5.1
Rating: 14.985
All Star Rating: 10.97
New Rating: 12.9775
Giannis_Antetokounmpo - Milwaukee_Bucks
Points: 27.1
Assists: 4.8
Rebounds: 10
Rating: 16.135
All Star Rating: 8.93
New Rating: 12.5325
```