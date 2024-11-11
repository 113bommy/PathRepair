from math import *

n = int(input())
r = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

co = 0
co2 = 0
for i in range(n):
    if r[i] > b[i]:
        co += 1
    elif r[i] < b[i]:
        co2 += 1
if co == 0:
    print(-1)
elif co2 >= co:
    lb = 0
    ub = 10**20
    while lb + 1 < ub:
        tx = (ub + lb) // 2
        dx = (ub - lb) // 2
        if tx*co > co2 + 1:
            ub -= dx
        else:
            lb += dx
    tx = (ub + lb) // 2
    for i in range(3):
        if tx*co <= co2:
            tx += 1
        elif (tx - 1)*co > co2:
            tx -= 1
    print(tx)
else:
    print(1)
 
