q=int(input())
for _ in range(q):
  n=int(input())
  if n<4:
    print(-1)
    continue
  if n in [5,7,11]:
    print(-1)
    continue
  if n%2==0:
    ans=0
    if n%4!=0:
      n-=6
      ans+=1
    ans+=n//4
    print(ans)
  else:
    ans=1
    n-=9
    ans+=n//4
    print(ans)