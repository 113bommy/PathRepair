from math import factorial
import bisect
def cmb(n,r):
  if n<0 or r<0:
    return 0
  else:
    return factorial(n)//factorial(n-r)//factorial(r)
n,a,b=map(int,input().split())
x = list(map(int,input().split()))
ans=0
x.sort(reverse=True)
print(sum(x[:a])/a)
if n==a:
  print(1)
elif x[0]==x[a]:
  for i in range(n):
    if x[0] != x[i]:
      k=i
      break
  else:
    k=n
  for i in range(a,b+1):
    ans+=cmb(k,i)
  print(ans)
elif x[a-1] == x[a]:
  y=sorted(x)
  x1=bisect.bisect_left(y,x[a])
  x2=bisect.bisect_right(y,x[a])
  print(cmb(x2-x1,a-(n-x2)))
else:
  print(1)