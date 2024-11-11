n,m=map(int,input().split())
d={}
ans=cnt=0
for i in map(int,input().split()):
    d[i]=d.get(i,0)+1
for i in range(1,m+1):
    cnt=0
    for v in d.items():
        cnt+=v[1]//i
    if cnt>=n: ans=i
print(ans)