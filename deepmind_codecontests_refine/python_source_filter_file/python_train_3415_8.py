n,l=map(int,input().split())
 a=n*(2*l+n-1)//2
if 1-n<=l<=0:
  print(a)
elif l<=-n:
  print(a-l-n+1)
else :
  print(a-l)
  