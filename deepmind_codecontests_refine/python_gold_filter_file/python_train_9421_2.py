#! /usr/bin/python

n = int(input())
v = [0 for i in range(n)]
h = [0 for i in range(n)]

ans = []

for i in range(n ** 2):
    ch, cv = map(int, input().split())
    if v[cv - 1] == 0 and h[ch - 1] == 0:
        v[cv - 1] = 1
        h[ch - 1] = 1
        ans.append(i + 1)

print(' '.join(list(map(str, ans))))
