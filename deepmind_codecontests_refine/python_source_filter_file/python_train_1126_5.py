# -*- coding: utf-8 -*-

line = input().split(" ")
n = int(line[0])
c = int(line[1])

sushi = []
for _ in range(n):
    line = input().split(" ")
    sushi.append([int(line[0]), int(line[1])]) #[x,v]

r = []
state = 0
rmax = -9999999999
for i in range(n):
    s = sushi[i]
    state += s[1]

    if state-s[0]>rmax:
        rmax = state-s[0]
    r.append(rmax)

state = 0
ret1 = r[-1]
for i in range(n-1,0,-1):
    s = sushi[i]
    state += s[1]

    s = state-2*(c-s[0]) + r[i-1]
    if s>ret1:
        ret1 = s




l = [0 for _ in range(n)]
state = 0
lmax = -9999999999999
for i in range(n-1,-1,-1):
    s = sushi[i]
    state += s[1]

    if state-(c-s[0])>lmax:
        lmax = state-(c-s[0])
    l[i] = lmax

state = 0
ret2 = l[-1]
for i in range(n-1):
    s = sushi[i]
    state += s[1]

    s = state-2*s[0] + l[i+1]
    if s>ret2:
        ret2 = s

print(max(ret1,ret2,0))
