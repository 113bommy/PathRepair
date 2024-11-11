n=int(input())
a=[int(i) for i in input().split()]
ans=0
for i in range(64):
    x,y=0,0
    for j in a:
        if j>>i&1:
            y+=1
        else:
            x+=1
    ans+=x*y*(1<<i)
    ans%=10**9+7
print(ans)
