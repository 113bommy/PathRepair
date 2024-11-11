t=int(input())
for rr in range(t):
  n=int(input())
  sum=n*(n+1)//2
  p=1
  while(p<=n):
    sum -=2*p
    p=p*2

  print(int(sum))