n=int(input())
ans=0
for i in range(1,n+1):
    m=n//i
    ans+=m*(m+1)//2*i
print(ans)