n,m=map(int,input().split())
ans=list(range(m))
for i in range(n):
    l=list(map(int,input().split()))[1:]
    ans=list(set(ans)&set(l))
print(len(ans))