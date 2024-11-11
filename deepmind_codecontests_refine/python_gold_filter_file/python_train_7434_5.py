n,d=map(int,input().split())
a=list(map(int,input().split()))
m=int(input())
a.sort()
s=0
if n==m:
  print(sum(a))
elif n>m:
  for i in range(m):
    s+=a[i]
  print(s)
else:
  z=(m-n)*d
  print(sum(a)-z)