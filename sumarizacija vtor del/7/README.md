# Festival

Да се дефинира класа Song во која ќе се чуваат информации за некоја песна, и тоа: наслов на песната (стринг), име и
презиме на авторот на песната (стринг), изведувач на песната (стринг), времетраење на песната (во секунди, цел број).

За класата да се дефинираат потребните конструктори, set() и get() методи, оператор за читање >>, како и метод void
print(ofstream& out), за печатење на информациите за песната во датотека што се предава како аргумент на методот (преку
ofstream објектот).

Да се дефинира класа Festival во која ќе се чуваат информации за некој музички фестивал, и тоа: име на фестивалот (
стринг), град во којшто се одржува фестивалот (стринг), датум на одржување (стринг; формат: ден/месец/година), како и
листа на песни пријавени за фестивалот (динамички алоцирана низа од објекти од класата Song, како и цел број n кој ја
означува големината на листата).

За класата Festival да се имплементираат:

* Потребните конструктори и деструктор
* Оператор -= за бришење на песна (објект од класата Song) од листата. Од листата се бришат сите песни со идентични
  податоци (исти: наслов, автор, изведувач и времетраење) како песната што е предадена како аргумент на операторот. Пред
  да се изведе бришење, да се провери дали листата е празна (да се спречи обидот за бришење на објект од празна листа,
  со
  печатење на соодветна порака: „Trying to delete from an empty list!“).
* Метод void print(ofstream& out), за печатење на информациите за фестивалот во датотека што се предава како аргумент на
  методот (преку ofstream објектот). Овој метод задолжително треба да го повика методот print од класата Song, за
  печатење
  на информациите за листата од песни.

* Оператор за читање >>

* Метод Festival notFromAuthor(string author) - кој како аргумент прима име и презиме на автор (еден стринг - author), а
  враќа нов објект од класата Festival кој во листата од песни ги содржи само оние песни чиј автор НЕ е author. (5 п.)

Дополнете ја main функцијата со следните барања:

Од датотеката vlezna.txt прочитајте ги информациите за фестивалот. Секој податок се наоѓа во засебен ред (прво се
зададени информациите за самиот фестивал, па бројот на пријавени песни, па на крајот и информациите за секоја песна што
е пријавена за фестивалот). Информациите се вчитуваат директно во објектот festival.
Во датотеката izlezna1.txt се печатат сите информации за фестивалот и сите песни.

Во датотеката izlezna2.txt се печатат информациите само за оние песни чиј автор НЕ е авторот author, вчитан во почетниот
код.

```
Input:
Ohridski Trubaduri
Ohrid
30/08/2024
2
Usni na usni
Grigor Koprov
Toshe Proeski
215
Tvoeto pismo moja Biblija
Damir Imeri
Andrijana Janevska
198
----
Grigor Koprov

Output:
All the data for the festival:
Festival: Ohridski Trubaduri - Ohrid, 30/08/2024
Song title: Usni na usni, Author: Grigor Koprov, Interpreted by: Toshe Proeski, 215 sek.
Song title: Tvoeto pismo moja Biblija, Author: Damir Imeri, Interpreted by: Andrijana Janevska, 198 sek.
Songs NOT from the author Grigor Koprov:
Festival: Ohridski Trubaduri - Ohrid, 30/08/2024
Song title: Tvoeto pismo moja Biblija, Author: Damir Imeri, Interpreted by: Andrijana Janevska, 198 sek.
```

```
Input:
Empty Festival
No city
XX/XX/XXXX
0
----
Grigor Koprov

Output:
Trying to delete from an empty list!
All the data for the festival:
Festival: Empty Festival - No city, XX/XX/XXXX
Songs NOT from the author Grigor Koprov:
Festival: Empty Festival - No city, XX/XX/XXXX
```

```
Input:
Coachella Valley Music and Arts Festival
Indio, California
12/04/2024
3
Bohemian Rhapsody
Freddie Mercury
Queen
360
Shape of You
Ed Sheeran
Ed Sheeran
240
Billie Jean
Michael Jackson
Michael Jackson
300
----
Ed Sheeran

Output:
All the data for the festival:
Festival: Coachella Valley Music and Arts Festival - Indio, California, 12/04/2024
Song title: Bohemian Rhapsody, Author: Freddie Mercury, Interpreted by: Queen, 360 sek.
Song title: Shape of You, Author: Ed Sheeran, Interpreted by: Ed Sheeran, 240 sek.
Song title: Billie Jean, Author: Michael Jackson, Interpreted by: Michael Jackson, 300 sek.
Songs NOT from the author Ed Sheeran:
Festival: Coachella Valley Music and Arts Festival - Indio, California, 12/04/2024
Song title: Bohemian Rhapsody, Author: Freddie Mercury, Interpreted by: Queen, 360 sek.
Song title: Billie Jean, Author: Michael Jackson, Interpreted by: Michael Jackson, 300 sek.
```

