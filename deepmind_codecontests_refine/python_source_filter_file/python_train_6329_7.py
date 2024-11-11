n,k=map(int,input().split())
A=list(map(int,input().split()))
ans=0
mod=10**9+7
for i in range(n):
    a=0
    b=0
    for j in range(min(i+1,n-1),n):
        if A[i]>A[j]:
            b+=1
    for j in range(i):
        if A[i]>A[j]:
            a+=1
    ans+=(b*k+(a+b)*k*(k-1)//2)%mod
print(ans)