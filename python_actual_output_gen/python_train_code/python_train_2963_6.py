# coding=utf-8
n, k = list(map(int, input().split()))
s = input()
e = list(set(s))
e.sort()
en = {}
for i in range(len(e)-1):
    en[e[i]] = e[i+1]
ns = []
for i in range(min(n, k)):
    ns.append(s[i])
if k-n:
    for i in range(k-n):
        ns.append(e[0])
else:
    while True:
        if ns[k-1] != e[-1]:
            ns[k-1] = en[ns[k-1]]
            break
        else:
            ns[k-1] = e[0]
            k -= 1
print(''.join(ns))
