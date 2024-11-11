x,k,d=map(int,input().split())
x=abs(x)
if x>k*d:
  ans=x-k*d
else:
  n=x//d
  if n%2==0:
    ans=x-n*d
  else:
    ans=abs(x-(n+1)*d)
print(ans)