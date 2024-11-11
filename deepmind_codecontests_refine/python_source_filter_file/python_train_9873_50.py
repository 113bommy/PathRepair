n,a,b=map(int,input().split())
ans=0
for i in range(n):
    if a<=sum(map(int,str(i)))<=b: ans+=i
print(ans)