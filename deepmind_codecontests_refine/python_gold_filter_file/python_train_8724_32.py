n,m=map(int,input().split())
ans=list(range(1,m+1))
for i in range(n):
    l=list(map(int,input().split()))[1:]
    ans=list(set(ans)&set(l))
print(len(ans))