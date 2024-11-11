n= int(input())

ans=0
for i in range(1,n+1):
    x=n//i
    ans+=i*(x*(x+1)//2)
print(ans)