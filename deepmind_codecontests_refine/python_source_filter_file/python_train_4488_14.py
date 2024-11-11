# import os

n,k  = map(int,input().split())

s= input()

letter = []
r = []

for l in s:
    if l not in letter:
        letter.append(l)
        r.append(s.count(l))
if len(r) == 4:
    print(min(r)*k)
else:
    print(0)
