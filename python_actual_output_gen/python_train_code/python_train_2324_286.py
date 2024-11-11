n=int(input())
x=2
ans=0
for i in range(1,n+1):
    x*=i
    ans+=x
print(ans)