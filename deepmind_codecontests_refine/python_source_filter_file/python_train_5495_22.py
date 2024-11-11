K,N=map(int,input().split())
A=[int(i) for i in input().split()]
ma=K-A[-1]+A[0]
for i in range(N-1):
    Z=A[i+1]-A[i]
    ans=max(ma,Z)
print(K-ans)