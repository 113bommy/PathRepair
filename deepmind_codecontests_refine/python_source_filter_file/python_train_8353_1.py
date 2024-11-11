# -*- coding: utf-8 -*-
"""
@author: Saurav Sihag
"""

rr = lambda: input().strip()
rri = lambda: int(rr())
# rri = lambda: int(stdin.readline())
rrm = lambda: [int(x) for x in rr().split()]
# stdout.write(str()+'\n')

from sys import stdin, stdout

def sol():
    n, k= rrm()
    s=input().strip()
    fr=[0 for i in range(26)]
    for c in s:
        fr[ord(c)-ord('a')]+=1
    res=1
    # print(fr)
    for i in range(2, k+1):
        if k%i==0:
            x=1
            while True:
                cn=x*i
                z=0
                for j in fr:
                    z+=j//x
                if z<i:
                    break
                x+=1
            x-=1
            res=max(res, x*i)
    print(res)
    return


# sol()
T = rri()
for t in range(1, T + 1):
    ans = sol()
    # print("Case #{}: {}".format(t, ans))

