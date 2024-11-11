x=int(input())
ans=0
for p in range(2,10):
    b=int(x**(1/p))
    while b**p>x:
        b -= 1
    ans=max(ans,b**p)
print(ans)