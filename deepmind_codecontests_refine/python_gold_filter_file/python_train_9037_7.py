n=int(input());ans=0
l=[int(input()) for i in range(n)]
if l[0]!=0:
  print(-1);exit()
for i in range(n-1):
  if l[i+1]>l[i]+1:
    print(-1);exit()
for i in range(1,n):
  if l[i]==l[i-1]+1:
    ans+=1
  else:
    ans+=l[i]
print(ans)