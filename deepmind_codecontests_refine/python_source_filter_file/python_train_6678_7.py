import math
import bisect

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = egcd(b % a, a)
        return (g, y - (b // a) * x, x)



def mulinv(b, n):
    g, x, _ = egcd(b, n)
    if g == 1:
        return x % n


primes = []

def isprime(n):
    for d in range(2, int(math.sqrt(n))+1):
        if n%d==0:
            return False
    return True


def argsort(ls):
    return sorted(range(len(ls)), key=ls.__getitem__)

def f(p=0):
    if p==1:
        return map(int, input().split())
    elif p==2:
        return list(map(int, input().split()))
    else:
        return int(input())



n = f()
dl = [0]*(2*10**5+1)
pl = [list() for _ in range(2*10**5+1)]
cl = f(2)


for i in range(n):
    dl[cl[i]]+=1
    if i==n-1 or  cl[i] != cl[i + 1]:
        pl[cl[i]].append(i)
    if i ==0 or cl[i] != cl[i - 1]:
        pl[cl[i]].append(i)




mx = max(dl)
pos = dl.index(mx)

start = pl[pos][1]
print(n-mx)
ln = len(pl[pos])
for j in range(2, ln):
    x = pl[pos][j]
    for i in range(start+1, x):
        if cl[i]>pos:
            print(2, i+1, i)
        else:
            print(1, i+1, i)
    if j+1<ln:
        start = pl[pos][j+1]

if cl[-1]!=pos:
    for i in range(pl[pos][-1]+1, n):
        if cl[i] > pos:
            print(2, i+1, i)
        else:
            print(1, i+1, i)

if cl[0]!=pos:
    for i in range(pl[pos][0], 0, -1):
        if cl[i-1] > pos:
            print(2, i, i+1)
        else:
            print(1, i, i+1)