n=int(input())
a=list(map(int,input().split()))
flg = True
if n%2==0:
  if 0 in a or len(set(a))!=n//2:
    flg=False
else:
  if len([0 for i in a if a==0])!=1 or len(set(a))!=n//2+1:
    flg=False
if flg:
  print(2**(n//2)%(10**9+7))
else:
  print(0)

