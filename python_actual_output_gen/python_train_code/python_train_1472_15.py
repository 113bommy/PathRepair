n=int(input())

if n%2!=0:
  print(0)
else:
  ans,div=0,10
  while div<n:
    ans+=n//div
    div*=5
  print(ans)