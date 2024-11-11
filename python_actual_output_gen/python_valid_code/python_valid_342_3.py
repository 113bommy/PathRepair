n,C,T=map(int,input().split())
t=[int(input()) for i in range(n)]
t.sort()
res=t[0]+T
cnt=1
ans=0
for i in range(n):
  if t[i]<=res and cnt<C:
    cnt+=1
  elif t[i]>res or cnt==C:
    ans+=1
    res=t[i]+T
    cnt=1
print(ans+1)