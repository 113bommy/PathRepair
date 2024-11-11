n,m=map(int,input().split())
A=list(map(int,input().split()))
s=0
A.sort()
for i in range(n):
    if A[i]>=0:
        break
    s+=A[i]
print(-s)