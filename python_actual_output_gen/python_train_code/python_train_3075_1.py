N,K=map(int,input().split())
ans=0
for i in range(1,N+1):
    p=i
    c=0
    while p<=K:
        p*=2
        c+=1
    ans+=1/2**c
print(ans/N)