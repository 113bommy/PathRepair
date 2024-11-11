for _ in range(int(input())):
  n=int(input())
  s=n*(n+1)/2
  d=1
  while d<=n:
    d*=2
    s-=d
  print(int(s))