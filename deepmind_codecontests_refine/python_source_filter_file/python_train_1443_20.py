n = int(input())
l = list(map(int,input().split()))
s = 1
if n%2!=0:
  if l.count(0)!=1:
    s =0
  else:
    l.remove(0)
    if len(set(l))==(n-1)//2:
      s = 2*(n-1)//2
    else:
      s =0
else:
    if len(set(l))==n//2:
      s = 2*(n//2)
    else:
      s = 0
print(int(s)%(10**9+7))
      
    