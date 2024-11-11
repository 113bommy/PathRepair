n=int(input())
ans=0
for i in range(1,n+1):
    A=n//i
    ans+=(A*(A+1)//2+i)
print(ans)