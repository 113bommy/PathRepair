"""

def Find(naj, mesto, dl):
    if naj >= 2:
        dl += 1
        Find(naj-2, mesto, dl)
    if naj >= 3:
        dl += 1
        Find(naj-3, mesto, dl)
    if naj >= 4 and len(mesto) == 4:
        dl += 1
        Find(naj-4, mesto, dl)
        dl += 1
        Find(naj-4, mesto, dl)
    global perem, kolvo
    if str(dl) in perem:
        kolvo[perem.index(str(dl))] += 1
    else:
        perem.append(str(dl))
        kolvo.append(1)


dlina = int(input())
sms = str(input())
KLAVA = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ']
najatiya = []
for i in sms:
    for f in range(len(KLAVA)):
        if i in KLAVA[f]:
            kek = KLAVA[f].index(i)+1
            if KLAVA[f].index(i)+1 <= 3:
                kek += 1
            najatiya.append([kek, KLAVA[f]])
#print(najatiya)
k = []
k.append(najatiya[0])
for i in range(1, len(najatiya)):
    if najatiya[i][1] == k[len(k)-1][1]:
        k[len(k)-1][0]+=najatiya[i][0]
    else:
        k.append(najatiya[i])
print(k)
gotovo = []
for i in range(len(k)):
    perem = []
    kolvo = []
    Find(k[i][0], k[i][1], 0)
    gotovo.append([perem, kolvo])
    #Даю ему кол-во нажатий и кнопку нажатия,
    #записываю длину сообщения,
    #записываю в массив длины сообщений,
    #набранных на одной кнопке и количество
    #одинаковых длин
    #решаю задачу цифры проходя по массиву длин
    #собираю количество возможных комбинаций
    #вывожу
print(gotovo)

def NaytiChisla(stroka):
    kek = ""
    chislo = []
    koef = 1
    for i in range(len(stroka)):
        if stroka[i] == '-':
            koef = -1
        if stroka[i] == '0' or stroka[i] == '1' or stroka[i] == '2' or stroka[i] == '3' or stroka[i] == '4' or stroka[i] == '5' or stroka[i] == '6' or stroka[i] == '7' or stroka[i] == '8' or stroka[i] == '9':
            kek+=stroka[i]
        if stroka[i] == ' ':
            chislo.append(int(kek)*koef)
            koef = 1
            kek = ""
    chislo.append(int(kek)*koef)
    koef = 1
    return chislo


su = int(input())
coins = NaytiChisla(str(input()))
su = int(input())
min = 10000000
mass = []
mass.append(0)
for i in range(su):
    lol = []
    for f in coins:
        if len(mass)-f-1 > 0 and len(mass)-f < len(mass)-1:
            lol.append(mass[len(mass)-f-1])
    try:
        kek = sorted(lol)[0]
    except:
        kek = 1000000
    mass.append(kek)
print(mass)
"""

def Kek():
    n, m = map(int, input().split())
    if n > m:
        i = 1
        f = m-1
        print(f, i, f-i)
        print(int((f-i+1)/2))
    else:
        if m <= 2*n:
            i = m-n
            f = n
            if i == 0:
                i = 2
            print(f, i, f - i)
            print(int((f-i+1)/2))
        else:
            print(0)
            return
    return


Kek()