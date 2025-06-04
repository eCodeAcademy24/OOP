# Doctor

Да се дефинира апстрактна класа Doctor, во која се чуваат информации за:

- името на докторот (стринг)
- презимето на докторот (стринг)
- плата (децимален број)
- код (стринг)

Во рамките на оваа класа да се дефинираат два чисто виртуелни методи:

- float calculateSalary() - за пресметка на платата на еден доктор.
- void print() - за печатење на информациите за еден доктор.

Кодот на секој доктор е стринг со должина 8, кој мора да ја има таа должина и не смее да содржи запирка. Доколку кодот
на еден доктор не ги исполнува овие услови да се фрли исклучок од класата InvalidCodeFormatException. Со исклучокот
треба да се справите во главната програма, при секој обид за креирање објект. При справувањето со исклучокот да се
испечати соодветна порака.

Од класата Doctor да се изведат две класи: GeneralDoctor и Specialist, кои претставуваат матичен доктор и специјалист,
соодветно. За секој матичен доктор, дополнително се чува бројот на пациенти (цел број), а за секој специјалист
дополнително се чува неговата специјалност (стринг), бројот на неговите интервенции (цел број) и години искуство (цел
број).

Во изведените класи соодветно да се препокријат виртуелните методи. Форматот за печатење да се види од тест-примерите, а
пресметката на плата се прави на следниот начин:

- За GeneralDoctor - основна плата е 45000 денари. Дополнително, за секои 10 пациенти докторот добива по 3000 денари. Да
  се врати платата со пресметан персонален данок од 7%.
- За Specialist - основна плата е 55000 денари. За секоја интервенција, специјалистите добиваат по 85 денари плус на
  основната плата. Дополнително, за секоја година работно искуство, специјалистите добиваат по 5% бонус од основната
  плата. Да се врати платата со пресметан персонален данок од 7%.

Да се дефинира глобална функција со потпис: void findDoctorsPercentage(Doctor **doctors, int n), која како аргументи
прима низа од покажувачи кон доктори и нејзината големина. Функцијата треба да го испечати процентот на специјалисти и
процентот на матични доктори. Форматот да се види од тест примерите.

```
Input:
1

Output:
General Doctor: John Smith CODE:236XY@2B Salary: 75330
General Doctor: Marco Brown CODE:345X!Y2B Salary: 75330
General Doctor: Emily Johnson CODE:ABCD123@ Salary: 106020
GENERAL DOCTOR CLASS OK!
```

```
Input:
2

Output:
Specialist: Beth Davis CODE:96Tr$$33 Cardiologist Salary: 67494.8
Specialist: William Wilson CODE:785#Qy2B Pulmonologist Salary: 73005
Specialist: Micheal Rosen CODE:7896YZ$s Radiologist Salary: 79966
SPECIALIST DOCTOR CLASS OK!
```

```
Input:
3

Output:
TESTING EXCEPTION HANDLING
The code 23Y@2B is invalid doctor code format. THE CODE MUST BE 8 CHARACTERS LONG AND CANNOT CONTAIN COMMA.
EXCEPTION HANDLING OK!
```

```
Input:
4

Output:
TESTING EXCEPTION HANDLING
The code 9,R$$334 is invalid doctor code format. THE CODE MUST BE 8 CHARACTERS LONG AND CANNOT CONTAIN COMMA.
EXCEPTION HANDLING OK!
```

```
Input:
5

Output:
TESTING EXCEPTION HANDLING
The code 9,R$$334 is invalid doctor code format. THE CODE MUST BE 8 CHARACTERS LONG AND CANNOT CONTAIN COMMA.
Specialist: William Wilson CODE:785#Qy2B Pulmonologist Salary: 73005
The code 96Tr, is invalid doctor code format. THE CODE MUST BE 8 CHARACTERS LONG AND CANNOT CONTAIN COMMA.
EXCEPTION HANDLING OK!
```

```
Input:
6
7
1 John Smith 236XY@2B 120
2 Alice Johnson ABCD123@ Pediatrician 35 8
1 Michael Brown 345X!Y2B 150
2 Sarah Davis 785#Qy2B Cardiologist 42 6
1 Emily Wilson 96Tr$$33 200
2 William Parker 7896YZ$s Neurologist 38 10
1 Jessica Lee 1234ABCD 130

Output:
INTEGRATION TEST AND TESTING GLOBAL FUNCTION!
LIST OF ALL DOCTORS:
General Doctor: John Smith CODE:236XY@2B Salary: 75330
Specialist: Alice Johnson CODE:ABCD123@ Pediatrician Salary: 74376.8
General Doctor: Michael Brown CODE:345X!Y2B Salary: 83700
Specialist: Sarah Davis CODE:785#Qy2B Cardiologist Salary: 69815.1
General Doctor: Emily Wilson CODE:96Tr$$33 Salary: 97650
Specialist: William Parker CODE:7896YZ$s Neurologist Salary: 79728.9
General Doctor: Jessica Lee CODE:1234ABCD Salary: 78120
42.8571% of the doctors are specialists and 57.1429% are general doctors.
```

```
Input:
6
10
1 John Smith 236XY@2B 120
2 Alice Johnson ABCD123@ Pediatrician 35 8
1 Michael Brown 345X!Y2B 150
2 Sarah Davis 785#Qy2B Cardiologist 42 6
1 Emily Wilson 96Tr$$33 200
2 William Parker 7896YZ$s Neurologist 38 10
1 Jessica Lee 1234ABCD 130
2 David Miller 4567PQR$ Surgeon 55 12
1 Olivia Taylor MNBV0987 180
2 Daniel Clark 8901XYZ$ Orthopedist 40 9

Output:
INTEGRATION TEST AND TESTING GLOBAL FUNCTION!
LIST OF ALL DOCTORS:
General Doctor: John Smith CODE:236XY@2B Salary: 75330
Specialist: Alice Johnson CODE:ABCD123@ Pediatrician Salary: 74376.8
General Doctor: Michael Brown CODE:345X!Y2B Salary: 83700
Specialist: Sarah Davis CODE:785#Qy2B Cardiologist Salary: 69815.1
General Doctor: Emily Wilson CODE:96Tr$$33 Salary: 97650
Specialist: William Parker CODE:7896YZ$s Neurologist Salary: 79728.9
General Doctor: Jessica Lee CODE:1234ABCD Salary: 78120
Specialist: David Miller CODE:4567PQR$ Surgeon Salary: 86187.8
General Doctor: Olivia Taylor CODE:MNBV0987 Salary: 92070
Specialist: Daniel Clark CODE:8901XYZ$ Orthopedist Salary: 77329.5
50% of the doctors are specialists and 50% are general doctors.
```