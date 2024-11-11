n=int(input())
ans=0
for i in range(1,n+1):
    a=n//i
    ans+=i*a*(a+1)//2
print(ans)