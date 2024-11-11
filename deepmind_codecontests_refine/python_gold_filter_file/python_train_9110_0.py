n,m,s,d=map(int,input().split())
x=list(map(int,input().split()))+[m+s+1]
x.sort()
cur=l=0
ans=[]
while l<m:
  r=min(x[cur]-1,m)
  ans.append(("RUN",r-l))
  if r==m:
    break
  if r-l<s:
    print("IMPOSSIBLE")
    exit()
  t=x[cur]+1
  while x[cur+1]-1-t<s:
    cur+=1
    t=x[cur]+1
  if t-r>d:
    print("IMPOSSIBLE")
    exit()
  ans.append(("JUMP",t-r))
  l=t
  cur+=1
for aa in ans:
  print(*aa)