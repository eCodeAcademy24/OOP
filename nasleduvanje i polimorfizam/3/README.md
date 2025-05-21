# Nedviznina

Да се развие класа Nediviznina за коjа се чуваат следниве информации:

* адреса (динамички алоцирана низа од знаци)
* квадратура (цел боj)
* цена за квадрат (цел боj)

За оваа класа да се имплементираат соодветните конструктори и следните методи:

* cena() коj ќе jа враќа цената на недвижнината (квадратура * цена-за-квадрат)
* pecati() коj ќе ги испечати сите информации за истата
* danokNaImot() коj го ваќа данокот што се плаќа за недвижнината, а истиот се пресметува како 5% од цената на
  недвижнината.

Од оваа класа да се изведе класа Vila за коjа дополнително се чува:

* данок на луксуз (цел броj, пр. 10%).

За оваа класа да се преоптоварат методите:

* pecati()
* danokNaImot() со тоа што пресметаниот данок се зголемува процентуално за данокот на луксуз.

И за двете класи треба да се преоптовари operator >>.

```
Input:
Kukja_vo_Centar
60
850
Vila_na_Vodno
110
1120
10

Output:
Kukja_vo_Centar, Kvadratura: 60, Cena po Kvadrat: 850
Danok za: Kukja_vo_Centar, e: 2550
Vila_na_Vodno, Kvadratura: 110, Cena po Kvadrat: 1120, Danok na luksuz: 10
Danok za: Vila_na_Vodno, e: 18480
```

```
Input:
Stan_vo_Karposh
45
950
Vila_vo_Rasdishani
200
800
15

Output:
Stan_vo_Karposh, Kvadratura: 45, Cena po Kvadrat: 950
Danok za: Stan_vo_Karposh, e: 2137.5
Vila_vo_Rasdishani, Kvadratura: 200, Cena po Kvadrat: 800, Danok na luksuz: 15
Danok za: Vila_vo_Rasdishani, e: 32000
```

```
Input:
Stan_vo_N.Lisice
35
900
Vila_vo_Zlokukjani
150
700
5

Output:
Stan_vo_N.Lisice, Kvadratura: 35, Cena po Kvadrat: 900
Danok za: Stan_vo_N.Lisice, e: 1575
Vila_vo_Zlokukjani, Kvadratura: 150, Cena po Kvadrat: 700, Danok na luksuz: 5
Danok za: Vila_vo_Zlokukjani, e: 10500
```