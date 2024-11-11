K,N=map(int,input().split())
A=list(map(int,input().split()))
A.append(A[0]+K)
l=0
for i in range(N-1):
    l=max(l,A[i+1]-A[i])
 
print(K-l)