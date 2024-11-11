#!/usr/bin/python3 -SOO
n = int(input())
a = []
b = []
c = []
l = [[1]*(n//2)+[0]*(n-(n//2)) for _ in range(2)]
for i in range(n):
    x,y = map(int,input().strip().split())
    a.append(x)
    b.append(y)
    c+=[(x,i,0),(y,i,1)]
c.sort()
for i,xs in enumerate(c):
    x,y,z = xs
    if y >= n//2 and i <= n:
        l[z][y] = 1
for xs in l:
    print(''.join(map(str,xs)))
