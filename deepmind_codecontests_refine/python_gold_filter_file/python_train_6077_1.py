n=int(input())
a=list(map(int, input().split(" ")))
if(a==[1]*n):
  print(1)
else:
 primes=[True for i in range(401)]
 primes[0]=False
 primes[1]=False
 for k in range(1, 401):
  if(primes[k]==True):
    for pro in range(k*k, 401, k):
      primes[pro]=False
  mine=[]
 for k in range(401):
  if(primes[k]):
    mine.append(k)
 d=[0 for i in range(100001)]
 dp=[0 for i in range(n)]
 for k in range(n):
  al=a[k]
  for prime in mine:
    if(al%prime==0):
      dp[k]=max(d[prime]+1, dp[k])
    while(al%prime==0):
      al//=prime
  for prime in mine:
    if(a[k]%prime==0):
      d[prime]=max(d[prime], dp[k])
  if(al!=1):
    dp[k]=max(d[al]+1, dp[k])
    d[al]=dp[k]
 print(max(dp))