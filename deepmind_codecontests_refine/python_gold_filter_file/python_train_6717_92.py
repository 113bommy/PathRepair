from math import factorial

n = int(input())

a = 0
for i in range(1, n+1):
    for j in range(0, i+1):
        a += int(factorial(i) / (factorial(j) * factorial(i-j)))

print(a)
