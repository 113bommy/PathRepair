n,m=map(int,input().split())

if n%2 == 1:
  for i in range(1,m+1):
    a,b=i,m-i
    print(a,b)
else:
  for i in range(1,m+1):
    a,b = i,m-i
    if b-a <= n//2:
      a+=1
    print(a,b)
  