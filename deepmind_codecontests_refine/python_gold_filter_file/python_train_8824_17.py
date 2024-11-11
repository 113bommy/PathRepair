n=int(input())
ans=0
for i in range(1,n+1):
    d=n//i
    ans+=i*d*(d+1)//2
print(ans)