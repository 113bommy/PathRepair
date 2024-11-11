from sys import stdin,stdout
from math import gcd
input=stdin.readline
print=stdout.write
def gcda(l):
    if len(l)==0:
        return 1
    res=l[0]
    for i in range(1,len(l)):
        res=gcd(res,l[i])
    return res
t=int(input())
for i in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    lsort=l[:]
    lsort.sort()
    s=set()
    for i in range(n):
        if l[i]!=lsort[i]:
            s.add(l[i])
    if len(s)==0:
        print("YES")
    else:
        if gcda(list(s))==min(l):
            print("YES")
        else:
            print("NO")
    print("\n")


