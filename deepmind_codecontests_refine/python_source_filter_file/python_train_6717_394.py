from math import*
x = int(input())
n = 0
summ = 0
for i in range(x):
    res = pow(2,n+1)
    n = n + 1
    summ = summ + res
print(int(summ))
