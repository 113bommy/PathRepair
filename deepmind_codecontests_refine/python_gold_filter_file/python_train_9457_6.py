n=int(input())
l=sorted([int(input()) for i in range(n)])
if sum(l)%10!=0:
  print(sum(l))
else:
  ans=sum(l)
  for i in range(n):
    if l[i]%10!=0:
      ans-=l[i]
      print(ans)
      quit()
  print(0)