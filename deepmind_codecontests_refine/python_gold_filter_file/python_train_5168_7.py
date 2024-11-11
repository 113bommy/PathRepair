n=int(input())
m=list(map(int,input().split()))
a=min(m)
i=m.index(a)
ans=n
for x in range(m.index(a)+1,n):
    if m[x]==a:
        ans=min(ans,x-i)
        i=x
print(ans)