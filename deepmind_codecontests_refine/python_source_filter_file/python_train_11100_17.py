import sys
n,k=map(int,input().split())
a=list(map(int,input().split()))
if k>n:
  print(n)
else:
  curr=0
  currpow=a[0]
  if currpow==n:
    print(n)
    sys.exit()
  for i in range(1,n):
    if a[i]>currpow:
      curr=0
      currpow=a[i]
      if currpow==n:
        print(n)
        sys.exit()
    else:
      curr+=1
      if curr>=k:
        print(currpow)
        sys.exit()