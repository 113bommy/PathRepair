n,c,k=map(int,input().split())
t=[0]*n
for i in range(n):
  t[i]=int(input())
t.sort()
ans=1
temp=t[0]
tempc=1
for i in range(1,n):
  if temp+k>=t[i] or tempc>c:
    ans=ans+1
    temp=t[i]
    tempc=1
  else:
    tempc=tempc+1
print(ans)