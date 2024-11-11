K,N=map(int,input().split())
A=list(map(int,input().split()))
A.sort()
dist=[A[0]+K-A[-1]]+[A[i]-A[i-1] for i in range(1,N)]
print(k-max(dist))