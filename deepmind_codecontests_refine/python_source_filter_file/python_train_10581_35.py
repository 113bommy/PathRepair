n,m=map(int,input().split())
ans=1000000
for i in range(n):
    a,b=map(int,input().split())
    if (a/b)<ans: ans=a/b
print(ans)