n,m=map(int, input().split())
p=[0]*(n+1)
seen=p.copy()
l=list(map(int,input().split()))
cnt=0
for i in range(m-1):
    d=(l[i+1]-l[i]+n)%n
    d= d if d!=0 else n
    if seen[d]==1 and l[i]!=d:
        print(-1)
        quit()
    cnt+=1 if seen[d]==0 else 0
    p[l[i]]=d
    seen[d]=1
i,j=1,1
while i<n:
    if p[i]!=0:
        i+=1
        continue
    while j<n and seen[j]==1 :
        j+=1
    p[i]=j
    seen[j]=1
    cnt+=1
    i+=1
ans = [str(p[i]) for i in range(1,n+1)]
print(' '.join(ans)if cnt==n else -1)
