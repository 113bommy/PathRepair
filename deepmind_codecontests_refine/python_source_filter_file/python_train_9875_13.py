from operator import itemgetter
import sys
N=int(input())
A=[int(i) for i in input().split()]
B=[(A[i],i) for i in range(N)]
B=sorted(B,key=itemgetter(1))
B=sorted(B,key=itemgetter(0))
T=[0]*N
cos,pt=B.pop()
for i in range(1,N):
    cos2,pt2=B.pop()
    T[pt]+=(cos-cos2)*i
    pt=min(pt,pt2)
    cos=cos2
T[pt]=cos*N
for i in T:
    print(i)
