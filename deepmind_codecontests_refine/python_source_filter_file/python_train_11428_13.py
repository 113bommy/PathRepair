# -*- coding: utf-8 -*-

N,X,M=map(int,input().split())

A=[0]*M
A[0]=X
D=[0]*M

s=N
for i in range(1,N):
    a=A[i-1]**2%M
    if D[a] == 1:
        s=A.index(a)
        break
    else:
        A[i]=a
        D[a]=1

if s==N:
    ans=sum(A)
else:
    A=A[:i]
    
    ans=0
    l=len(A)-s
    ans+=sum(A[:s])
    S=sum(A[s:])
    T=(N-s)//l
    ans+=T*S
    K=N-s-l*T
    ans+=sum(A[s:(s+K)])


print(ans)
