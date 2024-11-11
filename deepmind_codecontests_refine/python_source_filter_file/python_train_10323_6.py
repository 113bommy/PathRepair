#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7

n = int(input())
u = list(map(int, input().split()))
f = {}
ff = {}
ans = 1
for i in range(n):
    if len(ff) == 1:
        ans = i+1
    if u[i] in f: f[u[i]] += 1
    else: f[u[i]] = 1
    
    if f[u[i]]-1 in ff:
        if ff[f[u[i]]-1] == 1: del ff[f[u[i]]-1]
        else: ff[f[u[i]]-1] -= 1

    if f[u[i]] in ff: ff[f[u[i]]] += 1
    else: ff[f[u[i]]] = 1

    if len(ff) == 2:
        k1, k2 = sorted(ff.keys())
        if k2-k1 == 1:
            if ff[k2] == 1:
                ans = i+1
        elif k1 == 1:
            if ff[k1] == 1:
                ans = i+1
print(ans)