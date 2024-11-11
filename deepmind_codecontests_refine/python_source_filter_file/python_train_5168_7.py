n=int(input())
m=list(map(int,input().split()))
a=min(m)
i=m.index(a)
ans=0
for x in range(m.index(a),n):
    if m[x]==a:
        ans=max(ans,x-i)
        i=x
print(ans)