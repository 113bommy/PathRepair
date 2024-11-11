import sys
input = sys.stdin.readline

n,p,k=map(int,input().split())
A=list(map(int,input().split()))

B=[(a**4-k*a)%p for a in A]

from collections import Counter
C=Counter(B)


print(sum([l-1 for l in list(C.values())]))
