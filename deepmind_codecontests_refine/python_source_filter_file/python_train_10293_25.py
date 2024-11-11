import math

n = int(input())
a = list(map(int, input().split()))

X = math.ceil(sum(a) / n)

P = 0

for i in range(n):
    P += (X - a[i])**2

print(P)