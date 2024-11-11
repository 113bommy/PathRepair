v=["a","e","i","o","u"]
n=int(input().strip())
a=list(map(int,input().strip().split()))
l=[0 for i in range(n)]
for i in range(n):
  for s in input().strip().split():
    l[i]+=(sum([s.count(x) for x in v]))
if l==a:
  print("YES")
else:
  print("NO")