from sys import stdin
from math import gcd
n=int(stdin.readline())
a=[int(x) for x in stdin.readline().split()]
c = []
ld=[]
rd=[]


def check(l, r, e):
    if r == l: return c[l][e] > 0
    if e < l and ld[l][r-l] != 0:
        return ld[l][r-l] == 1
    elif e > r and rd[l][r-l] != 0:
        return rd[l][r-l] == 1
    for i in range(l,r+1):
        if c[i][e]>0:
            if i==l or check(l, i-1, i):
                if i==r or check(i+1, r, i):
                    if e < l:
                        ld[l][r-l] = 1
                    else:
                        rd[l][r-l] = 1
                    return True
    if e < l:
        ld[l][r - l] = -1
    else:
        rd[l][r - l] = -1
    return True


for i in range(n):
    c.append([0]*n)
    ld.append([0]*n)
    rd.append([0] * n)
for i in range(n):
    for j in range(i+1,n):
        if gcd(a[i],a[j]) > 1:
            c[i][j] = c[j][i] = 1
ans=False
for i in range(n):
    if i == 0 or check(0, i - 1, i):
        if i == n-1 or check(i + 1, n-1, i):
            ans = True
            break
if ans:
    print("Yes")
else:
    print("No")


