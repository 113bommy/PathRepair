n,m=map(int,input().split())
ba=[0]*n
ga=[0]*m
b=list(map(int,input().split()))
g=list(map(int,input().split()))
for i in range(1,b[0]+1):
    ba[b[i]]=1
for i in range(1,g[0]+1):
    ga[g[i]]=1
for i in range(2*(n+m)):
    if ba[i%n]==1 or ga[i%m]==1:
        ga[i%m],ba[i%n]=1,1
if(ba.count(1)+ga.count(1)==n+m):
    print("YES")
else:
    print("NO")

