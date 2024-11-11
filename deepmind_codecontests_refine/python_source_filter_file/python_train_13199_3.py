n=int(input())
i=1
ans=10**13
while(i*i<=n):
    if(n%i==0):
        ans=min(ans,n/i+i-2)
    i+=1
print(ans)