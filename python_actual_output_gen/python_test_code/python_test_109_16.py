n,*a=map(int,open(0).read().split())
a.sort()
ans=1
for i in a:
    ans*=i
    if ans>=1e18:
        print(-1)
        exit()
print(ans)