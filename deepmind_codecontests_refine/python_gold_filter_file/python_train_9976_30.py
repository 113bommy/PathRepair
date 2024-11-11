x=int(input())
ans=1
for i in range(2,int(x**0.5)+1):
    p=1
    while i*p<=x:
        p*=i
    ans=max(p,ans)
print(ans)