n,k=map(int,input().split())
A=list(map(int,input().split()))

l=0
r=max(A)+1
while r-l>1:
  m=(l+r)//2
  cut=0
  
  for i in range(n):
    cut+=((A[i]+m-1)//m)-1
  if cut>k:
    l=m
  else:
    r=m
print(r)
  