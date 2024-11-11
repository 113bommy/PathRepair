n=int(input())
a=[int(input()) for i in range(n)]
a0=0
ans=0
for ai in a[::-1]:
  
  if ai>a0-1:
    ans+=ai
  elif ai<a0-1:
    print(-1)
    exit()
  a0=ai
  
if a0 !=0:
  print(-1)
else:
  print(ans)
  