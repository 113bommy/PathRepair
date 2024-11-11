n,m=map(int,input().split())
ab=[list(map(int,input().split())) for _ in range(m)]
l.sort(key=lambda x:x[1])
lb=0
ans=0
for a,b in l:
    if a>=lb:
        lb=b
        ans+=1
print(ans)