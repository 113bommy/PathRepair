from math import *
def factors(n,l,r):
    for j in range(1,int(ceil(sqrt(n))+1)):
        if n%j==0:
            if j>=l and j<=r:
                return j
            elif n//j>=l and n//j<=r:
                return n//j
    return -1
for _ in range(int(input())):
    l,r,m=map(int,input().split())
    for i in range(l,r):
        x=(r-i)
        if m-x>0:
            a=factors(m-x,l,r)
            if a!=-1:
                print(a,r,i)
                break
        x=(i-r)
        if m-x>0:
            a=factors(m-x,l,r)
            if a!=-1:
                print(a,i,r)
                break