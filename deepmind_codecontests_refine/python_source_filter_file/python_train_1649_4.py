n=int(input())
l=[]
ans=0
for i in range(2):
l.append(list(map(int,input().split())))
for i in range(n):
  c=sum(l[0][:i+1])+sum(l[1][i:])
  if c>ans:ans=c
print(ans)