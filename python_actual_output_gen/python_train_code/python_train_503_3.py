n=int(input())
ans=0
for _ in range(n):
  a,b=map(int,input().split())
  if a==b:
    ans+=1
    if ans==3:
      break
  else:
    n=0
if ans==3:
  print("Yes")
else:
  print("No")