from math import sqrt

n, v1, v2 = [int(i) for i in input().split()]
x = [int(i) for i in input().split()]
x1, y1 = [int(i) for i in input().split()]

minim = x[1] / v1 + sqrt((x1-x[1])**2 + (y1)**2) / v2 #Время, если студен выйдет на первой остановке и побежит (если он быстрее автобуса)
res = 2
for i in range(2, n):
    t = x[i] / v1 + sqrt((x1-x[i])**2 + (y1)**2) / v2
    if t < minim:
        minim = t
        res = i + 1
    elif t == minim and sqrt((x1-x[res-1])**2 + (y1)**2) < sqrt((x1-x[i])**2 + (y1)**2):
        res = i+1
print(res)