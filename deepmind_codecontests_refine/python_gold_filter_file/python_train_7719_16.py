n,m=map(int,input().split())
n2=n//2
if m in (0,1) or n-m==1:
  print(1)
elif  n-m==0:
  print(0)
elif n>=m*2:
  print(m)
elif n2<m:
  print(n%m)