#!/usr/bin/env python3
m,n = [int(ii) for ii in input().split(' ')]
f = [int(ii)-1 for ii in input().split(' ')]
b = [int(ii)-1 for ii in input().split(' ')]

mp = dict([])
for i in range(n):
    if f[i] in mp:
        mp[f[i]].append(i)
    else:
        mp[f[i]] = [i]

res = "Possible"
for i in range(m):
    if b[i] in mp:
        if len(mp[b[i]])>1:
            res = "Ambiguity"
    else:
        res = "Impossible"
        break

print(res)
if res=="Possible":
    print (' '.join(str(mp[b[i]][0]+1) for i in range(m)))
