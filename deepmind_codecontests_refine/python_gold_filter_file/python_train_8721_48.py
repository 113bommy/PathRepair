N,M=map(int,input().split())
a=list(map(int,input().split()))
a=sorted(a, reverse=True)
if sum(a)/(4*M)<=a[M-1]:
  print("Yes")
else:
  print("No")