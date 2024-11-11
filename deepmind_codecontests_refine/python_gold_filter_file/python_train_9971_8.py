from math import *
from statistics import median
N=int(input())
A,B=[],[]
for i in range(N):
    a,b=map(int,input().split())
    A.append(a);B.append(b)
A.sort();B.sort()
if N%2:
    ans=median(B)-median(A)+1
else:
    ans=(median(B)-median(A))*2+1
print(int(ans))