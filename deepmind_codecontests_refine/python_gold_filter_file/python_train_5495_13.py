K,N=map(int,input().split())
A=list(map(int,input().split()))

A.append(K+A[0])
l=0
for i in range(N):
    l=max(l,A[i+1]-A[i])

print(K-l)