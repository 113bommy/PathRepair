from collections import Counter
for _ in range(int(input())):
    i_liczb = int(input())
    liczby = list(map(int, input().split()))
    conter = Counter(liczby)
    wynik = 0
    cos = True
    for x in range(101):
        if cos:
            if conter[x] >= 2:
                continue
            elif conter[x] == 1:
                cos = False
                wynik += x
            else:
                wynik += 2 * x
                break
        else:
            if conter[x] >= 1:
                continue
            else:
                wynik += x
                break
    print(wynik)