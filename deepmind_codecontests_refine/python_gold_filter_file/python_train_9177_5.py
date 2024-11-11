from  operator import itemgetter
n = int(input())
l = list(map(int, input().split()))
minus = -1
plus = -1
for i in range(n):
    if (l[i] < 0):
        if minus == -1:
            minus = i
        else:
            if (l[minus] > l[i]):
                minus = i
    if (l[i] > 0):
        if plus == -1:
            plus = i
        else:
            if (l[plus] < l[i]):
                plus = i
if (len(l) % 2 == 0 or (plus != -1 or minus != -1)):
    de = -1
    if (len(l) % 2 == 1):
        if (minus == -1): de = plus
        elif (plus == -1): de = minus
        elif (abs(l[minus]) - 1 > l[plus]):
            de = minus
        else:
            de = plus
    for i in range(n):
        if (l[i] > -1):
            l[i] = -l[i] - 1
        if i == de:
            l[i] = -l[i] - 1
for i in range(n): print(l[i], end=' ')