import sys
import math
import collections
import bisect
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
for t in range(1):
    bread=list(input())
    nb,ns,nc=get_ints()
    pb,ps,pc=get_ints()
    given=int(input())
    cb,cs,cc=bread.count("B"),bread.count("S"),bread.count("C")
    l=0
    r=10**9
    c=0
    while l<=r:
        mid=(l+r)//2
        cost=(max(0,mid*(cb)-nb)*pb + max(0,mid*(cs)-ns)*ps +max(0,mid*(cc)-nc)*pc)
        if cost<=given:
            l=mid
        else:
            r=mid
        c+=1
        if c>=100:
            break
    print(l)