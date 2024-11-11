# coding: utf-8
def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b,a%b)
n, m = [int(i) for i in input().split()]
x = [0]*n
y = [0]*m
for i in input().split()[1:]:
    x[int(i)] = 1
for i in input().split()[1:]:
    y[int(i)] = 1
for i in range(n*m//gcd(n,m)*2):
    if x[i%n] == 1 or y[i%m] == 1:
        x[i%n] = 1
        y[i%m] = 1
if x.count(1)==n and y.count(1)==m:
    print('Yes')
else:
    print('No')
