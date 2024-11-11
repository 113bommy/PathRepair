n=int(input());ans=n
for i in range(n):
    l,r=map(int,input().split())
    ans+=r-l
print(ans)