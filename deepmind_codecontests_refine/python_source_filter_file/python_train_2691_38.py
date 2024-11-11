from math import ceil
n,a,b = map(int,input().split())
h = [int(input()) for _ in range(n)]
l = 0
r = 10**18

def f(x):
    res = 0
    for i in range(n): res += ceil(max(0,(h[i]-b*x))/(a-b))
    return res <= x

while l+1 < r:
    m = (l+r)//2
    if f(m): r = m
    else: l = m
print(r)