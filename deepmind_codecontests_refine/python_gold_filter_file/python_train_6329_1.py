# coding: utf-8
# Your code here!
N,K=map(int,input().split())

A=list(map(int,input().split()))

A=A+A

count=[0]*2*N

for i in range(N):
    for j in range(i,2*N):
        if A[i]>A[j]:
            count[j]+=1
a=(sum(count[0:N]))
b=(sum(count[N:2*N]))
c=(int((a*K+b*K*(K-1)//2)))
print(c%(10**9+7))
