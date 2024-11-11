s=int(input())
t=[]
for i in range(s):
    u,l=map(int,input().split())
    t.append((u-l,u+l-1))
t.sort(key=lambda x: x[1])
d=-10**10
ans=0
for i in range(s):
  if d<t[i][0]:
    ans+=1
    d=t[i][1]
print(ans)