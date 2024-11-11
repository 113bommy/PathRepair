mod=10**9+7
N=int(input())
M=1
y=[1 for k in range(N)]
for k in range(2,N+1):
    for j in range(2,k+1):
        if k==1:
            break
        if k%j ==0:
            count=0
            while k%j==0:
                k=k//j
                count+=1
            y[j-1]+=count
ans=1
for k in range(len(y)):
    ans=ans*y[k]%mod
print(ans)