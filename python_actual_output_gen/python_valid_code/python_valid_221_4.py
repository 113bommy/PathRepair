X,L=map(int,input().split())
N=input().split()
d=0
ans=0
for i in N:
  d=d+int(i)
  if d<=L:
    ans+=1
print(ans)