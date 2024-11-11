n,m=list(map(int,input().split()))

i=1
ans=0

while i*i<=m:
    if m%i==0:
        if n<=m/i:
            ans=max(ans,i)
        if n<=i:
            ans=max(ans,m/i)
        
    i+=1

print(ans)
