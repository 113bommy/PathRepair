for i in range(int(input())):
    n = int(input());kol = 0; mas = list(map(int,input().split()))
    ost = 0;
    for i in mas:
        if i > 0:
            ost += 1
    ost1 = 0
    
    for i in range(n):
        #print(ost1)
        if (mas[i] < 0):
            if ost1 == 0:
                kol += abs(mas[i])
                mas[-1] -= abs(mas[i])
            else:
                if ost1 < abs(mas[i]):
                    k = abs(mas[i])-ost1
                    kol += k
                    ost1 = 0
                    mas[-1] -= k
                else:
                    ost1 -= abs(mas[i])
        else:
            ost1+= mas[i]
    print(kol)