```
Input:
Festival Name
City of Festival
25/06/2024
3
Song Title 1
Author 1
Singer 1
180
Song Title 2
Author 2
Singer 2
210
Song Title 3
Author 1
Singer 3
190
----
Author 1

Output:
All the data for the festival:
Festival: Festival Name - City of Festival, 25/06/2024
Song title: Song Title 1, Author: Author 1, Interpreted by: Singer 1, 180 sek.
Song title: Song Title 2, Author: Author 2, Interpreted by: Singer 2, 210 sek.
Song title: Song Title 3, Author: Author 1, Interpreted by: Singer 3, 190 sek.
Songs NOT from the author Author 1:
Festival: Festival Name - City of Festival, 25/06/2024
Song title: Song Title 2, Author: Author 2, Interpreted by: Singer 2, 210 sek.
```

```
Input:
Glastonbury Festival
Pilton, Somerset, England
26/06/2024
10
Bohemian Rhapsody
Freddie Mercury
Queen
360
Shape of You
Ed Sheeran
Ed Sheeran
240
Billie Jean
Michael Jackson
Michael Jackson
300
Hey Jude
Paul McCartney
The Beatles
360
Stairway to Heaven
Jimmy Page
Led Zeppelin
480
Purple Rain
Prince
Prince and The Revolution
300
Imagine
John Lennon
John Lennon
180
Hotel California
Don Felder
Eagles
360
Smells Like Teen Spirit
Kurt Cobain
Nirvana
300
Thriller
Rod Temperton
Michael Jackson
420
----
Michael Jackson

Output:
All the data for the festival:
Festival: Glastonbury Festival - Pilton, Somerset, England, 26/06/2024
Song title: Bohemian Rhapsody, Author: Freddie Mercury, Interpreted by: Queen, 360 sek.
Song title: Shape of You, Author: Ed Sheeran, Interpreted by: Ed Sheeran, 240 sek.
Song title: Billie Jean, Author: Michael Jackson, Interpreted by: Michael Jackson, 300 sek.
Song title: Hey Jude, Author: Paul McCartney, Interpreted by: The Beatles, 360 sek.
Song title: Stairway to Heaven, Author: Jimmy Page, Interpreted by: Led Zeppelin, 480 sek.
Song title: Purple Rain, Author: Prince, Interpreted by: Prince and The Revolution, 300 sek.
Song title: Imagine, Author: John Lennon, Interpreted by: John Lennon, 180 sek.
Song title: Hotel California, Author: Don Felder, Interpreted by: Eagles, 360 sek.
Song title: Smells Like Teen Spirit, Author: Kurt Cobain, Interpreted by: Nirvana, 300 sek.
Song title: Thriller, Author: Rod Temperton, Interpreted by: Michael Jackson, 420 sek.
Songs NOT from the author Michael Jackson:
Festival: Glastonbury Festival - Pilton, Somerset, England, 26/06/2024
Song title: Bohemian Rhapsody, Author: Freddie Mercury, Interpreted by: Queen, 360 sek.
Song title: Shape of You, Author: Ed Sheeran, Interpreted by: Ed Sheeran, 240 sek.
Song title: Hey Jude, Author: Paul McCartney, Interpreted by: The Beatles, 360 sek.
Song title: Stairway to Heaven, Author: Jimmy Page, Interpreted by: Led Zeppelin, 480 sek.
Song title: Purple Rain, Author: Prince, Interpreted by: Prince and The Revolution, 300 sek.
Song title: Imagine, Author: John Lennon, Interpreted by: John Lennon, 180 sek.
Song title: Hotel California, Author: Don Felder, Interpreted by: Eagles, 360 sek.
Song title: Smells Like Teen Spirit, Author: Kurt Cobain, Interpreted by: Nirvana, 300 sek.
Song title: Thriller, Author: Rod Temperton, Interpreted by: Michael Jackson, 420 sek.
```