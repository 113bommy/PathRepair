n=int(input())
ans=0
for i in range(1,n+1):
    w=n//i
    ans+=i*w*(w+1)//2
print(ans)