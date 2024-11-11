# -*- coding: utf-8 -*-
"""
Created on Sat Dec 14 17:00:02 2019

@author: Saurav Sihag
"""

rr = lambda: input().strip()
rri = lambda: int(rr())
rrm = lambda: [int(x) for x in rr().split()]

def sol():
    s=input()
    n=len(s)
    if n<3:
        print(0)
        print()
        return 0
    if n>4:
        res=0
        ind=[]
        i=0
        while i < n-4:
            if s[i]+s[i+1]+s[i+2]=="two":
                res += 1
                if s[i+3]+s[i+4]=="ne":
                    ind.append(str(i+2+1))
                    i+=5
                else:
                    ind.append(str(i+1+1))
                    i+=3
            elif s[i]+s[i+1]+s[i+2]=="one":
                res+=1
                ind.append(str(i+1+1))
                i+=3
            else:
                i+=1
        while i<n-2:
            if s[i]+s[i+1]+s[i+2]=="one" or s[i]+s[i+1]+s[i+2]=="two":
                res+=1
                ind.append(str(i+1+1))
                i+=3
            else:
                i+=1
        print(res)
        if res>0:
            inds=" ".join(ind)
            print(inds)
        else:
            print()
        return 0
    i=0
    res=0
    ind=[]
    while i < n - 2:
        if s[i] + s[i + 1] + s[i + 2] == "one" or s[i] + s[i + 1] + s[i + 2] == "two":
            res += 1
            ind.append(str(i + 1+1))
            i += 3
        else:
            i += 1
    print(res)
    if res > 0:
        inds = " ".join(ind)
        print(inds)
    else:
        print()
    return 0


T = rri()
for _ in range(T):
    #n = rri()
    ans = sol()
    #print(ans)
