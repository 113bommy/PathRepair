n=int(input())
ans=0
for i in range(1,n+1):
    y=n//i
    ans+=i*(y*(y+1)//2)
print(ans)