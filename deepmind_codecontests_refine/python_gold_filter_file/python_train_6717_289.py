n=int(input())
ans=0
for i in range(1,n+1):
    x=2**i
    ans+=x
print(ans)